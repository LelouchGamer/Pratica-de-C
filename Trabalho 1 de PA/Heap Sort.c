#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;

// Função para trocar
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Heapify
void heapify(vector<int>& arr, int n, int i) {
    int maior = i;
    int esquerda = 2*i + 1;
    int direita = 2*i + 2;

    if (esquerda < n && arr[esquerda] > arr[maior])
        maior = esquerda;
    if (direita < n && arr[direita] > arr[maior])
        maior = direita;

    if (maior != i) {
        swap(arr[i], arr[maior]);
        heapify(arr, n, maior);
    }
}

// Heap Sort
void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Geradores de vetor
vector<int> gerarAleatorio(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = rand() % (n*10);
    return arr;
}

vector<int> gerarCrescente(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = i;
    return arr;
}

vector<int> gerarDecrescente(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = n - i - 1;
    return arr;
}

// Mede o tempo em microssegundos
template <typename F>
double medirTempo(F gerador, int n, int repeticoes) {
    double soma = 0.0;

    for (int r = 0; r < repeticoes; r++) {
        auto arr = gerador(n);

        auto inicio = high_resolution_clock::now();
        heapSort(arr);
        auto fim = high_resolution_clock::now();

        soma += duration<double, micro>(fim - inicio).count();
    }
    return soma / repeticoes; // média em microssegundos
}

int main() {
    srand(time(nullptr));

    int tamanhos[] = {1000, 10000, 50000, 100000};
    int repeticoes = 10;

    for (int n : tamanhos) {
        cout << "\n📊 Testando com vetor de tamanho " << n << "\n";

        cout << " - aleatório: "
             << medirTempo(gerarAleatorio, n, repeticoes) << " microssegundos\n";

        cout << " - crescente: "
             << medirTempo(gerarCrescente, n, repeticoes) << " microssegundos\n";

        cout << " - decrescente: "
             << medirTempo(gerarDecrescente, n, repeticoes) << " microssegundos\n";
    }
}
