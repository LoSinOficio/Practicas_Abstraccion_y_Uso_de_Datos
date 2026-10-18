#include <iostream>
using namespace std;

class Pila {
private:
    static const int MAX = 5;
    int datos[MAX];
    int tope;
public:
    Pila() : tope(-1) {}
    bool vacia() const { return tope == -1; }
    bool llena() const { return tope == MAX - 1; }

    void push(int valor) {
        if (llena()) cout << "La pila esta llena.\n";
        else { datos[++tope] = valor; cout << "Elemento agregado.\n"; }
    }
    void pop() {
        if (vacia()) cout << "La pila esta vacia.\n";
        else cout << "Elemento eliminado: " << datos[tope--] << '\n';
    }
    void mostrar() const {
        if (vacia()) { cout << "Pila vacia.\n"; return; }
        cout << "Tope -> ";
        for (int i = tope; i >= 0; --i) cout << datos[i] << " ";
        cout << '\n';
    }
};


int main() {
    Pila pila;
    int opcion, valor;
    do {
        cout << "\n=== PILA ESTATICA ===\n1. Push\n2. Pop\n3. Mostrar\n0. Salir\nOpcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: cout << "Valor: "; cin >> valor; pila.push(valor); break;
            case 2: pila.pop(); break;
            case 3: pila.mostrar(); break;
            case 0: break;
            default: cout << "Opcion no valida.\n";
        }
    } while (opcion != 0);
    return 0;
}
