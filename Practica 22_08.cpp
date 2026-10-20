#include <iostream>
#include <stack>

using namespace std;

// 1. Responsabilidad: Lógica de la Pila Dinámica con STL 
class PilaDinamicaSTL {
private:
    stack<int> pila;

public:
    void apilar(int valor) {
        pila.push(valor);
        cout << "Elemento " << valor << " apilado en la cima.\n";
    }

    bool estaVacia() const {
        return pila.empty();
    }

    // Método seguro para obtener una copia y recorrerla sin romper el encapsulamiento
    stack<int> obtenerCopia() const {
        return pila;
    }
};

class VisualizadorPila {
public:
    static void mostrar(const PilaDinamicaSTL& pilaObj) {
        stack<int> temp = pilaObj.obtenerCopia();
        if (temp.empty()) {
            cout << "La pila esta vacia.\n";
            return;
        }
        cout << "\n[CIMA] -> ";
        while (!temp.empty()) {
            cout << temp.top() << " -> ";
            temp.pop();
        }
        cout << "[BASE]\n";
    }
};

int main() {
    cout << "=== EJERCICIO 8: PILA DINAMICA CON LIBRERIA DEL IDE / STL (POO) ===" << endl;
    
    PilaDinamicaSTL miPila;

    // Inserción de elementos de prueba
    miPila.apilar(10);
    miPila.apilar(20);
    miPila.apilar(30);

    // Mostrar estructura usando la clase VisualizadorPila
    VisualizadorPila::mostrar(miPila);

    return 0;
}