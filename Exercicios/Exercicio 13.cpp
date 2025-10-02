#include <iostream>
#include <string>
using namespace std;

struct Funcionario {
    string nome;
    float salario;
    string departamento;
};

int main() {
    
    Funcionario funcionario = {"Joao Silva", 3500.50, "Recursos Humanos"};

    cout << "Dados do Funcionario:\n";
    cout << "Nome: " << funcionario.nome << endl;
    cout << "Salario: R$ " << funcionario.salario << endl;
    cout << "Departamento: " << funcionario.departamento << endl;

    return 0;
}
