#ifndef __MEMORIA__
#define __MEMORIA__


typedef struct {
    uint16_t qtdRegistros;
    uint16_t qtdMAX;
}Tipo_Cabecalho;

typedef struct {
    char nome[20];
    char telefone[14];
    char endereco[30];
}tipo_registro;

void esxreverCabecalho (uint16_t numero_do_registro, tipo_registro &R);

void formata (void);

void insere(void);
#endif