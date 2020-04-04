#pragma once
#include "Jogador.h"
#include <vector>

class Jogo
{
private:
	Jogador jogador = Jogador('J');
	Jogador computador = Jogador('C');
	vector<vector<string>> matriz;

public:
	Jogo();

	bool jogadaJogador();

	bool jogadaComputador();

	void gerarTabuleiro();

	void distribuirPecasJogador(char tipoJogador);

	void distribuirPecas(string peca, int celulas);

	Jogador getJogador();

	Jogador getComputador();

	void info();

	void verTabuleiro();

	int gerarRandom(int menor, int maior);
};
