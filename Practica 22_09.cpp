#include <iostream>
#include <queue>

using namespace std;

// Definición de la clase con un nombre más sencillo
class Cola {
private:
    queue<int> cola; // Cola dinámica de la biblioteca estándar de C++

public:
    // Método para mostrar el menú y controlar las operaciones
    void ejecutarMenu() {
        int opcion, valor;

        do {
            cout << "\n=== COLA DINAMICA (POO) ===\n";
            cout << "1. Encolar (push)\n2. Desencolar (pop)\n3. Consultar frente\n4. Mostrar cola\n0. Salir\nOpcion: ";
            cin >> opcion;

            switch (opcion) {
                case 1:
                    cout << "Valor: ";
                    cin >> valor;
                    cola.push(valor);
                    cout << "Elemento agregado.\n";
                    break;
                case 2:
                    if (cola.empty()) {
                        cout << "La cola esta vacia.\n";
                    } else { 
                        cout << "Elemento eliminado: " << cola.front() << '\n'; 
                        cola.pop(); 
                    }
                    break;
                case 3:
                    if (cola.empty()) {
                        cout << "La cola esta vacia.\n";
                    } else {
                        cout << "Frente de la cola: " << cola.front() << '\n';
                    }
                    break;
                case 4: {
                    if (cola.empty()) { 
                        cout << "Cola vacia.\n"; 
                        break; 
                    }
                    // Se usa una copia temporal para mostrar los elementos sin alterar la cola original
                    queue<int> copia = cola;
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
    // 1. Creación del objeto usando la clase Cola
    Cola miCola;

    // 2. Invocación del método principal a través del objeto
    miCola.ejecutarMenu();

    return 0;
}