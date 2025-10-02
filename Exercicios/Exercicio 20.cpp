#include <iostream>
#include <string>
using namespace std;

struct Livro {
    string titulo;
    string autor;
    int anoPublicacao;
};

int main() {
    Livro livros[3] = {
        {"O Senhor dos Aneis", "J.R.R. Tolkien", 1954},
        {"Harry Potter", "J.K. Rowling", 1998},
        {"The Witcher", "Andrzej Sapkowski", 1992}
    };

    for (int i = 0; i < 3; i++) {
        cout << "Livro " << i + 1 << ":\n";
        cout << "Titulo: " << livros[i].titulo << endl;
        cout << "Autor: " << livros[i].autor << endl;
        cout << "Ano de Publicacao: " << livros[i].anoPublicacao << endl;
        cout << endl;
    }

    return 0;
}

