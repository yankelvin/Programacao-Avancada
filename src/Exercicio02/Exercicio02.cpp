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
        cout << "Digite o " << i + 1 << "ª elemento de A: ";
        cin >> a[i];
    }

    cout << endl;

    for (int i = 0; i < tamanho; i++)
    {
        cout << "Digite o " << i + 1 << "ª elemento de B: ";
        cin >> b[i];
    }

    cout << endl;

    for (int i = 0; i < tamanho; i++)
    {
        soma += a[i] * b[i];
    }

    cout << "O produto escalar de a[] por b[] é " << soma;
}
