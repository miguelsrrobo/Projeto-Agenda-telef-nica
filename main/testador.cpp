


#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "digital.h"
#include "delay.h"
#include "i2c.h"
#include "memori.h"
#include <inttypes.h> 

#define DEVICE 0x50

I2C i2c =  I2C();
volatile uint32_t x;


extern "C" void app_main() ;

uint8_t a;

void testa_se_esta_pronto(void)
{
	uint8_t a;
	while (1)
	{
		i2c.start();
		a = i2c.write(DEVICE << 1);
		if (a==0) break;
		i2c.stop();
		delay_ms(10);
	}
	i2c.stop();
}
void fazEscrita (uint16_t endereco, uint8_t valor)
{
	testa_se_esta_pronto();
	i2c.start();
	i2c.write(DEVICE << 1);	 
	i2c.write(endereco >> 8);
	i2c.write(endereco);
	i2c.write(valor);
	i2c.stop();
}
uint8_t fazLeitura  (uint16_t endereco)
{
	uint8_t a;
	testa_se_esta_pronto();
	i2c.start();
	i2c.write(DEVICE << 1); // operacao fake
	i2c.write(endereco >> 8);
	i2c.write(endereco);
	i2c.start(); // agora sim eh leitura
	i2c.write( (DEVICE << 1) | 1);
	a = i2c.read();
	i2c.stop();
	return a;
}
void salvaString(char * st, uint16_t endereco_base)
{
	uint8_t x=0;
	while (st[x] != 0)
	{
		fazEscrita(endereco_base+x,st[x]);
		x++;
	}
	fazEscrita(endereco_base+x,st[x]);
}
void app_main()
{
uart_config_t uart_config = {
        .baud_rate = 115200,                      //Bluetooth baud rate 
        .data_bits = UART_DATA_8_BITS,          //8 data bits 
        .parity    = UART_PARITY_DISABLE,       //No parity 
        .stop_bits = UART_STOP_BITS_1,          //1 stop bit 
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE   //No hardware flow 
    };
    
    uart_param_config(UART_NUM_0, &uart_config);
	uint8_t lido=0;
	
	i2c.configura(PIN16,PIN5);
	
	//salvaString((char *)"Engenharia de Computacao",200);
	for (int a=0;a<24;a++)
	{
		printf("%c",fazLeitura(200+a));
	}
	printf("\n");
	
	
	
	
	
	
	
      printf("FIM\n");
}
