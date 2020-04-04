#include "Embarcacao.h"
#include <iostream>

Embarcacao::Embarcacao(int celulas, int qtd)
{
	this->celulasAtual = celulas;
	this->celulasTotal = celulas;
	this->qtd = qtd;
}

void Embarcacao::bombardeou()
{
	int* ptr = &celulasAtual;

	if (this->celulasAtual > 0)
		*ptr--;

	if (this->celulasAtual == 0)
	{
		this->finalizou();
		cout << "\n" << this->tipo << "destruído! " << this->celulasTotal << "celulas" << endl;
	}
}

void Embarcacao::finalizou()
{
	if (this->qtd > 0)
		this->qtd--;
}

int Embarcacao::getTotalCelulas()
{
	return this->celulasAtual * this->qtd;
}

int Embarcacao::getCelulas()
{
	return this->celulasAtual;
}

int Embarcacao::getQtd()
{
	return this->qtd;
}
