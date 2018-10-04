#include "Jogo.h"
#include "Guerreiro.h"
//#include "Ladrao.h"
#include "Mago.h"
int main(int argc, char* argv[])
{
	Jogo jogo;
	jogo.inicializar();
	jogo.executar();
	jogo.finalizar();
	system("pause");
	return 0;
}