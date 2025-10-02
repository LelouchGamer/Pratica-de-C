#include <iostream>
using namespace std;

struct Ponto {
    int x;
    int y;
    int z;
};

int main() {
    Ponto ponto = {1, 2, 3};

    cout << "Ponto (x, y, z): (" << ponto.x << ", " << ponto.y << ", " << ponto.z << ")" << endl;

    return 0;
}

