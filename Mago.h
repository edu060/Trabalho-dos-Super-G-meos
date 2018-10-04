#pragma once
#include "Personagem.h"

class Mago :
	public Personagem
{
public:
	Mago();
	~Mago();

	void Especial();

private:
	Texto texto;
	bool pode_dese = true;
};