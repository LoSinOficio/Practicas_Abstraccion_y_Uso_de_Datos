#include <iostream>
#include <string>

using namespace std;

// 1. Responsabilidad: Lógica de la Lista Dinámica con Nodos y Punteros 
class ListaDinamica {
private:
    struct Nodo {
        int dato;
        Nodo* siguiente;
        Nodo(int valor, Nodo* sig = nullptr) : dato(valor), siguiente(sig) {}
    };

    Nodo* cabeza;

public:
    ListaDinamica() : cabeza(nullptr) {}

    ~ListaDinamica() {
        while (cabeza != nullptr) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

    bool estaVacia() const { return cabeza == nullptr; }

    void insertar(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (estaVacia()) {
            cabeza = nuevo;
        } else {
            Nodo* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
        cout << "Elemento " << valor << " insertado en la lista.\n";
    }

    // Recorrido seguro mediante un callback para no exponer la estructura interna
    void recorrer(void (*accion)(int)) const {
        for (Nodo* actual = cabeza; actual != nullptr; actual = actual->siguiente) {
            accion(actual->dato);
        }
    }
};

class VisualizadorLista {
public:
    static void mostrar(const ListaDinamica& lista) {
        if (lista.estaVacia()) {
            cout << "La lista esta vacia.\n";
            return;
        }
        cout << "\n[CABEZA] -> ";
        lista.recorrer([](int dato) {
            cout << dato << " -> ";
        });
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

    // Mostrando la lista resultante mediante la clase VisualizadorLista
    VisualizadorLista::mostrar(miLista);

    return 0;
}