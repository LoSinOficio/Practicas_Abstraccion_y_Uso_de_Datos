#include <iostream>

using namespace std;

// 1. Estructura del Nodo auto-referenciado para la Lista
struct Nodo {
    int dato;
    Nodo* siguiente; // Puntero que apunta al siguiente nodo de la lista
};

// 2. Clase orientada a objetos para administrar la Lista Dinámica
class ListaDinamica {
private:
    Nodo* cabeza; // Puntero que apunta al inicio de la lista

public:
    // Constructor: Inicializa la lista vacía
    ListaDinamica() {
        cabeza = nullptr;
    }

    // Método para insertar un elemento al final de la lista
    void insertar(int valor) {
        Nodo* nuevo = new Nodo();
        nuevo->dato = valor;
        nuevo->siguiente = nullptr;

        if (cabeza == nullptr) {
            cabeza = nuevo; // Si está vacía, el nuevo nodo es la cabeza
        } else {
            Nodo* actual = cabeza;
            // Recorremos hasta llegar al último nodo
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo; // Conectamos el nuevo nodo al final
        }
        cout << "Elemento " << valor << " insertado en la lista.\n";
    }

    // Método para mostrar todos los elementos de la lista de manera indirecta
    void mostrar() {
        if (cabeza == nullptr) {
            cout << "La lista esta vacia.\n";
            return;
        }
        Nodo* actual = cabeza;
        cout << "\n[CABEZA] -> ";
        while (actual != nullptr) {
            cout << actual->dato << " -> ";
            actual = actual->siguiente;
        }
        cout << "[NULL]\n";
    }
};

int main() {
    cout << "=== EJERCICIO 7 BIS: LISTA DINAMICA CON PUNTEROS (POO) ===" << endl;
    
    ListaDinamica miLista;

    // Insertando elementos de prueba
    miLista.insertar(10);
    miLista.insertar(20);
    miLista.insertar(30);

    // Mostrando la lista resultante
    miLista.mostrar();

    return 0;
}