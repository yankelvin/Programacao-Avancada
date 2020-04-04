#include "Jogador.h"
#include "Embarcacao.h"

Jogador::Jogador(char _tipo)
{
	this->tipo = _tipo;
	this->totalCelulas = this->getTotalCelulas();
}

Embarcacao Jogador::getPortaAvioes()
{
	return this->portaAvioes;
}

Embarcacao Jogador::getNavioTanque()
{
	return this->navioTanque;
}

Embarcacao Jogador::getContratorpedeiro()
{
	return this->contratorpedeiro;
}

Embarcacao Jogador::getSubmarino()
{
	return this->submarino;
}

int Jogador::getTotalCelulas()
{
	int soma = 0;
	soma += this->portaAvioes.getTotalCelulas();
	soma += this->navioTanque.getTotalCelulas();
	soma += this->contratorpedeiro.getTotalCelulas();
	soma += this->submarino.getTotalCelulas();
	return soma;
}
