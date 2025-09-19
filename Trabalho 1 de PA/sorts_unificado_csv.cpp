#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;
using namespace std::chrono;

/* ======================================================
   Funções utilitárias
   ====================================================== */
void imprimirVetor(const vector<int>& arr) {
    for (int v : arr) cout << v << " ";
    cout << "\n";
}

vector<int> gerarAleatorio(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = rand() % (n*10);
    return arr;
}

vector<int> gerarCrescente(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = i;
    return arr;
}

vector<int> gerarDecrescente(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = n - i - 1;
    return arr;
}

/* ======================================================
   Algoritmos de Ordenação
   ====================================================== */
// Insertion Sort
void insertionSort(vector<int>& arr) {
    for (int i = 1; i < (int)arr.size(); i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

// Bubble Sort simples
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-1; j++)
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
}

// Bubble Sort otimizado
void bubbleSortOtimizado(vector<int>& arr) {
    int n = arr.size();
    bool trocou;
    for (int i = 0; i < n-1; i++) {
        trocou = false;
        for (int j = 0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                trocou = true;
            }
        }
        if (!trocou) break;
    }
}

// Heap Sort
void heapify(vector<int>& arr, int n, int i) {
    int maior = i, esq = 2*i+1, dir = 2*i+2;
    if (esq < n && arr[esq] > arr[maior]) maior = esq;
    if (dir < n && arr[dir] > arr[maior]) maior = dir;
    if (maior != i) {
        swap(arr[i], arr[maior]);
        heapify(arr, n, maior);
    }
}
void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n/2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Merge Sort
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[l+i];
    for (int j = 0; j < n2; j++) R[j] = arr[m+1+j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}
void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

// Shell Sort
void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i], j;
            for (j = i; j >= gap && arr[j-gap] > temp; j -= gap)
                arr[j] = arr[j-gap];
            arr[j] = temp;
        }
    }
}

// Quick Sort (pivô = primeiro elemento)
int particionaPrimeiro(vector<int>& arr, int inicio, int fim) {
    int pivo = arr[inicio], i = inicio+1, j = fim;
    while (true) {
        while (i <= j && arr[i] <= pivo) i++;
        while (arr[j] > pivo) j--;
        if (i < j) swap(arr[i], arr[j]);
        else break;
    }
    swap(arr[inicio], arr[j]);
    return j;
}
void quickSortPrimeiro(vector<int>& arr, int inicio, int fim) {
    if (inicio < fim) {
        int p = particionaPrimeiro(arr, inicio, fim);
        quickSortPrimeiro(arr, inicio, p-1);
        quickSortPrimeiro(arr, p+1, fim);
    }
}

// Quick Sort (pivô = elemento central)
int particionaCentral(vector<int>& arr, int inicio, int fim) {
    int meio = inicio + (fim-inicio)/2, pivo = arr[meio];
    swap(arr[meio], arr[inicio]);
    int i = inicio+1, j = fim;
    while (true) {
        while (i <= j && arr[i] <= pivo) i++;
        while (arr[j] > pivo) j--;
        if (i < j) swap(arr[i], arr[j]);
        else break;
    }
    swap(arr[inicio], arr[j]);
    return j;
}
void quickSortCentral(vector<int>& arr, int inicio, int fim) {
    if (inicio < fim) {
        int p = particionaCentral(arr, inicio, fim);
        quickSortCentral(arr, inicio, p-1);
        quickSortCentral(arr, p+1, fim);
    }
}

/* ======================================================
   Medição de tempo
   ====================================================== */
template <typename F>
double medirTempo(F sortFunc, vector<int> arr, int repeticoes) {
    double soma = 0.0;
    for (int r = 0; r < repeticoes; r++) {
        auto copia = arr;
        auto inicio = high_resolution_clock::now();
        sortFunc(copia);
        auto fim = high_resolution_clock::now();
        soma += duration<double, micro>(fim - inicio).count();
    }
    return soma / repeticoes;
}

/* ======================================================
   Main
   ====================================================== */
int main() {
    srand(time(nullptr));

    // tamanhos de vetor
    int tamanhos[] = {10, 100, 1000, 10000};
    int repeticoes = 5;

    // lista de algoritmos
    struct Alg {
        string nome;
        void (*func)(vector<int>&);
    };
    vector<Alg> algoritmos = {
        {"Insertion Sort", insertionSort},
        {"Selection Sort", selectionSort},
        {"Bubble Sort", bubbleSort},
        {"Bubble Sort Otimizado", bubbleSortOtimizado},
        {"Heap Sort", heapSort},
        {"Merge Sort", [](vector<int>& a){ mergeSort(a,0,a.size()-1);} },
        {"Shell Sort", shellSort},
        {"Quick Sort (Primeiro)", [](vector<int>& a){ quickSortPrimeiro(a,0,a.size()-1);} },
        {"Quick Sort (Central)", [](vector<int>& a){ quickSortCentral(a,0,a.size()-1);} }
    };

    // geradores
    vector<pair<string, vector<int>(*)(int)>> geradores = {
        {"Aleatório", gerarAleatorio},
        {"Crescente", gerarCrescente},
        {"Decrescente", gerarDecrescente}
    };

    ofstream csv("resultados.csv");
    csv << "Tamanho,Caso,Algoritmo,Tempo_medio_microsegundos\n";

    for (int n : tamanhos) {
        cout << "\n========================\n";
        cout << "Tamanho do vetor: " << n << "\n";
        cout << "========================\n";
        for (auto& g : geradores) {
            cout << "\n>>> Caso " << g.first << " <<<\n";
            auto base = g.second(n);

            if (n <= 10) {
                cout << "Vetor original: ";
                imprimirVetor(base);
            }

            for (auto& alg : algoritmos) {
                auto arr = base;
                double tempo = medirTempo(alg.func, base, repeticoes);
                alg.func(arr);

                cout << setw(22) << left << alg.nome << ": " 
                     << tempo << " microssegundos\n";

                if (n <= 10) {
                    cout << "Ordenado: ";
                    imprimirVetor(arr);
                }

                csv << n << "," << g.first << "," << alg.nome << "," << tempo << "\n";
            }
        }
    }
    csv.close();
    cout << "\nResultados exportados para resultados.csv\n";
    return 0;
}