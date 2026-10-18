#include <iostream>

using namespace std;

class Operaciones {
public:
    int sumar(int a, int b) {
        return a + b;
    }
};

int main() {
    Operaciones op;
    cout << "La suma es: " << op.sumar(5, 3) << endl;
    return 0;
}