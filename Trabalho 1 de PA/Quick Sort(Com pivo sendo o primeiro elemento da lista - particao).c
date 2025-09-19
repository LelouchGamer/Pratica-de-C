
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;

// Particionamento usando pivô = primeiro elemento
int particiona(vector<int>& arr, int inicio, int fim) {
    int pivo = arr[inicio];
    int i = inicio + 1;
    int j = fim;

    while (true) {
        while (i <= j && arr[i] <= pivo) i++;
        while (arr[j] > pivo) j--;

        if (i < j) swap(arr[i], arr[j]);
        else break;
    }
    swap(arr[inicio], arr[j]);
    return j;
}

// Quick Sort
void quickSort(vector<int>& arr, int inicio, int fim) {
    if (inicio < fim) {
        int p = particiona(arr, inicio, fim);
        quickSort(arr, inicio, p - 1);
        quickSort(arr, p + 1, fim);
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
        quickSort(arr, 0, arr.size() - 1);
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
        cout << "\n📊 Testando Quick Sort (pivô = primeiro elemento) com vetor de tamanho " << n << "\n";

        cout << " - aleatório: "
             << medirTempo(gerarAleatorio, n, repeticoes) << " microssegundos\n";

        cout << " - crescente: "
             << medirTempo(gerarCrescente, n, repeticoes) << " microssegundos\n";

        cout << " - decrescente: "
             << medirTempo(gerarDecrescente, n, repeticoes) << " microssegundos\n";
    }
}
