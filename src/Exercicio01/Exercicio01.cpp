#include <iostream>
#include <math.h>
#include <string>

using namespace std;

float questao01()
{
	float denominador = 1;
	float numerador;
	float soma = 0;

	while (denominador <= 50)
	{
		numerador = denominador + (denominador - 1);
		soma += (numerador / denominador++);
	}

	return soma;
}

float questao02(int n)
{
	float pi = 0;
	int denominador = 1;

	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			pi += (float)4 / denominador;
		}
		else
		{
			pi -= (float)4 / denominador;
		}

		denominador += 2;
	}

	return pi;
}

float questao03()
{
	int expoente = 1;
	int denominador = 50;
	float soma = 0;

	while (denominador > 0)
	{
		soma += (float)(pow(2, expoente++) / denominador--);
	}

	return soma;
}

void questao04(int n)
{
	int soma = 0;
	int numImpar = 1;

	cout << "Série: ";

	for (int i = 0; i < n; i++)
	{
		soma += numImpar;
		cout << soma << " ";

		numImpar += 2;
	}
}

void questao05(int n)
{
	int seq1 = 1;
	int seq2 = 4;
	int position = 1;

	for (int i = 0; i < n; i++)
	{
		if (position == 1)
			cout << seq1++ << " ";

		if (position == 2)
			cout << seq2 << " ";

		if (position == 3)
		{
			cout << seq2++ << " ";
			position = 0;
		}

		position++;
	}
}

void questao06(int n)
{
	int a = 0;
	int b = 1;

	for (int i = 0; i < n; i++)
	{
		cout << a << " ";

		int c = b;
		b = a + b;
		a = c;
	}
}

void questao07(int n)
{
	int otimo = 0;
	int bom = 0;
	int regular = 0;
	int ruim = 0;
	int pessimo = 0;

	int somaIdadeRuim = 0;
	int maiorIdadePessimo = 0;
	int maiorIdadeOtimo = 0;
	int maiorIdadeRuim = 0;

	for (int i = 0; i < n; i++)
	{
		int idade;
		string nota;

		cout << "Espectador " << i + 1 << endl;
		cout << "Informe sua idade: ";
		cin >> idade;
		cout << "Informe sua nota (A-E): ";
		cin >> nota;

		if (nota == "A")
		{
			otimo++;
			if (i == 0)
				maiorIdadeOtimo = idade;
			else
				if (idade > maiorIdadeOtimo)
					maiorIdadeOtimo = idade;
		}
		else if (nota == "B")
			bom++;
		else if (nota == "C")
			regular++;
		else if (nota == "D")
		{
			ruim++;
			somaIdadeRuim += idade;

			if (i == 0)
				maiorIdadeRuim = idade;
			else
				if (idade > maiorIdadeRuim)
					maiorIdadeRuim = idade;
		}
		else if (nota == "E")
		{
			pessimo++;
			if (i == 0)
				maiorIdadePessimo = idade;
			else
				if (idade > maiorIdadePessimo)
					maiorIdadePessimo = idade;
		}
		else
			cout << "Nota inválida!";
	}

	int total = otimo + bom + regular + ruim + pessimo;
	float diferencaBomERegular = ((bom / total) - (regular / total)) * 100;

	cout << "Quantidade de respostas ótimo: " << otimo << endl;
	cout << "Diferença percentual entre respostas bom e regular: " << diferencaBomERegular << "%\n";
	cout << "Média de idade das pessoas que responderam ruim: " << (float)somaIdadeRuim / ruim << endl;
	cout << "Porcentagem de respostas péssima: " << (float)(pessimo / total) * 100 << "%\n";
	cout << "Maior idade que utilizou péssimo: " << maiorIdadePessimo;
	cout << "Diferença de idade entre a maior idade otimo e ruim: " << maiorIdadeOtimo - maiorIdadeRuim;
}

int main()
{
	setlocale(LC_ALL, "pt-Br");

	cout << "Informe o número do exercício: ";
	int num;
	cin >> num;

	switch (num)
	{
	case 1:
		cout << "\nA soma é: " << questao01();
		break;
	case 2:
		cout << "\nInforme o número de interações: ";
		int n;
		cin >> n;
		cout << "\nA soma é: " << questao02(n);
		break;
	case 3:
		cout << "\nA soma é: " << questao03();
		break;
	case 4:
		cout << "\nInforme o número de interações: ";
		cin >> n;
		questao04(n);
		break;
	case 5:
		cout << "\nInforme o número de interações: ";
		cin >> n;
		questao05(n);
		break;
	case 6:
		cout << "\nInforme o número de interações: ";
		cin >> n;
		questao06(n);
		break;
	case 7:
		questao07(100);
		break;
	default:
		break;
	}
}
