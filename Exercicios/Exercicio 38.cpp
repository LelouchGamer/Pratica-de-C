#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string nome;
    string telefone;
    string email;
} Contato;

int main() {
    Contato contato = {"Joao Silva", "1234-5678", "joao.silva@email.com"};

    cout << "Nome: " << contato.nome << endl;
    cout << "Telefone: " << contato.telefone << endl;
    cout << "Email: " << contato.email << endl;

    return 0;
}

