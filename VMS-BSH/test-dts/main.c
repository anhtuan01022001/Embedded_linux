#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/version.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/err.h>
#include <linux/slab.h>

#define BUFFER_SIZE 256

static char buff[BUFFER_SIZE] = {0};

static int vchar_driver_open(struct inode *inode, struct file *file);
static ssize_t vchar_driver_read(struct file* fp, char __user *buffer, size_t cnt, loff_t *offset);
static ssize_t vchar_driver_write(struct file* fp, const char __user *buffer, size_t cnt, loff_t *offset);
static int vchar_driver_close(struct inode *inode, struct file *file);
static int __init vchar_driver_init(void);
static void __exit vchar_driver_exit(void);

struct _vchar_driver {
    dev_t dev_num;
    struct class* dev_cls;
    struct device* dev;
    struct cdev cdevice;
} vchar_drv;

static struct file_operations vchar_drv_fops = {
    .owner   = THIS_MODULE,
    .open    = vchar_driver_open,
    .release = vchar_driver_close,
    .read    = vchar_driver_read,
    .write   = vchar_driver_write
};

static int vchar_driver_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device opened!\n");
    return 0;
}

static ssize_t vchar_driver_read(struct file* fp, char __user *buffer, size_t cnt, loff_t *offset)
{
    size_t buff_len = strlen(buff) + 1;
    size_t to_read = min(cnt, (size_t)(buff_len - *offset));

    if (*offset >= buff_len)
        return 0;

    if (copy_to_user(buffer, buff + *offset, to_read)) {
        pr_err("Failed to send %zu chars to the user!\n", to_read);
        return -EFAULT;
    }

    *offset += to_read;
    return to_read;
}

static ssize_t vchar_driver_write(struct file* fp, const char __user *buffer, size_t cnt, loff_t *offset)
{
    if (*offset >= BUFFER_SIZE)
        return -ENOMEM;

    if (cnt > BUFFER_SIZE - *offset - 1)
        cnt = BUFFER_SIZE - *offset - 1;

    if (!cnt)
        return -ENOMEM;

    if (copy_from_user(buff + *offset, buffer, cnt)) {
        pr_info("Failed to receive %zu chars from the user\n", cnt);
        return -EFAULT;
    }

    buff[*offset + cnt] = '\0';
    *offset += cnt;

    pr_info("Received %zu chars from user: %s\n", cnt, buff);
    return cnt;
}

static int vchar_driver_close(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device closed!\n");
    return 0;
}

static int __init vchar_driver_init(void)
{
    int ret;

    // 1. Allocate device number
    ret = alloc_chrdev_region(&vchar_drv.dev_num, 0, 1, "vchar_dev");
    if (ret < 0) {
        printk(KERN_ERR "Failed to allocate device number\n");
        return ret;
    }

    // 2. Initialize cdev and add to kernel
    cdev_init(&vchar_drv.cdevice, &vchar_drv_fops);
    vchar_drv.cdevice.owner = THIS_MODULE;

    ret = cdev_add(&vchar_drv.cdevice, vchar_drv.dev_num, 1);
    if (ret < 0) {
        printk(KERN_ERR "Failed to add cdev\n");
        unregister_chrdev_region(vchar_drv.dev_num, 1);
        return ret;
    }

    // 3. Create class
    vchar_drv.dev_cls = class_create(THIS_MODULE, "class_vchar_device");
    if (IS_ERR(vchar_drv.dev_cls)) {
        printk(KERN_ERR "Failed to create device class\n");
        cdev_del(&vchar_drv.cdevice);
        unregister_chrdev_region(vchar_drv.dev_num, 1);
        return PTR_ERR(vchar_drv.dev_cls);
    }

    // 4. Create device
    vchar_drv.dev = device_create(vchar_drv.dev_cls, NULL, vchar_drv.dev_num, NULL, "vchar_dev");
    if (IS_ERR(vchar_drv.dev)) {
        printk(KERN_ERR "Failed to create device\n");
        class_destroy(vchar_drv.dev_cls);
        cdev_del(&vchar_drv.cdevice);
        unregister_chrdev_region(vchar_drv.dev_num, 1);
        return PTR_ERR(vchar_drv.dev);
    }

    printk(KERN_INFO "vchar driver initialized successfully\n");
    return 0;
}

static void __exit vchar_driver_exit(void)
{
    device_destroy(vchar_drv.dev_cls, vchar_drv.dev_num);
    class_destroy(vchar_drv.dev_cls);
    cdev_del(&vchar_drv.cdevice);
    unregister_chrdev_region(vchar_drv.dev_num, 1);
    printk(KERN_INFO "vchar driver exited\n");
}

module_init(vchar_driver_init);
module_exit(vchar_driver_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("NDT");
MODULE_DESCRIPTION("A simple Linux vchar driver");
MODULE_VERSION("0.1");
