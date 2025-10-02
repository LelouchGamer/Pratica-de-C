#include <iostream>
#include <string>
using namespace std;

struct Endereco {
    string rua;
    int numero;
    string cidade;
};

struct Pessoa {
    string nome;
    Endereco endereco;
};

int main() {
    Pessoa pessoa = {"Joao Silva", {"Rua das Palmeiras", 123, "Sao Paulo"}};

    cout << "Nome: " << pessoa.nome << endl;
    cout << "Endereco: " << pessoa.endereco.rua << ", " << pessoa.endereco.numero << ", " << pessoa.endereco.cidade << endl;

    return 0;
}

