#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "pt-Br");

	int a[5];
	int b[5];
	int soma = 0;

	int tamanho = sizeof a / sizeof a[0];

	for (int i = 0; i < tamanho; i++)
	{
		cout << "Digite o " << i + 1 << "� elemento de A: ";
		cin >> a[i];
	}

	cout << endl;

	for (int i = 0; i < tamanho; i++)
	{
		cout << "Digite o " << i + 1 << "� elemento de B: ";
		cin >> b[i];

		soma += a[i] * b[i];
	}

	cout << endl;

	cout << "O produto escalar de a[] por b[] � " << soma;
}
