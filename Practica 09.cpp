#include <iostream>
#include <iomanip>

using namespace std;

// Definición de la clase orientada a objetos
class EstadisticasArreglo {
private:
    static const int N = 5;
    double numeros[N];
    double suma;
    double minimo;
    double maximo;

public:
    // Constructor para inicializar variables
    EstadisticasArreglo() {
        suma = 0;
        minimo = 0;
        maximo = 0;
    }

    // Método para ingresar los números y calcular las operaciones
    void ingresarDatos() {
        cout << "Ingresa " << N << " numeros:\n";
        for (int i = 0; i < N; ++i) {
            cout << "Numero " << i + 1 << ": ";
            cin >> numeros[i];
            suma += numeros[i];
        }

        // Determinamos el mínimo y el máximo con el primer elemento
        minimo = maximo = numeros[0];
        for (int i = 1; i < N; ++i) {
            if (numeros[i] < minimo) minimo = numeros[i];
            if (numeros[i] > maximo) maximo = numeros[i];
        }
    }

    // Método para mostrar los resultados en pantalla
    void mostrarResultados() {
        cout << fixed << setprecision(2);
        cout << "\nSuma: " << suma << '\n';
        cout << "Promedio/media: " << suma / N << '\n';
        cout << "Maximo: " << maximo << '\n';
        cout << "Minimo: " << minimo << '\n';
    }
};

int main() {
    // 1. Creación del objeto de la clase (Instanciación)
    EstadisticasArreglo calculo;

    // 2. Invocación de los métodos a través del objeto
    calculo.ingresarDatos();
    calculo.mostrarResultados();

    return 0;
}