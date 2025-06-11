#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>
#include <linux/gpio/consumer.h>
#include <linux/delay.h>

static int slm310_probe(struct platform_device *pdev)
{
    struct gpio_desc *pwrkey_gpio = devm_gpiod_get(&pdev->dev, "power", GPIOD_OUT_LOW);
    struct gpio_desc *reset_gpio = devm_gpiod_get(&pdev->dev, "reset", GPIOD_OUT_LOW);

    if (IS_ERR(pwrkey_gpio) || IS_ERR(reset_gpio))
        return -ENODEV;

    msleep(100);
    gpiod_set_value(pwrkey_gpio, 0);
    msleep(2000);
    gpiod_set_value(pwrkey_gpio, 1);

    return 0;
}

static const struct of_device_id slm310_of_match[] = {
    { .compatible = "meig,slm310" },
    {},
};
MODULE_DEVICE_TABLE(of, slm310_of_match);

static struct platform_driver slm310_driver = {
    .driver = {
        .name = "slm310",
        .of_match_table = slm310_of_match,
    },
    .probe = slm310_probe,
};
module_platform_driver(slm310_driver);

MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("SLM310 Power-on GPIO Driver");
MODULE_LICENSE("GPL");