#include <iostream>

using namespace std;

class BaseCalc {
public:
    virtual int operar(int a, int b) {
        return a + b;
    }
};

class CalcAvanzada : public BaseCalc {
public:
    int multiplicar(int a, int b) {
        int res = 0;
        int signo = 1;

        // Determinar el signo final según la regla de los signos
        if (a < 0) {
            signo *= -1;
            a = -a;
        }
        if (b < 0) {
            signo *= -1;
            b = -b;
        }

        for (int i = 0; i < b; i++) {
            res += a;
        }

        return res * signo;
    }

    int potencia(int base, int exp) {
        if (exp == 0) return 1;

        // Manejo básico de exponentes negativos con enteros
        if (exp < 0) {
            if (base == 1) return 1;
            if (base == -1) return (exp % 2 == 0) ? 1 : -1;
            return 0; // En división entera, cualquier base > 1 con exponente negativo da 0
        }

        int res = 1;
        for (int i = 0; i < exp; i++) {
            res = multiplicar(res, base); // Al soportar negativos en multiplicar, la potencia con base negativa funciona sola
        }
        return res;
    }

    int dividir(int a, int b) {
        if (b == 0) {
            cout << "Error: Division entre cero." << endl;
            return 0;
        }

        int cont = 0;
        int signo = 1;

        // Determinar el signo final para la división
        if (a < 0) {
            signo *= -1;
            a = -a;
        }
        if (b < 0) {
            signo *= -1;
            b = -b;
        }

        while (a >= b) {
            a -= b;
            cont++;
        }

        return cont * signo;
    }
};

int main() {
    CalcAvanzada calc;

    cout << "Multiplicacion (sumas sucesivas) -4 x 3 = " << calc.multiplicar(-4, 3) << endl;
    cout << "Potencia (-2)^3 = " << calc.potencia(-2, 3) << endl;
    cout << "Division (restas sucesivas) -10 / 3 = " << calc.dividir(-10, 3) << endl;

    return 0;
}