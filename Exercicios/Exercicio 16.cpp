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

    cout << "Titulo: " << filme.titulo << endl;
    cout << "Diretor: " << filme.diretor << endl;
    cout << "Ano de Lancamento: " << filme.anoLancamento << endl;

    return 0;
}

