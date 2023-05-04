#ifndef __MEMORIA__
#define __MEMORIA__

#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "digital.h"
#include "delay.h"
#include "memoria.h"
#include "i2c.h"
#include "bd.h"

#define DEVICE 0x50

class MEMORIA{ 
    private:
        uint8_t dispositivoAlvo;
        void testa_se_esta_pronto(void);
    public:
        void fazEscrita (uint16_t endereco, uint8_t valor);

        void init(uint8_t device);
        void write(char *buffer, uint16_t endereco_base);
        uint8_t read(uint16_t endereco);
        void read_all(uint16_t numero_do_registro, tipo_registro &R);
        void remove_register(uint16_t numero_do_registro, tipo_registro R);
};

#endif