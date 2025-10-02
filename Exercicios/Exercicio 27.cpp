#include <iostream>
#include <string>
using namespace std;

struct Contato {
    string nome;
    string telefone;
    string email;
};

int main() {
    Contato contato1 = {"Joao Pereira", "1234-5678", "joao@email.com"};
    Contato contato2;

    contato2 = contato1;

    cout << "Contato 2:\n";
    cout << "Nome: " << contato2.nome << endl;
    cout << "Telefone: " << contato2.telefone << endl;
    cout << "Email: " << contato2.email << endl;

    return 0;
}

