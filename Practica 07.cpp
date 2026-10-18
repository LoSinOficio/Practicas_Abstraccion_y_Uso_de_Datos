#include <iostream>
#include <string>

using namespace std;

struct AutoData {
    float precio;
    int anio;
};

struct PersonaData {
    string nombre, ap, am;
    char genero;
    int edad;
    
};

int main() {
    AutoData a = {150000.50, 2022};
    PersonaData p = {"Juan", "Perez", "Gomez", 'M', 20};

    cout << "Auto - Precio: " << a.precio << ", Anio: " << a.anio << endl;
    cout << "Persona - Nombre: " << p.nombre << " " << p.ap << " " << p.am << endl;
    return 0;
}
