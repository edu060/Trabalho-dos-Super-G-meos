#include "Ladrao.h"

Ladrao::Ladrao()
{
	inicializar("thief", "assets/spritesheets/Thief.png");
}

Ladrao::~Ladrao()
{
}

void Ladrao::Especial()
{
	if (Can_Draw == true)
	{
		Can_Draw = false;
	}
	else
	{
		Can_Draw = true;
	}
}
