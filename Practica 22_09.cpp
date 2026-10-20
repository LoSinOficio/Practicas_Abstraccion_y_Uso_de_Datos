#include <iostream>
#include <queue>

using namespace std;

// 1. Responsabilidad: Lógica de la Cola Dinámica con STL 
class ColaDinamicaSTL {
private:
    queue<int> cola;

public:
    void encolar(int valor) {
        cola.push(valor);
        cout << "Elemento agregado.\n";
    }

    bool estaVacia() const {
        return cola.empty();
    }

    int obtenerFrente() const {
        return cola.front();
    }

    void desencolar() {
        cola.pop();
    }

    // Método seguro para obtener una copia y recorrerla sin romper el encapsulamiento
    queue<int> obtenerCopia() const {
        return cola;
    }
};

class MenuCola {
public:
    static void ejecutar() {
        ColaDinamicaSTL miCola;
        int opcion, valor;

        do {
            cout << "\n=== COLA DINAMICA (POO) ===\n";
            cout << "1. Encolar (push)\n2. Desencolar (pop)\n3. Consultar frente\n4. Mostrar cola\n0. Salir\nOpcion: ";
            cin >> opcion;

            switch (opcion) {
                case 1:
                    cout << "Valor: ";
                    cin >> valor;
                    miCola.encolar(valor);
                    break;
                case 2:
                    if (miCola.estaVacia()) {
                        cout << "La cola esta vacia.\n";
                    } else { 
                        cout << "Elemento eliminado: " << miCola.obtenerFrente() << '\n'; 
                        miCola.desencolar(); 
                    }
                    break;
                case 3:
                    if (miCola.estaVacia()) {
                        cout << "La cola esta vacia.\n";
                    } else {
                        cout << "Frente de la cola: " << miCola.obtenerFrente() << '\n';
                    }
                    break;
                case 4: {
                    if (miCola.estaVacia()) { 
                        cout << "Cola vacia.\n"; 
                        break; 
                    }
                    queue<int> copia = miCola.obtenerCopia();
                    cout << "Frente -> ";
                    while (!copia.empty()) { 
                        cout << copia.front() << " "; 
                        copia.pop(); 
                    }
                    cout << "<- Final\n";
                    break;
                }
                case 0:
                    cout << "Saliendo del programa...\n";
                    break;
                default:
                    cout << "Opcion no valida.\n";
            }
        } while (opcion != 0);
    }
};

int main() {
    MenuCola::ejecutar();
    return 0;
}