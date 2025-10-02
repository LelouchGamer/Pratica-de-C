#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string nome;
    string disciplina;
    float salario;
} Professor;

int main() {
    Professor professor = {"Maria Santos", "Matematica", 3500.00};

    cout << "Nome: " << professor.nome << endl;
    cout << "Disciplina: " << professor.disciplina << endl;
    cout << "Salario: R$ " << professor.salario << endl;

    return 0;
}

