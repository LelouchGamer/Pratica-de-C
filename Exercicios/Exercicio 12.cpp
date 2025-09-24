#include <iostream>
#include <string>
using namespace std;

struct Aluno {
    string nome;
    int matricula;
    float nota;
};

void cadastrarAluno(Aluno& aluno) {
    cout << "Digite o nome do aluno: ";
    getline(cin, aluno.nome);  

    cout << "Digite a matricula do aluno: ";
    cin >> aluno.matricula;

    cout << "Digite a nota do aluno: ";
    cin >> aluno.nota;
    cin.ignore();  
}

void imprimirAluno(const Aluno& aluno) {
    cout << "\n--- Dados do Aluno ---\n";
    cout << "Nome: " << aluno.nome << endl;
    cout << "Matricula: " << aluno.matricula << endl;
    cout << "Nota: " << aluno.nota << endl;
}

int main() {
    int n;

    cout << "Quantos alunos voce deseja cadastrar? ";
    cin >> n;
    cin.ignore();  

    Aluno alunos[n];

    for (int i = 0; i < n; i++) {
        cout << "\nCadastro do Aluno " << i + 1 << ":\n";
        cadastrarAluno(alunos[i]);
    }

    for (int i = 0; i < n; i++) {
        imprimirAluno(alunos[i]);
    }

    return 0;
}
