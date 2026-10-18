#include <iostream>
#include <string>

using namespace std;

// Estructura auto-referenciada
struct Persona {
    string nombre;
    int edad;
    
    // Puntero que apunta a otra variable del mismo tipo (Persona)
    Persona* siguientePersona; 

    // Constructor para inicializar fácilmente
    Persona(string n, int e) {
        nombre = n;
        edad = e;
        siguientePersona = nullptr; // Inicialmente no apunta a nadie
    }
};

// Clase que administra la relación
class GestorPersonas {
public:
    void mostrarRelacion(Persona& p1, Persona& p2) {
        // Conectamos la persona 1 con la persona 2 de manera indirecta
        p1.siguientePersona = &p2;

        cout << "=== EJERCICIO 1: PUNTERO AL MISMO TIPO DE DATO ===" << endl;
        cout << "Persona Principal: " << p1.nombre << " (" << p1.edad << " anos)" << endl;
        
        // Accedemos a la segunda persona usando el puntero de la primera
        cout << "Vinculada (via puntero): " << p1.siguientePersona->nombre 
             << " (" << p1.siguientePersona->edad << " anos)" << endl;
    }
};

int main() {
    // Creamos dos objetos de tipo Persona
    Persona p1("Erick", 21);
    Persona p2("Sofia", 20);

    GestorPersonas gestor;
    gestor.mostrarRelacion(p1, p2);

    return 0;
}