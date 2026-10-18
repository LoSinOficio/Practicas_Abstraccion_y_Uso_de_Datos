#include <iostream>

using namespace std;

// Definición de la clase para manejar las matrices por POO
class OperacionesMatriciales {
private:
    int filasA, colA, filasB, colB;
    int A[100][100];
    int B[100][100];
    int C[100][100]; // Matriz resultado A * B
    int D[100][100]; // Matriz resultado A * constante
    int constante;

public:
    // Método para configurar dimensiones y validar la regla matemática
    void configurarDimensiones() {
        cout << "=== PRACTICA 11: MATRICES CON FILAS Y COLUMNAS LIBRES (POO) ===" << endl;

        cout << "\n--- Dimensiones de la Matriz A ---" << endl;
        cout << "Ingrese el numero de filas de A: ";
        cin >> filasA;
        cout << "Ingrese el numero de columnas de A: ";
        cin >> colA;

        cout << "\n--- Dimensiones de la Matriz B ---" << endl;
        cout << "Ingrese el numero de filas de B: ";
        cin >> filasB;
        cout << "Ingrese el numero de columnas de B: ";
        cin >> colB;

        // Validación matemática obligatoria para la multiplicación matricial A * B
        if (colA != filasB) {
            cout << "\n[AVISO]: Para poder multiplicar A * B, las columnas de A (" << colA 
                 << ") deben ser iguales a las filas de B (" << filasB << ")." << endl;
            cout << "Se ajustaran automaticamente las filas de B para que sea igual a las columnas de A (" << colA << ").\n";
            filasB = colA; 
        }
    }

    // Método para ingresar los valores de las matrices y la constante
    void ingresarDatos() {
        cout << "\n--- INGRESO DE VALORES PARA MATRIZ A (" << filasA << "x" << colA << ") ---" << endl;
        for (int i = 0; i < filasA; i++) {
            for (int j = 0; j < colA; j++) {
                cout << "A[" << i << "][" << j << "]: ";
                cin >> A[i][j];
            }
        }

        cout << "\n--- INGRESO DE VALORES PARA MATRIZ B (" << filasB << "x" << colB << ") ---" << endl;
        for (int i = 0; i < filasB; i++) {
            for (int j = 0; j < colB; j++) {
                cout << "B[" << i << "][" << j << "]: ";
                cin >> B[i][j];
            }
        }

        cout << "\nIngrese la constante para multiplicar la Matriz A: ";
        cin >> constante;
    }

    // Método para realizar los cálculos matemáticos
    void calcular() {
        // 1. Multiplicación de Matriz A por una constante
        for (int i = 0; i < filasA; i++) {
            for (int j = 0; j < colA; j++) {
                D[i][j] = A[i][j] * constante;
            }
        }

        // 2. Multiplicación de Matrices A * B
        for (int i = 0; i < filasA; i++) {
            for (int j = 0; j < colB; j++) {
                C[i][j] = 0;
                for (int k = 0; k < colA; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }

    // Método para mostrar los resultados en pantalla
    void mostrarResultados() {
        cout << "\n=======================================================" << endl;
        cout << "RESULTADO 1: Matriz A * Constante (" << constante << ")" << endl;
        for (int i = 0; i < filasA; i++) {
            for (int j = 0; j < colA; j++) {
                cout << D[i][j] << "\t";
            }
            cout << endl;
        }

        cout << "\nRESULTADO 2: Multiplicacion de Matrices A * B (" << filasA << "x" << colB << ")" << endl;
        for (int i = 0; i < filasA; i++) {
            for (int j = 0; j < colB; j++) {
                cout << C[i][j] << "\t";
            }
            cout << endl;
        }
        cout << "=======================================================" << endl;
    }
};

int main() {
    // Creación del objeto de la clase (Instanciación)
    OperacionesMatriciales matrizObj;

    // Invocación de los métodos de la clase a través del objeto
    matrizObj.configurarDimensiones();
    matrizObj.ingresarDatos();
    matrizObj.calcular();
    matrizObj.mostrarResultados();

    return 0;
    
}