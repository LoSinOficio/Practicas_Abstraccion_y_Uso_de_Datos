#include <iostream>
using namespace std;

class Lista {
private:
    static const int MAX = 10;
    int datos[MAX];
    int cantidad;
public:
    Lista() : cantidad(0) {}

    void insertar(int posicion, int valor) {
        if (cantidad == MAX) { cout << "Lista llena.\n"; return; }
        if (posicion < 0 || posicion > cantidad) {
            cout << "Posicion no valida. Usa posiciones desde 0 hasta " << cantidad << ".\n";
            return;
        }
        for (int i = cantidad; i > posicion; --i) datos[i] = datos[i - 1];
        datos[posicion] = valor;
        ++cantidad;
        cout << "Elemento insertado.\n";
    }
    void eliminar(int posicion) {
        if (posicion < 0 || posicion >= cantidad) { cout << "Posicion no valida.\n"; return; }
        cout << "Eliminado: " << datos[posicion] << '\n';
        for (int i = posicion; i < cantidad - 1; ++i) datos[i] = datos[i + 1];
        --cantidad;
    }
    void mostrar() const {
        if (cantidad == 0) { cout << "Lista vacia.\n"; return; }
        for (int i = 0; i < cantidad; ++i) cout << "[" << i << "]=" << datos[i] << " ";
        cout << '\n';
    }
};

int main() {
    Lista lista;
    int opcion, posicion, valor;
    do {
        cout << "\n=== LISTA ESTATICA ===\n1. Insertar\n2. Eliminar\n3. Mostrar\n0. Salir\nOpcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Posicion (empieza en 0): "; cin >> posicion;
                cout << "Valor: "; cin >> valor;
                lista.insertar(posicion, valor);
                break;
            case 2: cout << "Posicion a eliminar: "; cin >> posicion; lista.eliminar(posicion); break;
            case 3: lista.mostrar(); break;
            case 0: break;
            default: cout << "Opcion no valida.\n";
        }
    } while (opcion != 0);
    return 0;
}
