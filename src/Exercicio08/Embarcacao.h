#pragma once
#include <string>

using namespace std;

class Embarcacao
{
private:
	string tipo;
	int celulasTotal;
	int celulasAtual;
	int qtd;

public:
	Embarcacao(int celulas, int qtd);

	void bombardeou();

	void finalizou();

	int getTotalCelulas();

	int getCelulas();

	int getQtd();
};
