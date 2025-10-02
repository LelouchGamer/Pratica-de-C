#include <iostream>
#include <string>
using namespace std;

struct Produto {
    string nome;
    int codigo;
    float preco;
};

int main() {
    Produto produto;
    cout << "Tamanho da estrutura Produto: " << sizeof(produto) << " bytes" << endl;
    return 0;
}

