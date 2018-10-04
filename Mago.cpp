#include "Mago.h"

Mago::Mago()
{
	gRecursos.carregarFonte("magia", "assets/texto/Merda.ttf", 80);
	texto.setFonte("magia");
	texto.setString("Skidaddle Skidoodle");

	/*while (pode_dese == false) {
		texto.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	}*/

	inicializar("mage", "assets/spritesheets/Mage.png");
	tiro.inicializar();

	gRecursos.carregarAudio("Explosao", "assets/som/Explosao.wav");

	som.setAudio("Explosao");
	som.setVolume(50);
}

Mago::~Mago()
{
}

void Mago::Especial()
{
	/*if (pode_dese == true)
	{
		pode_dese = false;
	}
	else
	{
		pode_dese = true;
	}*/
	//tiro.desenhar();
	if (tiro.getVivo() == false) {
		tiro.disparar(x, y, lado); 
		//som.tocar();
		//texto.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
	}
	//tiro.disparar(x, y, lado);
	
	
	//texto.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
}
