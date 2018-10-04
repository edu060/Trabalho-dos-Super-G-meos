#pragma once
#include "libUnicornio.h"
class Tiro
{
public:
	Tiro();
	~Tiro();

	float getX();
	float getY();

	bool getVivo();

	Sprite getSprite();

	void inicializar();
	void atualizar();
	void desenhar();
	void morrer();
	void disparar(float x, float y, int lado);

private:
	float x, y, velocidade;
	Sprite sprite;
	bool vivo;
	int lado;
};

