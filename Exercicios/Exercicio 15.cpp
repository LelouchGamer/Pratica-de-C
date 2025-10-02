#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string rua;
    int numero;
    string cidade;
} Endereco;

int main() {
    Endereco endereco1 = {"Rua dos Girassois", 45, "Rio de Janeiro"};
    Endereco endereco2;

    endereco2 = endereco1;

    cout << "Endereco 2:\n";
    cout << "Rua: " << endereco2.rua << endl;
    cout << "Numero: " << endereco2.numero << endl;
    cout << "Cidade: " << endereco2.cidade << endl;

    return 0;
}

