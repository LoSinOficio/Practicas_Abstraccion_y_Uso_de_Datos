#include <iostream>

using namespace std;

// 1. Estructura del Nodo auto-referenciado para la Cola
struct Nodo {
    int dato;
    Nodo* siguiente; // Puntero al siguiente nodo
};

// 2. Clase orientada a objetos para la Cola Dinámica
class ColaDinamica {
private:
    Nodo* frente;
    Nodo* final;

public:
    // Constructor
    ColaDinamica() {
        frente = nullptr;
        final = nullptr;
    }

    // Verificar si la cola está vacía
    bool estaVacia() {
        return (frente == nullptr);
    }

    // Método para agregar un elemento a la cola (Enqueue)
    void encolar(int valor) {
        Nodo* nuevo = new Nodo();
        nuevo->dato = valor;
        nuevo->siguiente = nullptr;

        if (estaVacia()) {
            frente = nuevo;
        } else {
            final->siguiente = nuevo;
        }
        final = nuevo;
        cout << "Elemento " << valor << " agregado a la cola.\n";
    }

    // Método para mostrar los elementos de la cola
    void mostrar() {
        if (estaVacia()) {
            cout << "La cola esta vacia.\n";
            return;
        }
        Nodo* actual = frente;
        cout << "\n[FRENTE] -> ";
        while (actual != nullptr) {
            cout << actual->dato << " -> ";
            actual = actual->siguiente;
        }
        cout << "[FINAL]\n";
    }
};

int main() {
    cout << "=== EJERCICIO 7: COLA DINAMICA CON PUNTEROS (POO) ===" << endl;
    
    ColaDinamica miCola;

    // Inserción de elementos de prueba
    miCola.encolar(100);
    miCola.encolar(200);
    miCola.encolar(300);

    // Mostrar estructura
    miCola.mostrar();

    return 0;
}