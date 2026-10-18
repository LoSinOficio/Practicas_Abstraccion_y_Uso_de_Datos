#include <iostream>
#include <stack>

using namespace std;

// Clase orientada a objetos que encapsula la Pila basada en STL
class PilaDinamicaSTL {
private:
    stack<int> pila; // Contenedor dinámico de la librería estándar

public:
    // Método para apilar un elemento (Push)
    void apilar(int valor) {
        pila.push(valor);
        cout << "Elemento " << valor << " apilado en la cima.\n";
    }

    // Método para mostrar los elementos de la pila desde la cima hasta la base
    void mostrar() {
        if (pila.empty()) {
            cout << "La pila esta vacia.\n";
            return;
        }

        // Se utiliza una pila auxiliar temporal para no perder los datos originales al recorrerlos
        stack<int> temp = pila;
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

    // Mostrar estructura
    miPila.mostrar();

    return 0;
}