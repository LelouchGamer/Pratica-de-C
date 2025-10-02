#include <iostream>
using namespace std;

struct Ponto {
    int x;
    int y;
    int z;
};

struct Espaco {
    Ponto ponto;
};

int main() {
    Espaco espaco = {{1, 2, 3}};

    cout << "Ponto (x, y, z): (" << espaco.ponto.x << ", " << espaco.ponto.y << ", " << espaco.ponto.z << ")" << endl;

    return 0;
}

