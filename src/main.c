#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#define SLEEP_TIME_MS 50


// Define o LED usando Device Tree
#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)

// Verifica se o LED está definido no Device Tree
#if DT_NODE_HAS_STATUS(LED0_NODE, okay)
static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
#else
#error "Unsupported board: led0 devicetree alias is not defined"
#endif

#if DT_NODE_HAS_STATUS(LED1_NODE, okay)
static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
#else
#error "Unsupported board: led1 devicetree alias is not defined"
#endif

int main(void)
{
    int ret,ret2, i=0;

    // Verifica se o device está pronto
    if (!gpio_is_ready_dt(&led)) {
        printk("Error: LED device %s is not ready\n", led.port->name);
        return;
    }
	// Verifica se o device está pronto
    if (!gpio_is_ready_dt(&led1)) {
        printk("Error: LED device %s is not ready\n", led1.port->name);
        return;
    }

    // Configura o pino como saída
    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE);
    if (ret < 0) {
        printk("Error %d: failed to configure LED pin\n", ret);
        return;
    }

    printk("LED blinking on %s pin %d\n", led.port->name, led.pin);
	
	// Configura o pino como saída
    ret2 = gpio_pin_configure_dt(&led1, GPIO_OUTPUT_INACTIVE);
    if (ret2 < 0) {
        printk("Error %d: failed to configure LED pin\n", ret2);
        return;
    }

    printk("LED blinking on %s pin %d\n", led.port->name, led.pin);
	printk("LED blinking on %s pin %d\n", led1.port->name, led1.pin);
    while (1) {
        //pisca o led azul à cada 500ms, pisca o led azul à cada segundo
		// Toggle do LED usando a nova API
		/*
        gpio_pin_toggle_dt(&led);
        k_msleep(100);
		gpio_pin_toggle_dt(&led);
		k_msleep(500);
		gpio_pin_toggle_dt(&led);
		gpio_pin_toggle_dt(&led1);
		k_msleep(100);
		gpio_pin_toggle_dt(&led);
		gpio_pin_toggle_dt(&led1);
		k_msleep(SLEEP_TIME_MS);
		*/
		
		//criando um que pisca o led verde à cada 350 ms e o azul à cada 1000 ms

		k_msleep(SLEEP_TIME_MS);
		gpio_pin_set_dt(&led,0); // desliga ambos os pinos dos leds
		gpio_pin_set_dt(&led1,0);
		i++;
		if(i%7==0)
		{
		gpio_pin_toggle_dt(&led);
		// teste do led
		//printk("LED verde ligado em %d ", 50*i);
		}
		if(i%20 == 0)
		{
		gpio_pin_toggle_dt(&led1);
		// teste do led
		//printk("LED azul ligado em %d", 50*i);
		}
		if(i==140)
		{
			i=0;
		}
		// teste do led
		//printk("\n");
    }
}