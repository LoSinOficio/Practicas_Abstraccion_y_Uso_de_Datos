# Caratula

## Practicas de programacion

| Dato | Informacion |
| --- | --- |
| Institucion | [Nombre de la institucion] |
| Asignatura | [Nombre de la asignatura] |
| Estudiante | [Nombre del estudiante] |
| Docente | [Nombre del docente] |
| Fecha | [Fecha de entrega] |

## Indice

- [Practica 01.cpp](#practica-01cpp)
- [Practica 02.cpp](#practica-02cpp)
- [Practica 03.cpp](#practica-03cpp)
- [Practica 04.cpp](#practica-04cpp)
- [Practica 05.cpp](#practica-05cpp)
- [Practica 06.cpp](#practica-06cpp)
- [Practica 07.cpp](#practica-07cpp)
- [Practica 07.1.cpp](#practica-071cpp)
- [Practica 07 POO.java](#practica-07-poojava-contenido-c)
- [Practica 08 POO.java](#practica-08-poojava-contenido-c)
- [Practica 09.cpp](#practica-09cpp)
- [Practica 10.cpp](#practica-10cpp)
- [Practica 11.cpp](#practica-11cpp)
- [Practica 12.cpp](#practica-12cpp)
- [Practica 13.cpp](#practica-13cpp)
- [Practica 14.cpp](#practica-14cpp)
- [Practica 15.cpp](#practica-15cpp)

## Desarrollo de soluciones

Este repositorio contiene los programas de las practicas 01 a 15. El codigo de cada archivo se incluye a continuacion.

> Nota: `Practica 07 POO.java` y `Practica 08 POO.java` tienen extension `.java`, pero su contenido es C++. Se conservan sus nombres originales.

## Practica 01.cpp

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hola mundo" << endl;
    return 0;
}
```

## Practica 02.cpp

```cpp
#include <iostream>

using namespace std;

int sumar(int a, int b) {
    return a + b;
}

int main() {
    int res = sumar(5, 3);
    cout << "La suma es: " << res << endl;
    return 0;
}
```

## Practica 03.cpp

```cpp
#include <iostream>
using namespace std;

class Calculadora {
public:
    double sumar(double a, double b) { return a + b; }
    double restar(double a, double b) { return a - b; }
    double multiplicar(double a, double b) { return a * b; }

    bool dividir(double a, double b, double &resultado) {
        if (b == 0) return false;
        resultado = a / b;
        return true;
    }
};


int main() {
    Calculadora calc;
    double a, b, resultado;
    int opcion;

    cout << "=== Calculadora basica ===\n";
    cout << "Ingresa el primer numero: ";
    cin >> a;
    cout << "Ingresa el segundo numero: ";
    cin >> b;

    cout << "\n1. Suma\n2. Resta\n3. Multiplicacion\n4. Division\nOpcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1: cout << "Resultado: " << calc.sumar(a, b) << '\n'; break;
        case 2: cout << "Resultado: " << calc.restar(a, b) << '\n'; break;
        case 3: cout << "Resultado: " << calc.multiplicar(a, b) << '\n'; break;
        case 4:
            if (calc.dividir(a, b, resultado)) cout << "Resultado: " << resultado << '\n';
            else cout << "Error: no se puede dividir entre cero.\n";
            break;
        default: cout << "Opcion no valida.\n";
    }
    return 0;
}
```

## Practica 04.cpp

```cpp
#include <iostream>

using namespace std;

// Sin parametros
void mostrar() {
    cout << "Sin parametros" << endl;
}

// Con 2 parametros
void mostrar(int a, int b) {
    cout << "Suma 2 parametros: " << a + b << endl;
}

// Con 3 parametros
void mostrar(int a, int b, int c) {
    cout << "Suma 3 parametros: " << a + b + c << endl;
}

int main() {
    mostrar();
    mostrar(2, 3);
    mostrar(1, 2, 3);
    return 0;
    
}
```

## Practica 05.cpp

```cpp
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
```

## Practica 06.cpp

```cpp
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
        for(int i = 0; i < b; i++) {
            res += a;
        }
        return res;
    }

    int potencia(int base, int exp) {
        int res = 1;
        for(int i = 0; i < exp; i++) {
            res = multiplicar(res, base);
        }
        return res;
    }

    int dividir(int a, int b) {
        int cont = 0;
        while(a >= b) {
            a -= b;
            cont++;
        }
        return cont;
    }
};

int main() {
    CalcAvanzada calc;
    cout << "Multiplicacion (sumas sucesivas) 4x3: " << calc.multiplicar(4, 3) << endl;
    cout << "Potencia (multiplicaciones sucesivas) 2^3: " << calc.potencia(2, 3) << endl;
    cout << "Division (restas sucesivas) 10/3: " << calc.dividir(10, 3) << endl;
    return 0;
}
```

## Practica 07.cpp

```cpp
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
```

## Practica 07.1.cpp

```cpp
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
```

## Practica 07 POO.java (contenido C++)

```cpp
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
```

## Practica 08 POO.java (contenido C++)

```cpp
#include <iostream>

using namespace std;

class Estadistica {
public:
    void calcular(int a, int b, int c, int d, int e) {
        int suma = a + b + c + d + e;
        float promedio = suma / 5.0;
        
        int max = a;
        if(b > max) max = b;
        if(c > max) max = c;
        if(d > max) max = d;
        if(e > max) max = e;
        
        int min = a;
        if(b < min) min = b;
        if(c < min) min = c;
        if(d < min) min = d;
        if(e < min) min = e;
        
        cout << "Suma: " << suma << endl;
        cout << "Promedio: " << promedio << endl;
        cout << "Maximo: " << max << endl;
        cout << "Minimo: " << min << endl;
    }
};

int main() {
    Estadistica est;
    est.calcular(10, 20, 30, 40, 50);
    return 0;
}
```

## Practica 09.cpp

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int N = 5;
    double numeros[N], suma = 0, minimo, maximo;

    cout << "Ingresa " << N << " numeros:\n";
    for (int i = 0; i < N; ++i) {
        cout << "Numero " << i + 1 << ": ";
        cin >> numeros[i];
        suma += numeros[i];
    }

    minimo = maximo = numeros[0];
    for (int i = 1; i < N; ++i) {
        if (numeros[i] < minimo) minimo = numeros[i];
        if (numeros[i] > maximo) maximo = numeros[i];
    }

    cout << fixed << setprecision(2);
    cout << "\nSuma: " << suma << '\n';
    cout << "Promedio/media: " << suma / N << '\n';
    cout << "Maximo: " << maximo << '\n';
    cout << "Minimo: " << minimo << '\n';
    return 0;
}
```

## Practica 10.cpp

```cpp
#include <iostream>
using namespace std;

class PromedioPuntero {
    int nums[5];
public:
    void ejecutar() {
        int *p = nums;
        int suma = 0;
        cout << "Ingresa 5 numeros:\n";
        for(int i = 0; i < 5; i++) {
            cin >> *(p + i);
            suma += *(p + i);
        }
        int maxVal = *p, minVal = *p;
        for(int i = 0; i < 5; i++) {
            if(*(p + i) > maxVal) maxVal = *(p + i);
            if(*(p + i) < minVal) minVal = *(p + i);
        }
        cout << "Suma: " << suma << " | Promedio: " << (suma / 5.0) 
             << " | Max: " << maxVal << " | Min: " << minVal << "\n";
    }
};

int main() {
    PromedioPuntero obj;
    obj.ejecutar();
    return 0;
}
```

## Practica 11.cpp

```cpp
#include <iostream>
using namespace std;

class Matrices {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{2, 0}, {1, 2}};
public:
    void resolver() {
        int c = 3;
        cout << "--- Matriz A * Constante (" << c << ") ---\n";
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) cout << A[i][j] * c << " ";
            cout << "\n";
        }
        cout << "--- Multiplicacion A * B ---\n";
        int R[2][2] = {0};
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                for(int k = 0; k < 2; k++) R[i][j] += A[i][k] * B[k][j];
        
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) cout << R[i][j] << " ";
            cout << "\n";
        }
    }
};

int main() {
    Matrices m;
    m.resolver();
    return 0;
}
```

## Practica 12.cpp

```cpp
#include <iostream>
#include <string>
using namespace std;

class Coche { public: string marca; };
class Persona { public: string nombre; Coche autoPersona; };

class ListaPersonas {
public:
    void mostrar() {
        Persona lista[2] = {{"Ana", {"Toyota"}}, {"Luis", {"Nissan"}}};
        for(int i = 0; i < 2; i++) {
            cout << lista[i].nombre << " tiene un auto " << lista[i].autoPersona.marca << "\n";
        }
    }
};

int main() {
    ListaPersonas lp;
    lp.mostrar();
    return 0;
}
```

## Practica 13.cpp

```cpp
#include <iostream>
#include <string>
using namespace std;

class Persona { public: string nombre; };

class PunteroLista {
public:
    void acceder() {
        Persona lista[2] = {{"Carlos"}, {"Sofia"}};
        Persona *ptr = lista;
        for(int i = 0; i < 2; i++) {
            cout << "Persona " << i + 1 << ": " << (ptr + i)->nombre << "\n";
        }
    }
};

int main() {
    PunteroLista pl;
    pl.acceder();
    return 0;
}
```

## Practica 14.cpp

```cpp
#include <iostream>
using namespace std;

class RecursividadCalc {
public:
    int factorial(int n) {
        return (n <= 1) ? 1 : n * factorial(n - 1);
    }
    int fibonacci(int n) {
        return (n <= 1) ? n : fibonacci(n - 1) + fibonacci(n - 2);
    }
    // Multiplicación por sumas sucesivas recursivas
    int sumaSucesiva(int a, int b) {
        if(b == 0) return 0;
        return a + sumaSucesiva(a, b - 1);
    }
};

int main() {
    RecursividadCalc rc;
    cout << "Factorial de 5: " << rc.factorial(5) << "\n";
    cout << "Fibonacci de 6: " << rc.fibonacci(6) << "\n";
    cout << "Multiplicacion (4 * 3) por sumas sucesivas: " << rc.sumaSucesiva(4, 3) << "\n";
    return 0;
}
```

## Practica 15.cpp

```cpp
#include <iostream>
using namespace std;

class Fractales {
public:
    void polvoCantor(int nivel) {
        if(nivel == 0) return;
        cout << "Polvo de Cantor - Nivel " << nivel << "\n";
        polvoCantor(nivel - 1);
    }
    void sierpinski(int fila, int maxFilas) {
        if(fila > maxFilas) return;
        for(int j = 0; j <= fila; j++) {
            if((fila & j) == 0) cout << "* ";
            else cout << "  ";
        }
        cout << "\n";
        sierpinski(fila + 1, maxFilas);
    }
};

int main() {
    Fractales f;
    cout << "--- Polvo de Cantor ---\n";
    f.polvoCantor(3);
    cout << "\n--- Triangulo de Sierpinski ---\n";
    f.sierpinski(0, 4);
    return 0;
}
```
