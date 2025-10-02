#include <iostream>
using namespace std;

enum Estacoes {
    Primavera = 1,
    Verao,
    Outono,
    Inverno
};

int main() {
    for (int i = Primavera; i <= Inverno; i++) {
        cout << "Estacao " << i << ": ";
        switch(i) {
            case Primavera:
                cout << "Primavera" << endl;
                break;
            case Verao:
                cout << "Verao" << endl;
                break;
            case Outono:
                cout << "Outono" << endl;
                break;
            case Inverno:
                cout << "Inverno" << endl;
                break;
        }
    }
    return 0;
}

