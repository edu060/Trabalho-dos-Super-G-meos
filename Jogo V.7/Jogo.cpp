#include "Jogo.h"
#include "Guerreiro.h"
#include "Mago.h"
#include"Ladrao.h"
#include "Personagem.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	Pers = 0;

	uniInicializar(800, 600, false);

	mapa.carregar("assets/tilemaps/mapinha.json");

	//-------------Carregar_Cavaleiro----------------------------------------------------//
	//gRecursos.carregarSpriteSheet("knight", "assets/spritesheets/Knight.png", 4, 4);

	personagem[0] = new Guerreiro;
	personagem[0]->setSpriteSheet("knight");
	personagem[0]->setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	personagem[0]->setVel(0.3);


	//-------------Carregar_Mago--------------------------------------------------------//
	//gRecursos.carregarSpriteSheet("mage", "assets/spritesheets/Mage.png", 4, 4);

	personagem[1] = new Mago;
	personagem[1]->setSpriteSheet("mage");
	personagem[1]->setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	personagem[1]->setVel(0.5);

	//-------------Carregar_Ladrão-----------------------------------------------------//
	//gRecursos.carregarSpriteSheet("thief", "assets/spritesheets/Thief.png", 4, 4);

	personagem[2] = new Ladrao;
	personagem[2]->setSpriteSheet("thief");
	personagem[2]->setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	personagem[2]->setVel(0.8);
}

void Jogo::finalizar()
{
	gRecursos.descarregarTudo();
	mapa.descarregar();
	uniFinalizar();
}

void Jogo::executar()
{

	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		//Desenha O Mapa
		mapa.desenhar();

		//Anima os Personagens
		for (int Per = 0; Per < 3; Per++)
		{
			personagem[Per]->animar();
		}

		//Troca de Personagem
		if (gTeclado.pressionou[TECLA_X])
		{
			if (Pers == 0)
			{
				Pers = 1;
			}
			else if (Pers == 1)
			{
				Pers = 2;
			}
			else if (Pers == 2)
			{
				Pers = 0;
			}
		}

		//Controles do Personagem
		personagem[Pers]->ControleBase();

		//Desenha os Personagens
		for (int Per = 0; Per < 3; Per++)
		{
			personagem[Per]->desenhar();
		}

		uniTerminarFrame();
	}
}