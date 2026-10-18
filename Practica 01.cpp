#include <iostream>

using namespace std;

// Definición de la clase
class Mensaje {
public:
    // Método que imprime el texto
    void saludar() {
        cout << "Hola mundo" << endl;
    }
};

int main() {
    // 1. Creamos el objeto de la clase Mensaje
    Mensaje miObjeto;

    // 2. Llamamos al método a través del objeto
    miObjeto.saludar();

    return 0;
}