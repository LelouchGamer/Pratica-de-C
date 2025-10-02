#include <iostream>
#include <string>
using namespace std;

struct Filme {
    string titulo;
    string diretor;
    int anoLancamento;
};

int main() {
    Filme filme = {"Matrix", "Lana e Lilly Wachowski", 1999};
    Filme* ptrFilme = &filme;

    cout << "Titulo: " << ptrFilme->titulo << endl;
    cout << "Diretor: " << ptrFilme->diretor << endl;
    cout << "Ano de Lancamento: " << ptrFilme->anoLancamento << endl;

    return 0;
}

