#include "Guerreiro.h"

Guerreiro::Guerreiro()
{
	inicializar("knight", "assets/spritesheets/Knight.png");
	gRecursos.carregarAudio("Monstro", "assets/som/Monstro.wav");

	som.setAudio("Monstro");
	som.setVolume(50);
}

Guerreiro::~Guerreiro()
{
}

void Guerreiro::Especial()
{
	som.tocar();
}
