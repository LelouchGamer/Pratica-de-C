
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace std::chrono;

// Bubble Sort otimizado
void bubbleSortOtimizado(vector<int>& arr) {
    int n = arr.size();
    bool trocou;
    for (int i = 0; i < n-1; i++) {
        trocou = false;
        for (int j = 0; j < n-1-i; j++) { // já ignora elementos finais
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                trocou = true;
            }
        }
        if (!trocou) break; // se não houve troca, vetor já está ordenado
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
        bubbleSortOtimizado(arr);
        auto fim = high_resolution_clock::now();
        soma += duration<double, micro>(fim - inicio).count();
    }
    return soma / repeticoes; // microssegundos
}

int main() {
    srand(time(nullptr));

    int tamanhos[] = {100, 500, 1000, 5000};
    int repeticoes = 10; // média de execuções

    for (int n : tamanhos) {
        cout << "\n📊 Testando Bubble Sort otimizado com vetor de tamanho " << n << "\n";

        cout << " - aleatório: "
             << medirTempo(gerarAleatorio, n, repeticoes) << " microssegundos\n";

        cout << " - crescente: "
             << medirTempo(gerarCrescente, n, repeticoes) << " microssegundos\n";

        cout << " - decrescente: "
             << medirTempo(gerarDecrescente, n, repeticoes) << " microssegundos\n";
    }
}
