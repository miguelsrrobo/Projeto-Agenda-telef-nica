#ifndef __MEMORI__
#define __MEMORI__

typedef struct {
    char nome[20];
    char telefone[14];
    char endereco[30];
}tipo_registro;

void le_registro (uint16_t numero_do_registro, tipo_registro &R);

void salva_registro(uint16_t numero_do_registro, tipo_registro R);

#endif
