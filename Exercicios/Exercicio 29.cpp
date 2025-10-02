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
    Cliente* ptrCliente = &cliente;

    cout << "Nome: " << ptrCliente->nome << endl;
    cout << "Idade: " << ptrCliente->idade << endl;
    cout << "Endereco: " << ptrCliente->endereco << endl;

    return 0;
}

