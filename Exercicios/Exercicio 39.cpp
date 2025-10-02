#include <iostream>
#include <string>
using namespace std;

struct Produto {
    string nome;
    int codigo;
    float preco;
};

int main() {
    Produto produto1 = {"Camiseta", 101, 39.90};
    Produto produto2;

    produto2 = produto1;

    cout << "Produto 2:\n";
    cout << "Nome: " << produto2.nome << endl;
    cout << "Codigo: " << produto2.codigo << endl;
    cout << "Preco: R$ " << produto2.preco << endl;

    return 0;
}

