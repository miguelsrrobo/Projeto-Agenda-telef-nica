#include "i2c.h"
#include "digital.h"
#include <stdio.h>
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "digital.h"

#include "memori.h"


void inicializarFila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

int estaVazia(Fila* fila) {
    return fila->tamanho == 0;
}


void enfileirar(Fila* fila, Contato contato) {
    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->contato = contato;
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
        Contato contatoVazio;
        strcpy(contatoVazio.nome, "");
        strcpy(contatoVazio.telefone, "");
        strcpy(contatoVazio.endereco.rua, "");
        contatoVazio.endereco.numero = 0;
        strcpy(contatoVazio.endereco.cidade, "");
        return contatoVazio;
    }

    No* noRemovido = fila->inicio;
    Contato contato = noRemovido->contato;

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


