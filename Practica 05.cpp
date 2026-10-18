#include <iostream>
using namespace std;

class Calculadora {
public:
    double sumar(double a, double b) { return a + b; }
    double restar(double a, double b) { return a - b; }
    double multiplicar(double a, double b) { return a * b; }
    double dividir(double a, double b) {
        if (b == 0) {
            cout << "Error: division entre cero.\n";
            return 0;
        }
        return a / b;
        
    }
};

// CalculadoraNueva hereda las operaciones de Calculadora.
class CalculadoraNueva : public Calculadora {
public:
    double potencia(double base, int exponente) {
        double resultado = 1;
        int n = exponente < 0 ? -exponente : exponente;
        for (int i = 0; i < n; ++i) resultado *= base;
        if (exponente < 0) {
            if (resultado == 0) {
                cout << "Error: cero no puede elevarse a exponente negativo.\n";
                return 0;
            }
            resultado = 1 / resultado;
        }
        return resultado;
    }
};

int main() {
    CalculadoraNueva calc;
    double a, b;
    int opcion, exponente;

    cout << "=== Calculadora con herencia ===\n";
    cout << "1. Suma\n2. Resta\n3. Multiplicacion\n4. Division\n5. Potencia\nOpcion: ";
    cin >> opcion;

    cout << "Ingresa el primer valor/base: ";
    cin >> a;
    if (opcion == 5) {
        cout << "Ingresa el exponente entero: ";
        cin >> exponente;
        cout << "Resultado: " << calc.potencia(a, exponente) << '\n';
        return 0;
    }

    cout << "Ingresa el segundo valor: ";
    cin >> b;
    switch (opcion) {
        case 1: cout << "Resultado: " << calc.sumar(a, b) << '\n'; break;
        case 2: cout << "Resultado: " << calc.restar(a, b) << '\n'; break;
        case 3: cout << "Resultado: " << calc.multiplicar(a, b) << '\n'; break;
        case 4: cout << "Resultado: " << calc.dividir(a, b) << '\n'; break;
        default: cout << "Opcion no valida.\n";
    }
    return 0;
}
