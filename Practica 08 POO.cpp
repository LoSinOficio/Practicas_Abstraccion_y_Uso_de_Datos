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
