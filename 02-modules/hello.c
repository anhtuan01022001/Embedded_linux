#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("tusn");
MODULE_DESCRIPTION("A Hello LKM");

static int __init my_module_init(void) {
    printk(KERN_INFO "Hello from kernel module!\n");
    return 0;
}

static void __exit my_module_exit(void) {
    printk(KERN_INFO "Goodbye from kernel module!\n");
}

module_init(my_module_init);//insmod=insertmodule
module_exit(my_module_exit);//rmmod=removemodule
