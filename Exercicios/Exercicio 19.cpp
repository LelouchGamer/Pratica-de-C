#include <iostream>
#include <string>
using namespace std;

struct Carro {
    string marca;
    string modelo;
    int ano;
};

void imprimirCarro(Carro carro) {
    cout << "Marca: " << carro.marca << endl;
    cout << "Modelo: " << carro.modelo << endl;
    cout << "Ano: " << carro.ano << endl;
}

int main() {
    Carro carro = {"Toyota", "Corolla", 2020};
    imprimirCarro(carro);
    return 0;
}

