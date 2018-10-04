#pragma once
#include "libUnicornio.h"
#include "Tiro.h"

enum PersonagemAnim
{
	CAMINHANDO_BAIXO,
	CAMINHANDO_ESQ,
	CAMINHANDO_DIR,
	CAMINHANDO_CIMA,
	//GIRANDO
};

class Personagem :public ObjetoTileMap
{
public:
	Personagem();
	~Personagem();

	bool Can_Draw = true;
	int lado = 0;

	float getX();
	float getY();
	float getXTiro();
	float getYTiro();

	void matarTiro();

	int getLado();

	Sprite getSpriteTiro();

	void setPos(int x, int y);
	void setVel(float vel);
	void setSpriteSheet(string spritesheet);


	void moverDir();
	void moverEsq();
	void moverCima();
	void moverBaixo();

	void inicializar(string nome, string caminho);


	//void girar();
	//void ficarParado();

	void ControleBase();

	virtual void Especial();

	void animar();
	void desenhar();

protected:
	Sprite sprite;
	float x, y;
	float vel;
	Som som;
	Tiro tiro;
};