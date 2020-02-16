#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "pt-Br");

	cout << "-------- Lojão das Tintas --------" << endl;
	float qtdLata1 = 24 * 7, qtdLata2 = 5.4 * 7;

	while (true)
	{
		float metrosQ = 0, total = 0;
		int quantidade = 0;

		cout << "\nInforme a quantidade de metros quadrados: ";
		cin >> metrosQ;

		quantidade = ceil(metrosQ / qtdLata1);
		total = quantidade * 91;

		cout << endl;
		cout << quantidade << " lata(s) de 24 litros: R$ " << total;

		quantidade = ceil(metrosQ / qtdLata2);
		total = quantidade * 23;

		cout << endl;
		cout << quantidade << " lata(s) de 5.4 litros: R$ " << total;

		if (metrosQ > qtdLata1)
		{
			int lata1 = floor(metrosQ / qtdLata1);
			float metrosLata1 = lata1 * qtdLata1;
			float sobra = metrosQ - metrosLata1;

			int lata2 = ceil(sobra / qtdLata2);
			total = (lata1 * 91) + (lata2 * 23);

			cout << endl;
			cout << lata1 << " lata(s) de 24 litros e " << lata2 << " lata(s) de 5.4 litros: R$ " << total << endl;
		}

		cout << "\nDeseja realizar uma nova compra? [1 - Sim | 2 - Não]: ";
		int resposta;
		cin >> resposta;

		if (resposta == 2)
			break;
	}
}
