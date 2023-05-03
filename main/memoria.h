#ifndef __MEMORIA__
#define __MEMORIA__

#include "digital.h"

class TIPO_REGISTO{ 
    public:
        char nome[20];
        char telefone[14];
        char endereco[30];
}

class MEMORIA{ 
    private:
        void testa_se_esta_pronto(void);
        void fazEscrita (uint16_t endereco, uint8_t valor);

    public:
        void init(gpio_num_t pinoDados, gpio_num_t pinoCLOCK);
        void write(void *buffer, uint16_t tam);
        void read(uint16_t endereco);
        void read_all(uint16_t numero_do_registro, tipo_registro &R);
        void remove_register(uint16_t numero_do_registro, tipo_registro R);
}

#endif