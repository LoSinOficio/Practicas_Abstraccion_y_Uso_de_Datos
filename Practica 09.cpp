#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int N = 5;
    double numeros[N], suma = 0, minimo, maximo;

    cout << "Ingresa " << N << " numeros:\n";
    for (int i = 0; i < N; ++i) {
        cout << "Numero " << i + 1 << ": ";
        cin >> numeros[i];
        suma += numeros[i];
    }

    minimo = maximo = numeros[0];
    for (int i = 1; i < N; ++i) {
        if (numeros[i] < minimo) minimo = numeros[i];
        if (numeros[i] > maximo) maximo = numeros[i];
    }

    cout << fixed << setprecision(2);
    cout << "\nSuma: " << suma << '\n';
    cout << "Promedio/media: " << suma / N << '\n';
    cout << "Maximo: " << maximo << '\n';
    cout << "Minimo: " << minimo << '\n';
    return 0;
}

