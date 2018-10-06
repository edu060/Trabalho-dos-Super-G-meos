#pragma once
#include "libUnicornio.h"
#include "Personagem.h"

class Jogo
{
public:
	Jogo();
	~Jogo();
	void inicializar();
	void finalizar();
	void executar();

	int Pers;

protected:
	Personagem * personagem[3];
	TileMap mapa;
};