// Ejercicio 21: Quick Sort Indirecto mediante Punteros
#include <iostream>
using namespace std;

class QuickSortIndirecto {
private:
    static int particion(int* ptrs[], int low, int high) {
        int pivote = *ptrs[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (*ptrs[j] < pivote) {
                i++;
                int* temp = ptrs[i];
                ptrs[i] = ptrs[j];
                ptrs[j] = temp;
            }
        }
        int* temp = ptrs[i + 1];
        ptrs[i + 1] = ptrs[high];
        ptrs[high] = temp;
        return (i + 1);
    }

public:
    static void ordenar(int* ptrs[], int low, int high) {
        if (low < high) {
            int pi = particion(ptrs, low, high);
            ordenar(ptrs, low, pi - 1);
            ordenar(ptrs, pi + 1, high);
        }
    }
};

int main() {
    int datos[] = {99, 11, 44, 22, 88};
    int n = 5;
    int* ptrs[5];
    for (int i = 0; i < n; i++) ptrs[i] = &datos[i];

    QuickSortIndirecto::ordenar(ptrs, 0, n - 1);

    cout << "--- Quick Sort Indirecto ---" << endl;
    cout << "Orden mediante punteros: ";
    for (int i = 0; i < n; i++) cout << *ptrs[i] << " ";
    cout << endl;

    return 0;
}
