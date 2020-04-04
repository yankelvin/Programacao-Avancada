#include <iostream>
#include "Jogo.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "pt-Br");

	Jogo jogo;

	while (true)
	{
		jogo.verTabuleiro();
		cout << endl;

		jogo.info();
		cout << endl;

		jogo.jogadaJogador();
		jogo.jogadaComputador();

		if (jogo.getJogador().getTotalCelulas() == 0)
		{
			cout << "O computador venceu!\n";
			jogo.info();
			break;
		}
		else if (jogo.getComputador().getTotalCelulas() == 0)
		{
			cout << "O jogador venceu!\n";
			jogo.info();
			break;
		}
	}
}
