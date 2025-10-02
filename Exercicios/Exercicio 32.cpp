#include <iostream>
#include <string>
using namespace std;

struct Produto {
    string nome;
    int codigo;
    float preco;
};

int main() {
    Produto produtos[4] = {
        {"Produto A", 101, 29.99},
        {"Produto B", 102, 19.50},
        {"Produto C", 103, 45.80},
        {"Produto D", 104, 99.99}
    };

    for (int i = 0; i < 4; i++) {
        cout << "Produto " << i + 1 << ":\n";
        cout << "Nome: " << produtos[i].nome << endl;
        cout << "Codigo: " << produtos[i].codigo << endl;
        cout << "Preco: R$ " << produtos[i].preco << endl;
        cout << endl;
    }

    return 0;
}

