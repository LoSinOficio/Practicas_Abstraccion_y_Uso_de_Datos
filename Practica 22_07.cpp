#include <iostream>
#include <string>

using namespace std;

// 1. Responsabilidad: Lógica de la Cola Dinámica con Nodos y Punteros 
class ColaDinamica {
private:
    struct Nodo {
        int dato;
        Nodo* siguiente;
        Nodo(int valor, Nodo* sig = nullptr) : dato(valor), siguiente(sig) {}
    };

    Nodo* frente;
    Nodo* final;

public:
    ColaDinamica() : frente(nullptr), final(nullptr) {}

    ~ColaDinamica() {
        while (frente != nullptr) {
            Nodo* temp = frente;
            frente = frente->siguiente;
            delete temp;
        }
    }

    bool estaVacia() const { return frente == nullptr; }

    void encolar(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (estaVacia()) {
            frente = nuevo;
        } else {
            final->siguiente = nuevo;
        }
        final = nuevo;
        cout << "Elemento " << valor << " agregado a la cola.\n";
    }

    // Método para exponer el frente de manera segura sin romper encapsulamiento
    void recorrer(void (*accion)(int)) const {
        for (Nodo* actual = frente; actual != nullptr; actual = actual->siguiente) {
            accion(actual->dato);
        }
    }
};

class VisualizadorCola {
public:
    static void mostrar(const ColaDinamica& cola) {
        if (cola.estaVacia()) {
            cout << "La cola esta vacia.\n";
            return;
        }
        cout << "\n[FRENTE] -> ";
        cola.recorrer([](int dato) {
            cout << dato << " -> ";
        });
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

    // Mostrar estructura usando la clase VisualizadorCola
    VisualizadorCola::mostrar(miCola);

    return 0;
}