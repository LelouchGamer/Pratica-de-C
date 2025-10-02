#include <iostream>
using namespace std;

enum Meses {
    Janeiro = 1,
    Fevereiro,
    Marco,
    Abril,
    Maio,
    Junho,
    Julho,
    Agosto,
    Setembro,
    Outubro,
    Novembro,
    Dezembro
};

int main() {
    for (int i = Janeiro; i <= Dezembro; i++) {
        cout << "Mes " << i << ": " << (i == Janeiro ? "Janeiro" :
                                        i == Fevereiro ? "Fevereiro" :
                                        i == Marco ? "Marco" :
                                        i == Abril ? "Abril" :
                                        i == Maio ? "Maio" :
                                        i == Junho ? "Junho" :
                                        i == Julho ? "Julho" :
                                        i == Agosto ? "Agosto" :
                                        i == Setembro ? "Setembro" :
                                        i == Outubro ? "Outubro" :
                                        i == Novembro ? "Novembro" : "Dezembro") << endl;
    }
    return 0;
}

