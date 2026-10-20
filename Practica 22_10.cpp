#include <iostream>
#include <list>

using namespace std;

// 1. Responsabilidad: Lógica de la Lista Dinámica con STL 
class ListaDinamicaSTL {
private:
    list<int> elementos;

public:
    void agregarAlFinal(int valor) {
        elementos.push_back(valor);
    }

    void agregarAlFrente(int valor) {
        elementos.push_front(valor);
    }

    bool estaVacia() const {
        return elementos.empty();
    }

    // Método seguro para obtener una copia y recorrerla sin romper el encapsulamiento
    list<int> obtenerCopia() const {
        return elementos;
    }
};

// 2. Responsabilidad: Visualización e impresión de datos 
class VisualizadorLista {
public:
    static void mostrar(const ListaDinamicaSTL& listaObj) {
        list<int> temp = listaObj.obtenerCopia();
        cout << "--- Lista STL ---" << endl;
        cout << "Elementos de la lista: ";
        for (int v : temp) {
            cout << v << " ";
        }
        cout << endl;
    }
};

int main() {
    ListaDinamicaSTL miLista;

    // Inicialización y llenado de datos
    miLista.agregarAlFinal(10);
    miLista.agregarAlFinal(20);
    miLista.agregarAlFrente(5);

    // Mostrar resultados usando la clase VisualizadorLista
    VisualizadorLista::mostrar(miLista);

    return 0;
}