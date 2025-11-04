
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;

// Insertion Sort (insercao simples)
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // desloca elementos maiores para a direita
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Funcoes de geracao de vetor
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

// Mede o tempo medio
template <typename F>
double medirTempo(F gerador, int n, int repeticoes) {
    double soma = 0.0;
    for (int r = 0; r < repeticoes; r++) {
        auto arr = gerador(n);
        auto inicio = high_resolution_clock::now();
        insertionSort(arr);
        auto fim = high_resolution_clock::now();
        soma += duration<double, micro>(fim - inicio).count();
    }
    return soma / repeticoes; // microssegundos
}

int main() {
    srand(time(nullptr));

    int tamanhos[] = {1000, 5000, 10000, 15000, 20000, 25000, 50000, 100000};
    int repeticoes = 10;

    for (int n : tamanhos) {
        cout << "\n Testando Insertion Sort com vetor de tamanho " << n << "\n";

        cout << " - aleatorio: "
             << medirTempo(gerarAleatorio, n, repeticoes) << " microssegundos\n";

        cout << " - crescente: "
             << medirTempo(gerarCrescente, n, repeticoes) << " microssegundos\n";

        cout << " - decrescente: "
             << medirTempo(gerarDecrescente, n, repeticoes) << " microssegundos\n";
    }
}
