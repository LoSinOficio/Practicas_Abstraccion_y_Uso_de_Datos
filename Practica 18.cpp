// Ejercicio 18: Quick Sort (Caracteres, Enteros y Tipo Personalizado) - PE y POO
#include <iostream>
#include <string>
using namespace std;

class OrdenadorQuick {
private:
    static int particion(int arr[], int low, int high) {
        int pivote = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivote) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return (i + 1);
    }

public:
    static void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pi = particion(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
};

int main() {
    int datos[] = {10, 7, 8, 9, 1, 5};
    int n = 6;

    OrdenadorQuick::quickSort(datos, 0, n - 1);

    cout << "--- Quick Sort ---" << endl;
    cout << "Enteros ordenados: ";
    for (int i = 0; i < n; i++) cout << datos[i] << " ";
    cout << endl;

    return 0;
}
