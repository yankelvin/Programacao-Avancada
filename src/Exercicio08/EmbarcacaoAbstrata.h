#pragma once
class EmbarcacaoAbstrata
{
protected:
	int celulas;
	int qtd;

public:
	virtual void bombardeou();

	void finalizou();

	int getTotalCelulas();
};
