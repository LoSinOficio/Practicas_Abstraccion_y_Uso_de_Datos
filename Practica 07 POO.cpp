#include <iostream>
#include <string>

using namespace std;

class AutoClase {
public:
    float precio;
    int anio;
};

class PersonaClase {
public:
    string nombre, ap, am;
    char genero;
    int edad;
};

int main() {
    AutoClase a;
    a.precio = 150000.50;
    a.anio = 2022;
    
    PersonaClase p;
    p.nombre = "Juan";
    p.ap = "Perez";
    p.am = "Gomez";
    p.genero = 'M';
    p.edad = 20;
    
    cout << "Auto Clase - Precio: " << a.precio << ", Anio: " << a.anio << endl;
    cout << "Persona Clase - Nombre: " << p.nombre << " " << p.ap << " " << p.am << endl;
    
    return 0;
}
