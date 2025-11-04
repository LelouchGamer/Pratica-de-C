import matplotlib.pyplot as plt

# 🧮 Tamanhos dos vetores
tamanhos = [1000, 5000, 10000, 15000, 20000, 25000, 50000, 100000]

# 🔹 Dados médios (em microssegundos)
shell_ale = [299.99, 1600.43, 4401.03, 6001.52, 10002.2, 12302.8, 26205.8, 59417.8]
selection_ale = [3100.7, 83270, 284846, 633213, 1096790, 1849810, 7002720, 26991900]
quick1_ale = [200.02, 1000.21, 1898.28, 3100.79, 5005.32, 5101.19, 11802.9, 32364.9]
quick2_ale = [99.85, 1012.05, 2031.7, 3329.01, 4545.94, 5127.91, 11130.3, 24414]
merge_ale = [612.18, 4022.98, 8274.23, 11971.8, 16019.2, 19406.9, 36802.7, 73310.7]
insertion_ale = [2200.41, 53411.9, 212048, 456803, 819766, 1265600, 5343660, 21390000]
heap_ale = [400.08, 2000.45, 4200.77, 6401.37, 8801.76, 11502.6, 23913.9, 53812.2]
bubble_ale = [11502.6, 292370, 1031760, 2345710, 4096440, 6310690, 25430900, 102670000]
bubbleO_ale = [7401.69, 195544, 912656, 1745040, 3139160, 5316860, 21520900, 82054100]

shell_cre = [100.08, 600.03, 1200.23, 1700.27, 3000.75, 3300.63, 6601.61, 14809]
selection_cre = [3300.72, 75331.7, 280537, 609898, 1154150, 1872960, 6780020, 27063900]
quick1_cre = [1400.21, 40009, 164733, 397163, 709055, 1045210, 4311530, 16528800]
quick2_cre = [0, 400.09, 713.48, 1001.87, 1210.56, 1833.8, 3120.32, 8810.92]
merge_cre = [500.24, 3934.54, 8041.24, 10365.2, 13202.3, 14988.3, 29588.8, 59356.7]
insertion_cre = [0, 100.07, 100.07, 300.07, 333.56, 370.89, 399.98, 1000.06]
heap_cre = [300.1, 2155.74, 4801.16, 6301.36, 7801.73, 10452.9, 21383.1, 47010.6]
bubble_cre = [6601.41, 151234, 559141, 1371390, 2229890, 3471640, 13978700, 55480200]
bubbleO_cre = [0, 0, 0, 99.98, 188.24, 300.14, 400.16, 700.17]

shell_dec = [100.04, 900.23, 2000.45, 3100.63, 4401.06, 5301.29, 10302.3, 21309.2]
selection_dec = [3401.37, 77517.4, 284554, 645851, 1230330, 1912550, 6935030, 27791700]
quick1_dec = [1500.44, 40124.5, 167903, 400489, 714066, 1080140, 3843240, 15402200]
quick2_dec = [0, 512.17, 814.54, 1404.95, 1812.25, 2000.5, 4518.41, 9407.53]
merge_dec = [499.92, 3008.35, 6711.22, 10001.2, 13499.1, 16559.7, 28836.5, 59055.2]
insertion_dec = [4801.12, 102923, 413193, 909794, 1609560, 2513990, 10607100, 43512100]
heap_dec = [300.15, 1800.36, 3700.88, 5901.25, 7101.74, 10202.2, 21104.7, 42909.7]
bubble_dec = [12702.9, 282163, 1104230, 2493690, 4411400, 6858360, 27707600, 110925000]
bubbleO_dec = [10002.2, 288978, 891900, 2053130, 3485590, 5522050, 26235700, 97898400]

shell_med = [166.7, 1033.56, 2533.9, 3600.8, 5801.34, 6974.91, 14369.9, 31845.3]
selection_med = [3267.6, 78706.4, 283312.3, 629654, 1163757, 1875106, 6905923, 27272500]
quick1_med = [1033.6, 27044.6, 111511, 266918, 476042, 708817, 2725524, 10621121]
quick2_med = [33.28, 641.44, 1186.57, 1911.94, 2522.92, 2920.74, 6246.34, 14210.8]
merge_med = [537.45, 3655.29, 7675.56, 10779.4, 14240.2, 16984.97, 31742.7, 63907.5]
insertion_med = [2333.84, 52011.65, 208447.02, 455632.36, 808775.33, 1259863.33, 5333853.33, 21901033.36]
heap_med = [333.44, 1985.52, 4234.27, 6201.33, 7901.74, 10719.23, 22133.9, 47910.83]
bubble_med = [6935.0, 241922.3, 898043.7, 2070263, 3585910, 5546897, 22372400, 89758333.3]
bubbleO_med = [5801.29, 161507.33, 601518.7, 1269423.33, 2207920, 3616403.38, 16032333.33, 60251066.72]

# =======================================================
# Função para plotar comparação entre algoritmos
# =======================================================
def comparar_algoritmos(nome_caso, *datasets):
    plt.figure(figsize=(10,6))
    for label, tempos in datasets:
        plt.plot(tamanhos, tempos, marker='o', label=label)
    plt.title(f"Comparação entre Algoritmos - {nome_caso}")
    plt.xlabel("Tamanho do Vetor")
    plt.ylabel("Tempo (µs)")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.show()

# =======================================================
# Gráficos comparativos entre algoritmos
# =======================================================
comparar_algoritmos("Caso Aleatório",
    ("Shell Sort", shell_ale),
    ("Selection Sort", selection_ale),
    ("Quick Sort (Pivô 1º)", quick1_ale),
    ("Quick Sort (Central)", quick2_ale),
    ("Merge Sort", merge_ale),
    ("Insertion Sort", insertion_ale),
    ("Heap Sort", heap_ale),
    ("Bubble Sort", bubble_ale),
    ("Bubble Sort (Otimizado)", bubbleO_ale)
)

comparar_algoritmos("Caso Crescente",
    ("Shell Sort", shell_cre),
    ("Selection Sort", selection_cre),
    ("Quick Sort (Pivô 1º)", quick1_cre),
    ("Quick Sort (Central)", quick2_cre),
    ("Merge Sort", merge_cre),
    ("Insertion Sort", insertion_cre),
    ("Heap Sort", heap_cre),
    ("Bubble Sort", bubble_cre),
    ("Bubble Sort (Otimizado)", bubbleO_cre)
)

comparar_algoritmos("Caso Decrescente",
    ("Shell Sort", shell_dec),
    ("Selection Sort", selection_dec),
    ("Quick Sort (Pivô 1º)", quick1_dec),
    ("Quick Sort (Central)", quick2_dec),
    ("Merge Sort", merge_dec),
    ("Insertion Sort", insertion_dec),
    ("Heap Sort", heap_dec),
    ("Bubble Sort", bubble_dec),
    ("Bubble Sort (Otimizado)", bubbleO_dec)
)

comparar_algoritmos("Caso Médio",
    ("Shell Sort", shell_med),
    ("Selection Sort", selection_med),
    ("Quick Sort (Pivô 1º)", quick1_med),
    ("Quick Sort (Central)", quick2_med),
    ("Merge Sort", merge_med),
    ("Insertion Sort", insertion_med),
    ("Heap Sort", heap_med),
    ("Bubble Sort", bubble_med),
    ("Bubble Sort (Otimizado)", bubbleO_med)
)
