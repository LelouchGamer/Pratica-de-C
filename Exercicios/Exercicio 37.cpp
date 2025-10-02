#include <iostream>
#include <string>
using namespace std;

struct Cliente {
    string nome;
    int idade;
    string endereco;
};

int main() {
    Cliente cliente = {"Maria Souza", 35, "Rua das Acacias, 456"};

    cout << "Nome: " << cliente.nome << endl;
    cout << "Idade: " << cliente.idade << endl;
    cout << "Endereco: " << cliente.endereco << endl;

    return 0;
}

