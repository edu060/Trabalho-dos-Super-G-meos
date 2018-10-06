#include "Personagem.h"

Personagem::Personagem()
{
	vel = 0.2;
	x = 0;
	y = 0;

	
}

Personagem::~Personagem()
{
}

float Personagem::getX()
{
	return x;
}

float Personagem::getY()
{
	return y;
}

float Personagem::getXTiro()
{
	return tiro.getX();
}

float Personagem::getYTiro()
{
	return tiro.getY();
}

void Personagem::matarTiro()
{
	tiro.morrer();
}

int Personagem::getLado()
{
	return lado;
}

Sprite Personagem::getSpriteTiro()
{
	return tiro.getSprite();
}

void Personagem::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Personagem::setVel(float vel)
{
	this->vel = vel;
}

void Personagem::moverDir()
{
	lado = 1;
	x += vel;
	sprite.setAnimacao(CAMINHANDO_DIR);
}

void Personagem::moverEsq()
{
	lado = 2;
	x -= vel;
	sprite.setAnimacao(CAMINHANDO_ESQ);
}

void Personagem::moverCima()
{
	lado = 3;
	y -= vel;
	sprite.setAnimacao(CAMINHANDO_CIMA);
}

void Personagem::moverBaixo()
{
	lado = 0;
	y += vel;
	sprite.setAnimacao(CAMINHANDO_BAIXO);
}

void Personagem::inicializar(string nome, string caminho)
{
	if (!gRecursos.carregouSpriteSheet(nome))
	{
		gRecursos.carregarSpriteSheet(nome, caminho, 4, 4); // carrega a sprite do personagem (nro de animacoes, nro de frames da maior animacao)
	}
	sprite.setSpriteSheet(nome); // posiciona o personagem na tela
	x = 200;
	y = 300;
}

void Personagem::setSpriteSheet(string spritesheet)
{
	sprite.setSpriteSheet(spritesheet);
}

void Personagem::ControleBase()
{
	if (gTeclado.segurando[TECLA_D]) 
	{
		moverDir();
	}
	else if (gTeclado.segurando[TECLA_A])
	{
		moverEsq();
	}
	else if (gTeclado.segurando[TECLA_W])
	{
		moverCima();
	}
	else if (gTeclado.segurando[TECLA_S])
	{
		moverBaixo();
	}

	if (gTeclado.pressionou[TECLA_ESPACO])
	{
		Especial();
	}

	if (Can_Draw == true)
	{
		desenhar();
	}
	tiro.atualizar();
}

void Personagem::Especial()
{
}

void Personagem::animar()
{
	sprite.avancarAnimacao();
}

void Personagem::desenhar()
{
	if (Can_Draw == true)
	{
		sprite.desenhar(x, y);
	}
	tiro.desenhar();
}

