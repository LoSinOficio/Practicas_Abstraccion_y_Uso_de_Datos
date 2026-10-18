#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
void burbuja(vector<T>& datos) {
    for (size_t i = 0; i < datos.size(); ++i) {
        bool huboCambio = false;
        for (size_t j = 0; j + 1 < datos.size() - i; ++j) {
            if (datos[j + 1] < datos[j]) {
                T temporal = datos[j];
                datos[j] = datos[j + 1];
                datos[j + 1] = temporal;
                huboCambio = true;
            }
        }
        if (!huboCambio) break;
    }
}

struct Auto {
    string marca;
    int anio;
    double precio;
    bool operator<(const Auto& otro) const {
        if (marca != otro.marca) return marca < otro.marca;
        return anio < otro.anio;
    }
};

template <typename T>
void mostrar(const vector<T>& datos) {
    for (const auto& elemento : datos) cout << elemento << " ";
    cout << '\n';
}

ostream& operator<<(ostream& salida, const Auto& a) {
    salida << "[Marca: " << a.marca << ", anio: " << a.anio
           << ", precio: " << a.precio << "]";
    return salida;
}

int main() {
    vector<int> enteros = {8, 3, 9, 1, 5};
    vector<char> caracteres = {'z', 'a', 'm', 'b', 'c'};
    vector<Auto> autos = {
        {"Toyota", 2018, 180000},
        {"Nissan", 2020, 210000},
        {"Chevrolet", 2016, 150000},
        {"Audi", 2022, 450000}
    };

    burbuja(enteros);
    burbuja(caracteres);
    burbuja(autos);

    cout << "Enteros ordenados: ";
    mostrar(enteros);
    cout << "Caracteres ordenados: ";
    mostrar(caracteres);
    cout << "Autos ordenados por marca y despues anio:\n";
    mostrar(autos);
    return 0;
}


/*#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definición de la estructura Auto
struct Auto {
    string marca;
    int anio;
    double precio;

    // Sobrecarga del operador < para comparar autos por marca y año
    bool operator<(const Auto& otro) const {
        if (marca != otro.marca) return marca < otro.marca;
        return anio < otro.anio;
    }
};

// Sobrecarga del operador << para imprimir objetos de tipo Auto fácilmente
ostream& operator<<(ostream& salida, const Auto& a) {
    salida << "[Marca: " << a.marca << ", anio: " << a.anio
           << ", precio: " << a.precio << "]";
    return salida;
}

// Clase orientada a objetos para manejar el ordenamiento y visualización
class OrdenadorBurbuja {
public:
    // Método genérico para ordenar cualquier tipo de vector usando burbuja
    template <typename T>
    void ordenar(vector<T>& datos) {
        for (size_t i = 0; i < datos.size(); ++i) {
            bool huboCambio = false;
            for (size_t j = 0; j + 1 < datos.size() - i; ++j) {
                if (datos[j + 1] < datos[j]) {
                    T temporal = datos[j];
                    datos[j] = datos[j + 1];
                    datos[j + 1] = temporal;
                    huboCambio = true;
                }
            }
            if (!huboCambio) break;
        }
    }

    // Método genérico para mostrar los elementos del vector
    template <typename T>
    void mostrar(const vector<T>& datos) {
        for (const auto& elemento : datos) {
            cout << elemento << " ";
        }
        cout << '\n';
    }
};

int main() {
    // Vectores de prueba
    vector<int> enteros = {8, 3, 9, 1, 5};
    vector<char> caracteres = {'z', 'a', 'm', 'b', 'c'};
    vector<Auto> autos = {
        {"Toyota", 2018, 180000},
        {"Nissan", 2020, 210000},
        {"Chevrolet", 2016, 150000},
        {"Audi", 2022, 450000}
    };

    // Creación del objeto de la clase OrdenadorBurbuja
    OrdenadorBurbuja ordenador;

    // Aplicar el método de ordenamiento a través del objeto
    ordenador.ordenar(enteros);
    ordenador.ordenar(caracteres);
    ordenador.ordenar(autos);

    // Mostrar resultados usando los métodos del objeto
    cout << "Enteros ordenados: ";
    ordenador.mostrar(enteros);
    
    cout << "Caracteres ordenados: ";
    ordenador.mostrar(caracteres);
    
    cout << "Autos ordenados por marca y despues anio:\n";
    ordenador.mostrar(autos);

    return 0;
}*/