#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string nome;
    int idade;
    string endereco;
} Cliente;

int main() {
    Cliente cliente = {"Ana Souza", 30, "Rua das Flores, 123"};
    cout << "Dados do Cliente:\n";
    cout << "Nome: " << cliente.nome << endl;
    cout << "Idade: " << cliente.idade << endl;
    cout << "Endereco: " << cliente.endereco << endl;
    return 0;
}
