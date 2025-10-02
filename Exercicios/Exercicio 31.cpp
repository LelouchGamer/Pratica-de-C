#include <iostream>
#include <string>
using namespace std;

struct Funcionario {
    string nome;
    float salario;
    string departamento;
};

void imprimirFuncionario(Funcionario funcionario) {
    cout << "Nome: " << funcionario.nome << endl;
    cout << "Salario: R$ " << funcionario.salario << endl;
    cout << "Departamento: " << funcionario.departamento << endl;
}

int main() {
    Funcionario funcionario = {"Carlos Lima", 4500.50, "Financeiro"};
    imprimirFuncionario(funcionario);

    return 0;
}

