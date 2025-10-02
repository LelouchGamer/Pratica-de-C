#include <iostream>
using namespace std;

union Valor {
    char c;
    int i;
};

int main() {
    Valor valor;
    
    valor.c = 'A';
    cout << "Valor armazenado como char: " << valor.c << endl;

    valor.i = 123;
    cout << "Valor armazenado como inteiro: " << valor.i << endl;

    return 0;
}

