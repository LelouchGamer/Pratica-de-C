#include <iostream>
#include <string>
using namespace std;

struct Livro {
    string titulo;
    string autor;
    int anoPublicacao;
};

void cadastrarLivro(Livro& livro) {
    cout << "Digite o titulo do livro: ";
    getline(cin, livro.titulo);

    cout << "Digite o autor do livro: ";
    getline(cin, livro.autor);

    cout << "Digite o ano de publicacao do livro: ";
    cin >> livro.anoPublicacao;
    cin.ignore(); 
}

void imprimirLivro(const Livro& livro) {
    cout << "\nDados do Livro:\n";
    cout << "Titulo: " << livro.titulo << endl;
    cout << "Autor: " << livro.autor << endl;
    cout << "Ano de Publicacao: " << livro.anoPublicacao << endl;
}

int main() {
    int n;

    cout << "Quantos livros deseja cadastrar? ";
    cin >> n;
    cin.ignore(); 

    Livro livros[n];

    for (int i = 0; i < n; i++) {
        cout << "\nCadastro do Livro " << i + 1 << ":\n";
        cadastrarLivro(livros[i]);
    }

    for (int i = 0; i < n; i++) {
        imprimirLivro(livros[i]);
    }

    return 0;
}

