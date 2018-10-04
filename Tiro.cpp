#include "Tiro.h"



Tiro::Tiro()
{
}


Tiro::~Tiro()
{
}

float Tiro::getX()
{
	return x;
}

float Tiro::getY()
{
	return y;
}

bool Tiro::getVivo()
{
	return vivo;
}

Sprite Tiro::getSprite()
{
	return sprite;
}

void Tiro::inicializar()
{
	if (!gRecursos.carregouSpriteSheet("tiro"))
	{
		gRecursos.carregarSpriteSheet("tiro", "assets/spritesheets/tiro.png");// Carrega o tiro
	}
	sprite.setSpriteSheet("tiro");
	velocidade = 4;
	vivo = false;
}

void Tiro::atualizar()
{
	if (vivo)
	{
		if (lado == 1) //Atira para a direita
		{
			x += velocidade;
		}
		else if (lado == 2) //Atira para a esquerada
		{
			x -= velocidade;
		}
		else if (lado == 3) //Atira para cima
		{
			y -= velocidade;
		}
		else //Atira para baixo
		{
			y += velocidade;
		}


		if (x < sprite.getLargura() || x > gJanela.getLargura() + sprite.getLargura())
		{
			vivo = false;
			//morrer();
		}
		if (y < sprite.getLargura() || y > gJanela.getLargura() + sprite.getLargura())
		{
			vivo = false;
			//morrer();
		}
	}

}

// Desenha o sprite do tiro em uma posissão X,Y
void Tiro::desenhar()
{
	if (vivo)
	{
		sprite.desenhar(x, y);
	}
}

// Determina a morte do tiro
void Tiro::morrer()
{
	vivo = false;
}

// Define o disparo do tiro
void Tiro::disparar(float x, float y, int lado)
{
	this->x = x;
	this->y = y;
	this->lado = lado;
	vivo = true;
}