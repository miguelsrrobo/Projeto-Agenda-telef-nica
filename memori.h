#ifndef __MEMORI__
#define __MEMORI__

typedef struct tipo {
    char nome[20];
    char telefone[14];
    char endereco[30];
}tipo_registro;

typedef struct no {
    tipo_registro tipo;
    struct no* proximo;
}NO

typedef struct fila {
    NO *inicio;
    NO *fim;
    int tamanho;
} Fila;

void le_registro (uint16_t numero_do_registro, tipo_registro &R);

void salva_registro(uint16_t numero_do_registro, tipo_registro R);

void inicializarFila(Fila* fila);

int estaVazia(Fila* fila);

void enfileirar(Fila* fila, Contato contato);

#endif
