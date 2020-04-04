#pragma once
#include "Embarcacao.h"

class Jogador
{
private:
	Embarcacao portaAvioes = Embarcacao(5, 1);
	Embarcacao navioTanque = Embarcacao(4, 1);
	Embarcacao contratorpedeiro = Embarcacao(3, 2);
	Embarcacao submarino = Embarcacao(2, 2);
	int totalCelulas;
	char tipo;

public:
	Jogador(char _tipo);

    Embarcacao getPortaAvioes();

    Embarcacao getNavioTanque();

    Embarcacao getContratorpedeiro();

    Embarcacao getSubmarino();

	int getTotalCelulas();
};
