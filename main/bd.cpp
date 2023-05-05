#include "bd.h"
#include "memoria.h"

MEMORIA memoria = MEMORIA();

void cria_cabecalho(Tipo_Cabecalho *c)
{
    memoria.write(c,0);
}

void atualiza_cabecalho();
void remove_cabecalho();

Tipo_Cabecalho le_cabecalho(char comando);
void salva_registro(uint16_t numero_do_registro, tipo_registro *R);
void lista_registros();

void busca_nome(char n[20]);
tipo_registro busca_telefone(char t[14]);
void remove_registro(char t[14]);
