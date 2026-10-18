#include <iostream>
#include <string>

using namespace std;

// Definición del Tipo de Dato Abstracto (ADT) CuentaBancaria
class CuentaBancaria {
private:
    // Los datos están ocultos y protegidos (Encapsulamiento)
    string titular;
    double saldo;

public:
    // Constructor para inicializar el ADT
    CuentaBancaria(string nombreTitular, double saldoInicial) {
        titular = nombreTitular;
        if (saldoInicial >= 0) {
            saldo = saldoInicial;
        } else {
            saldo = 0;
        }
    }

    // Operación permitida 1: Depositar dinero
    void depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
            cout << "Deposito exitoso de: $" << monto << endl;
        } else {
            cout << "Monto no valido.\n";
        }
    }

    // Operación permitida 2: Consultar saldo actual
    void consultarSaldo() {
        cout << "Titular: " << titular << " | Saldo actual: $" << saldo << endl;
    }
};

int main() {
    cout << "=== EJERCICIO 2: TIPO DE DATO ABSTRACTO (ADT) ===" << endl;

    // Instanciamos el ADT
    CuentaBancaria cuenta1("Erick Cruz", 5000.0);

    // Interactuamos exclusivamente a través de la interfaz pública
    cuenta1.consultarSaldo();
    
    cuenta1.depositar(1500.0);
    
    cuenta1.consultarSaldo();

    // Nota: Intentar acceder directamente a 'cuenta1.saldo' marcaría un error de compilación 
    // porque los datos están protegidos (Principio del ADT).

    return 0;
    
}