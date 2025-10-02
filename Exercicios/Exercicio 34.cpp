#include <iostream>
using namespace std;

union Valor {
    double d;
    char c;
};

int main() {
    Valor valor;

    valor.d = 3.14;
    cout << "Valor armazenado como double: " << valor.d << endl;

    valor.c = 'A';
    cout << "Valor armazenado como char: " << valor.c << endl;

    return 0;
}

