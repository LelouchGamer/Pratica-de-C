#include <iostream>
#include <string>
using namespace std;

struct Funcionario {
    string nome;
    int idade;
    float salario;
    string departamento;
};

void cadastrarFuncionario(Funcionario& funcionario) {
    cout << "Digite o nome do funcionario: ";
    getline(cin, funcionario.nome);

    cout << "Digite a idade do funcionario: ";
    cin >> funcionario.idade;

    cout << "Digite o salario do funcionario: ";
    cin >> funcionario.salario;
    cin.ignore(); // Limpar o buffer do teclado

    cout << "Digite o departamento do funcionario: ";
    getline(cin, funcionario.departamento);
}

void imprimirFuncionario(const Funcionario& funcionario) {
    cout << "\nDados do Funcionario:\n";
    cout << "Nome: " << funcionario.nome << endl;
    cout << "Idade: " << funcionario.idade << endl;
    cout << "Salario: R$ " << funcionario.salario << endl;
    cout << "Departamento: " << funcionario.departamento << endl;
}

int main() {
    int n;

    cout << "Quantos funcionarios deseja cadastrar? ";
    cin >> n;
    cin.ignore(); // Limpar o buffer do teclado após o cin

    Funcionario funcionarios[n];

    for (int i = 0; i < n; i++) {
        cout << "\nCadastro do Funcionario " << i + 1 << ":\n";
        cadastrarFuncionario(funcionarios[i]);
    }

    for (int i = 0; i < n; i++) {
        imprimirFuncionario(funcionarios[i]);
    }

    return 0;
}

