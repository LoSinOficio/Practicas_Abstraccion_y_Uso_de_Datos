#include <iostream>
#include <list>

using namespace std;

// Definición de la clase para manejar la Lista
class Lista {
private:
    list<int> elementos; // Lista dinámica de la biblioteca estándar de C++

public:
    // Método para inicializar y mostrar los elementos
    void mostrarLista() {
        elementos.push_back(10);
        elementos.push_back(20);
        elementos.push_front(5);

        cout << "--- Lista STL ---" << endl;
        cout << "Elementos de la lista: ";
        for (int v : elementos) {
            cout << v << " ";
        }
        cout << endl;
    }
};

int main() {
    // 1. Creación del objeto de la clase Lista (Instanciación)
    Lista miObjetoLista;

    // 2. Invocación del método a través del objeto
    miObjetoLista.mostrarLista();

    return 0;
}