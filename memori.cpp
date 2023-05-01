#include "i2c.h"
#include "digital.h"
#include <stdio.h>
#include "memori.h"

void inicializarFila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

int estaVazia(Fila* fila) {
    return fila->tamanho == 0;
}


void enfileirar(Fila* fila, tipo_registro tipo) {
    NO* novoNo = (NO*) malloc(sizeof(NO));
    novoNo->contato = tipo;
    novoNo->proximo = NULL;

    if (estaVazia(fila)) {
        fila->inicio = novoNo;
    } else {
        fila->fim->proximo = novoNo;
    }

    fila->fim = novoNo;
    fila->tamanho++;
}

tipo_registro desenfileirar(Fila* fila) {
    if (estaVazia(fila)) {
        tipo_registro tipo
        strcpy(tipo.nome, "");
        strcpy(tipo.telefone, "");
        strcpy(tipo.endereco, "");
        return tipo;
    }

    NO* noRemovido = fila->inicio;
    tipo_registro tipo = noRemovido->tipo;

    fila->inicio = noRemovido->proximo;
    free(noRemovido);

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    fila->tamanho--;
    return contato;
}

void le_registro (uint16_t numero_do_registro, tipo_registro &R)
{

}

void salva_registro(uint16_t numero_do_registro, tipo_registro R)
{

}


