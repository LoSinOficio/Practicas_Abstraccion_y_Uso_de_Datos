// Ejercicio 19: Ordenamiento Indirecto por Burbuja (Uso de arreglos de punteros)
#include <iostream>
#include <string>
using namespace std;

class OrdenamientoIndirecto {
public:
    static void ordenarPunterosEnteros(int* ptrs[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (*ptrs[j] > *ptrs[j + 1]) {
                    int* temp = ptrs[j];
                    ptrs[j] = ptrs[j + 1];
                    ptrs[j + 1] = temp;
                }
            }
        }
    }
};


int main() {
    int datos[] = {50, 10, 40, 20, 30};
    int n = 5;
    int* ptrs[5];

    for (int i = 0; i < n; i++) ptrs[i] = &datos[i];

    OrdenamientoIndirecto::ordenarPunterosEnteros(ptrs, n);

    cout << "--- Burbuja Indirecta ---" << endl;
    cout << "Arreglo original sin modificar: ";
    for (int i = 0; i < n; i++) cout << datos[i] << " ";
    cout << endl;

    cout << "Valores accedidos mediante punteros ordenados: ";
    for (int i = 0; i < n; i++) cout << *ptrs[i] << " ";
    cout << endl;

    return 0;
}
