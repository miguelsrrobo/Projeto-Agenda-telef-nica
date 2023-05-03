#include "memoria.h"

// void MEMORIA::init(gpio_num_t pinoDados, gpio_num_t pinoCLOCK)
// {
//     tipo_registro *tipo;
//     tipo->endereco = 0;
//     tipo->nome = 0;
//     tipo->telefone = 0;
// }

void MEMORIA::write(char *buffer, uint16_t endereco_base)
{
	uint8_t x=0;
	while (buffer[x] != 0)
	{
		fazEscrita(endereco_base+x,buffer[x]);
		x++;
	}
	fazEscrita(endereco_base+x,buffer[x]);
}

uint8_t MEMORIA::read(uint16_t endereco)
{
    uint8_t a;
	testa_se_esta_pronto();
	i2c.start();
	i2c.write(DEVICE << 1); // operacao fake
	i2c.write(endereco >> 8);
	i2c.write(endereco);
	i2c.start(); // agora sim eh leitura
	i2c.write( (DEVICE << 1) | 1);
	a = i2c.read();
	i2c.stop();
	return a;
}

void MEMORIA::fazEscrita (uint16_t endereco, uint8_t valor)
{
	testa_se_esta_pronto();
	i2c.start();
	i2c.write(DEVICE << 1);	 
	i2c.write(endereco >> 8);
	i2c.write(endereco);
	i2c.write(valor);
	i2c.stop();
}

void MEMORIA::testa_se_esta_pronto(void)
{
	uint8_t a;
	while (1)
	{
		i2c.start();
		a = i2c.write(DEVICE << 1);
		if (a==0) break;
		i2c.stop();
		delay_ms(10);
	}
	i2c.stop();
}