#include <iostream>
using namespace std;

class Calculadora {
public:
    double sumar(double a, double b) { return a + b; }
    double restar(double a, double b) { return a - b; }
    double multiplicar(double a, double b) { return a * b; }

    bool dividir(double a, double b, double &resultado) {
        if (b == 0) return false;
        resultado = a / b;
        return true;
        
    }
};


int main() {
    Calculadora calc;
    double a, b, resultado;
    int opcion;

    cout << "=== Calculadora basica ===\n";
    cout << "Ingresa el primer numero: ";
    cin >> a;
    cout << "Ingresa el segundo numero: ";
    cin >> b;

    cout << "\n1. Suma\n2. Resta\n3. Multiplicacion\n4. Division\nOpcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1: cout << "Resultado: " << calc.sumar(a, b) << '\n'; break;
        case 2: cout << "Resultado: " << calc.restar(a, b) << '\n'; break;
        case 3: cout << "Resultado: " << calc.multiplicar(a, b) << '\n'; break;
        case 4:
            if (calc.dividir(a, b, resultado)) cout << "Resultado: " << resultado << '\n';
            else cout << "Error: no se puede dividir entre cero.\n";
            break;
        default: cout << "Opcion no valida.\n";
    }
    return 0;
}
