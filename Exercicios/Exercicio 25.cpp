#include <iostream>
#include <string>
using namespace std;

struct Aluno {
    string nome;
    int matricula;
    float nota;
};

int main() {
    Aluno aluno = {"Carlos Oliveira", 12345, 8.7};

    cout << "Nome: " << aluno.nome << endl;
    cout << "Matricula: " << aluno.matricula << endl;
    cout << "Nota: " << aluno.nota << endl;

    return 0;
}

