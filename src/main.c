#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#define SLEEP_TIME_MS 50
#define STACK_SIZE 1024
#define PRIORITY 0


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
static const struct gpio_dt_spec led_1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
#else
#error "Unsupported board: led0 devicetree alias is not defined"
#endif

void liga_led_verde(void *arg1, void *arg2,void *arg3){
	while(1){
	printk("thread liga_led_verde rodando!\n");
	gpio_pin_toggle_dt(&led);
	k_msleep(950);
	}
}

void liga_led_azul(void *arg1, void *arg2,void *arg3){
	while(1){
	printk("thread liga_led_azul rodando!\n");
	gpio_pin_toggle_dt(&led_1);
    k_msleep(350);}
}

K_THREAD_DEFINE(thread_led_verde,STACK_SIZE,liga_led_verde,NULL,NULL,NULL,PRIORITY,0,0);
K_THREAD_DEFINE(thread_led_azul,STACK_SIZE,liga_led_azul,NULL,NULL,NULL,PRIORITY,0,0);

void main(void)
{
int ret,ret2;

    // Verifica se o device está pronto
    if (!gpio_is_ready_dt(&led)) {
        printk("Error: LED device %s is not ready\n", led.port->name);
        return;
    }
	// Verifica se o device está pronto
    if (!gpio_is_ready_dt(&led_1)) {
        printk("Error: LED device %s is not ready\n", led_1.port->name);
        return;
    }

    // Configura o pino como saída
    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE);
    if (ret < 0) {
        printk("Error %d: failed to configure LED pin\n", ret);
        return;
    }
	
	// Configura o pino como saída
    ret2 = gpio_pin_configure_dt(&led_1, GPIO_OUTPUT_INACTIVE);
    if (ret2 < 0) {
        printk("Error %d: failed to configure LED pin\n", ret2);
        return;
    }

    printk("LED blinking on %s pin %d\n", led.port->name, led.pin);
	printk("LED blinking on %s pin %d\n", led_1.port->name, led_1.pin);
    
        //pisca o led azul à cada 500ms, pisca o led azul à cada segundo
		// Toggle do LED usando a nova API
		/*
        gpio_pin_toggle_dt(&led);
        k_msleep(100);
		gpio_pin_toggle_dt(&led);
		k_msleep(500);
		gpio_pin_toggle_dt(&led);
		gpio_pin_toggle_dt(&led_1);
		k_msleep(100);
		gpio_pin_toggle_dt(&led);
		gpio_pin_toggle_dt(&led_1);
		k_msleep(SLEEP_TIME_MS);
		*/
		
		//criando um que pisca o led verde à cada 350 ms e o azul à cada 1000 ms
		while(1){
		k_msleep(SLEEP_TIME_MS);
		gpio_pin_set_dt(&led,0); // desliga ambos os pinos dos leds
		gpio_pin_set_dt(&led_1,0);
	    printk("leds desligados!\n");
		}
		// teste do led
		//printk("\n");
    
}