#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;

// Shell Sort
void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

// Funções de geração de vetor
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

// Mede o tempo médio
template <typename F>
double medirTempo(F gerador, int n, int repeticoes) {
    double soma = 0.0;
    for (int r = 0; r < repeticoes; r++) {
        auto arr = gerador(n);
        auto inicio = high_resolution_clock::now();
        shellSort(arr);
        auto fim = high_resolution_clock::now();
        soma += duration<double, micro>(fim - inicio).count();
    }
    return soma / repeticoes; // microssegundos
}

int main() {
    srand(time(nullptr));

    int tamanhos[] = {1000, 5000, 10000, 50000};
    int repeticoes = 10;

    for (int n : tamanhos) {
        cout << "\n📊 Testando Shell Sort com vetor de tamanho " << n << "\n";

        cout << " - aleatório: "
             << medirTempo(gerarAleatorio, n, repeticoes) << " microssegundos\n";

        cout << " - crescente: "
             << medirTempo(gerarCrescente, n, repeticoes) << " microssegundos\n";

        cout << " - decrescente: "
             << medirTempo(gerarDecrescente, n, repeticoes) << " microssegundos\n";
    }
}
