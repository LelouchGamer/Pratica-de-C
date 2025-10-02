#include <iostream>
#include <string>
using namespace std;

struct Funcionario {
    string nome;
    float salario;
    string departamento;
};

int main() {
    Funcionario funcionario;
    cout << "Tamanho da estrutura Funcionario: " << sizeof(funcionario) << " bytes" << endl;
    return 0;
}

