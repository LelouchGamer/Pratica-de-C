#include <iostream>
#include <string>
using namespace std;

struct Cliente {
    string nome;
    int idade;
    string endereco;
};

int main() {
    Cliente cliente = {"Ana Silva", 28, "Rua das Flores, 123"};

    cout << "Nome: " << cliente.nome << endl;
    cout << "Idade: " << cliente.idade << endl;
    cout << "Endereco: " << cliente.endereco << endl;

    return 0;
}

