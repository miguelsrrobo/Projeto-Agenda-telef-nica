#ifndef __MEMORIA__
#define __MEMORIA__

#include "digital.h"
#include "i2c.h"
#include "delay.h"

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


#define DEVICE 0x50

I2C i2c =  I2C();

typedef struct
{
    uint16_t qtdRegistros;
    uint16_t qtdMAX;
}Tipo_Cabecalho;

typedef struct {
    char nome[20];
    char telefone[14];
    char endereco[30];
}tipo_registro;

class MEMORIA{ 
    public:
        void testa_se_esta_pronto(void);
        void fazEscrita (uint16_t endereco, uint8_t valor);

        void init(gpio_num_t pinoDados, gpio_num_t pinoCLOCK);
        void write(char *buffer, uint16_t endereco_base);
        uint8_t read(uint16_t endereco);
        void read_all(uint16_t numero_do_registro, tipo_registro &R);
        void remove_register(uint16_t numero_do_registro, tipo_registro R);
};

#endif