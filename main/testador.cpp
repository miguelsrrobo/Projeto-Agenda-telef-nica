#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "digital.h"
#include "delay.h"
#include "memoria.h"
#include <inttypes.h> 


volatile uint32_t x;


extern "C" void app_main() ;

uint8_t a;

void app_main(){
uart_config_t uart_config = {
        .baud_rate = 115200,                      //Bluetooth baud rate 
        .data_bits = UART_DATA_8_BITS,          //8 data bits 
        .parity    = UART_PARITY_DISABLE,       //No parity 
        .stop_bits = UART_STOP_BITS_1,          //1 stop bit 
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE   //No hardware flow 
    };
    
    // uart_param_config(UART_NUM_0, &uart_config);
	// uint8_t lido=0;
	
	// i2c.configura(PIN16,PIN5);
	
	// //salvaString((char *)"Engenharia de Computacao",200);
	// for (int a=0;a<24;a++)
	// {
	// 	printf("%c",fazLeitura(200+a));
	// }
	// printf("\n");
	// printf("FIM\n");
}