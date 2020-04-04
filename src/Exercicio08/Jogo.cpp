#include "Jogo.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

Jogo::Jogo()
{
	this->gerarTabuleiro();
	this->distribuirPecasJogador('J');
	this->distribuirPecasJogador('C');
}

bool Jogo::jogadaJogador()
{
	cout << "\n";
	while (true)
	{
		int linha, coluna;

		while (true)
		{
			cout << "Escolha uma linha [1 a 10]: ";
			cin >> linha;
			linha--;

			if (linha > -1 && linha < 10)
				break;
			else
				cout << "Linha inválida!\n\n";
		}

		while (true)
		{
			cout << "Escolha uma coluna [1 a 10]:";
			cin >> coluna;
			coluna--;

			if (coluna > -1 && coluna < 10)
				break;
			else
				cout << "Coluna inválida!\n\n";
		}

		char letra = matriz[linha][coluna][0];

		switch (letra)
		{
			case 'J':
				cout << "\nVocê não pode acertar sua própria embarcação.\n";
				break;
			case 'C':
			{
				char embarcacao = matriz[linha][coluna][1];
				cout << "\nAcertou!\n";
				switch (embarcacao)
				{
					case 'P':
						computador.getPortaAvioes().bombardeou();
						break;
					case 'N':
						computador.getNavioTanque().bombardeou();
						break;
					case 'C':
						computador.getContratorpedeiro().bombardeou();
						break;
					case 'S':
						computador.getSubmarino().bombardeou();
						break;
					default:
						break;
				}

				matriz[linha][coluna] = "---";
				return true;
			}
			default:
				cout << "\nAgua!\n";
				return true;
		}
	}
}

bool Jogo::jogadaComputador()
{
	cout << "\n";
	while (true)
	{
		int linha = this->gerarRandom(0, 9);
		int coluna = this->gerarRandom(0, 9);

		char letra = matriz[linha][coluna][0];

		switch (letra)
		{
			case 'C':
				break;
			case 'J':
			{
				char embarcacao = matriz[linha][coluna][1];
				cout << "Computador acertou!\n";
				switch (embarcacao)
				{
					case 'P':
						jogador.getPortaAvioes().bombardeou();
						break;
					case'N':
						jogador.getNavioTanque().bombardeou();
						break;
					case 'C':
						jogador.getContratorpedeiro().bombardeou();
						break;
					case 'S':
						jogador.getSubmarino().bombardeou();
						break;
					default:
						break;
				}

				matriz[linha][coluna] = "---";
				return true;
			}
			default:
				cout << "Computador errou!\n";
				return true;
		}
	}
}

void Jogo::gerarTabuleiro()
{
	for (int i = 0; i < 10; i++)
	{
		vector<string> lista;
		for (int j = 0; j < 10; j++)
			lista.push_back("---");

		matriz.push_back(lista);
	}
}

void Jogo::distribuirPecasJogador(char tipoJogador)
{
	switch (tipoJogador)
	{
		case 'J':
			distribuirPecas("JP", 5);
			distribuirPecas("JN", 4);
			distribuirPecas("JC", 3);
			distribuirPecas("JC", 3);
			distribuirPecas("JS", 2);
			distribuirPecas("JS", 2);
			break;
		case 'C':
			distribuirPecas("CP", 5);
			distribuirPecas("CN", 4);
			distribuirPecas("CC", 3);
			distribuirPecas("CC", 3);
			distribuirPecas("CS", 2);
			distribuirPecas("CS", 2);
			break;
	}
}

void Jogo::distribuirPecas(string peca, int celulas)
{
	int coluna, linha;
	while (true)
	{
		coluna = this->gerarRandom(0, 9);
		linha = this->gerarRandom(0, 9);
		vector<string> posicao = matriz[linha];
		if (posicao[coluna] == "---")
		{
			if ((coluna + 2) >= 10 || (coluna - 2) < 0)
				continue;

			if (posicao[coluna + 2]._Equal("---") && posicao[coluna - 2]._Equal("---"))
			{
				if (coluna >= celulas)
				{
					int c = 1, remove = 0;
					for (int i = coluna; i > (coluna - celulas); i--)
					{
						while (true)
						{
							if (posicao[remove]._Equal("---"))
							{
								posicao[remove] = "---";
								break;
							}
							remove++;
						}
						matriz[linha][i] = peca + to_string(c++);
					}
					break;
				}
				else
				{
					int c = 1, remove = 9;
					for (int i = coluna; i < (coluna + celulas); i++)
					{
						while (true)
						{
							if (posicao[remove]._Equal("---"))
							{
								posicao[remove] = "---";
								break;
							}
							remove--;
						}
						matriz[linha][i] = peca + to_string(c++);
					}
					break;
				}
			}
		}
	}
}

Jogador Jogo::getJogador()
{
	return this->jogador;
}

Jogador Jogo::getComputador()
{
	return this->computador;
}

void Jogo::info()
{
	cout << "\nInformações do Jogador: " << endl;
	cout << "PortaAvioes:        Celulas = " << this->jogador.getPortaAvioes().getCelulas() << " | Qtd = " << this->jogador.getPortaAvioes().getQtd() << endl;
	cout << "NavioTanque:        Celulas = " << this->jogador.getNavioTanque().getCelulas() << " | Qtd = " << this->jogador.getNavioTanque().getQtd() << endl;
	cout << "Contratorpedeiro:   Celulas = " << this->jogador.getContratorpedeiro().getCelulas() << " | Qtd = " << this->jogador.getContratorpedeiro().getQtd() << endl;
	cout << "Submarinos:         Celulas = " << this->jogador.getSubmarino().getCelulas() << " | Qtd = " << this->jogador.getSubmarino().getQtd() << endl;

	cout << endl;
	cout << "Informações do Computador:" << endl;
	cout << "PortaAvioes:        Celulas = " << this->computador.getPortaAvioes().getCelulas() << " | Qtd = " << this->computador.getPortaAvioes().getQtd() << endl;
	cout << "NavioTanque:        Celulas = " << this->computador.getNavioTanque().getCelulas() << " | Qtd = " << this->computador.getNavioTanque().getQtd() << endl;
	cout << "Contratorpedeiro:   Celulas = " << this->computador.getContratorpedeiro().getCelulas() << " | Qtd = " << this->computador.getContratorpedeiro().getQtd() << endl;
	cout << "Submarinos:         Celulas = " << this->computador.getSubmarino().getCelulas() << " | Qtd = " << this->computador.getSubmarino().getQtd() << endl;
}

void Jogo::verTabuleiro()
{
	printf("\n%35s\n", "- BATALHA NAVAL -");
	printf("%8s %4s %4s %4s %4s %4s %4s %4s %4s %5s \n", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10");
	for (int i = 0; i < 10; i++)
	{
		string s = "";
		s += to_string(i + 1);
		if (i < 9)
			s += "  : ";
		else
			s += " : ";

		s += "[";
		for (int j = 0; j < 10; j++)
		{
			string valor = this->matriz[i][j];
			char letra = valor[0];
			if (letra != 'C')
			{
				s += valor;
				if (j < 9)
					s += ", ";
			}
			else
			{
				s += "---";

				if (j < 9)
					s += ", ";
			}
		}

		s += "]\n";
		cout << s;
	}
}

int Jogo::gerarRandom(int menor, int maior)
{
	return rand() % maior + menor;
}
