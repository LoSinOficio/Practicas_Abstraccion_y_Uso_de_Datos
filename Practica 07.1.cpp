#include <iostream>
#include <string>
using namespace std;

struct Auto {
    string marca;
    double precio;
    int anio;
};

class Persona {
public:
    string nombre;
    string apellidoPaterno;
    string apellidoMaterno;
    string genero;
    int edad;
};


int main() {
    cout << "=== Tamano de tipos de datos (bytes) ===\n";
    cout << "char: " << sizeof(char) << '\n';
    cout << "bool: " << sizeof(bool) << '\n';
    cout << "short: " << sizeof(short) << '\n';
    cout << "int: " << sizeof(int) << '\n';
    cout << "long: " << sizeof(long) << '\n';
    cout << "long long: " << sizeof(long long) << '\n';
    cout << "float: " << sizeof(float) << '\n';
    cout << "double: " << sizeof(double) << '\n';
    cout << "long double: " << sizeof(long double) << '\n';
    cout << "string (objeto): " << sizeof(string) << '\n';
    cout << "Auto (estructura): " << sizeof(Auto) << '\n';
    cout << "Persona (clase): " << sizeof(Persona) << '\n';
    cout << "\nNota: los tamanos pueden variar segun el compilador y la arquitectura.\n";
    cout << "sizeof(string) mide el objeto string, no la memoria dinamica de su texto.\n";
    return 0;
}
