#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "pt-Br");

	cout << "--------- Ambrósio's Grocery Store ---------" << endl;
	while (true)
	{
		int produto = 0;
		int quantidade = 0;
		float total = 0;

		cout << "Informe o produto desejado: ";
		cin >> produto;
		cout << "Informe a quantidade desejada: ";
		cin >> quantidade;

		switch (produto)
		{
			case 1:
				total = quantidade * 5.30;
				break;
			case 2:
				total = quantidade * 6;
				break;
			case 3:
				total = quantidade * 3.20;
				break;
			case 4:
				total = quantidade * 2.50;
				break;
			default:
				cout << "Produto inválido." << endl;
				break;
		}

		if (quantidade >= 15 || total >= 40)
		{
			total -= total * 0.15;
		}

		cout << "O total a ser pago é R$ " << total << endl;

		cout << "\nDeseja realizar uma nova compra? [1 - Sim | 2 - Não]: ";
		int resposta;
		cin >> resposta;

		if (resposta == 2)
			break;
	}

	cout << "Obrigado pela compra!";
}
