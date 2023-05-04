#ifndef __BD__
#define __BD__

#include <inttypes.h>

typedef struct {
    uint16_t qtdRegistros;
    uint16_t qtdMAX;
}Tipo_Cabecalho;

typedef struct {
    char nome[20];
    char telefone[14];
    char endereco[30];
}tipo_registro;

void cria_cabecalho(Tipo_Cabecalho *c);
void atualiza_cabecalho();
void remove_cabecalho();

Tipo_Cabecalho le_cabecalho(char comando);
void salva_registro(uint16_t numero_do_registro, tipo_registro *R);
void lista_registros();

void busca_nome(char n[20]);
tipo_registro busca_telefone(char t[14]);
void remove_registro(char t[14]);


#endif