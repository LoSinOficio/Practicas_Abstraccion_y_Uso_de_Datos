#include <iostream>

using namespace std;

class CalculadoraSobrecarga {
public:
    // 1. MÃ©todo sin parÃ¡metros (0 parÃ¡metros)
    void sumar() {
        cout << "Metodo de 0 parametros -> No hay valores para sumar." << endl;
    }

    // 2. MÃ©todo con 2 parÃ¡metros
    void sumar(int a, int b) {
        cout << "Suma de 2 parametros (" << a << " + " << b << ") = " << (a + b) << endl;
    }

    // 3. MÃ©todo con 3 parÃ¡metros
    void sumar(int a, int b, int c) {
        cout << "Suma de 3 parametros (" << a << " + " << b << " + " << c << ") = " << (a + b + c) << endl;
    }
};

int main() {
    // CreaciÃ³n del objeto de la clase
    CalculadoraSobrecarga calc;

    cout << "=== EJERCICIO 4: SOBRECARGA EN POO ===" << endl;
    
    // Probando las variantes de la funciÃ³n
    calc.sumar();         // Llama a la de 0 parÃ¡metros
    calc.sumar(10, 20);   // Llama a la de 2 parÃ¡metros
    calc.sumar(5, 10, 15); // Llama a la de 3 parÃ¡metros

    return 0;
    
}