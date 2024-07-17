#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "../debug_probe/probe.h"


Probe pr_D1 = Probe(1);
Probe pr_D4 = Probe(4);
Probe pr_D5 = Probe(5);


void led_task(void *)
{   
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        gpio_put(LED_PIN, 1);
        pr_D1.hi();
        vTaskDelay(100);
        gpio_put(LED_PIN, 0);
        pr_D1.lo();
        vTaskDelay(900);
    }
}
void ch4_task(void *)
{   
    while (true) {
        pr_D4.hi();
        vTaskDelay(300);
        pr_D4.lo();
        vTaskDelay(300);
    }
}
void ch5_task(void *)
{   
    while (true) {
        pr_D5.hi();
        vTaskDelay(500);
        pr_D5.lo();
        vTaskDelay(500);
    }
}

int main()
{
    stdio_init_all();

    xTaskCreate(led_task, "ch1_Task", 256, NULL, 1, NULL);
    xTaskCreate(ch4_task, "ch4_Task", 256, NULL, 1, NULL);
    xTaskCreate(ch5_task, "ch5_Task", 256, NULL, 1, NULL);
    vTaskStartScheduler();

    while(1){};
}