import matplotlib.pyplot as plt

# 🧮 Tamanhos dos vetores
tamanhos = [1000, 5000, 10000, 15000, 20000, 25000, 50000, 100000]

# 🔹 Shell Sort
shell_ale = [299.99, 1600.43, 4401.03, 6001.52, 10002.2, 12302.8, 26205.8, 59417.8]
shell_cre = [100.08, 600.03, 1200.23, 1700.27, 3000.75, 3300.63, 6601.61, 14809]
shell_dec = [100.04, 900.23, 2000.45, 3100.63, 4401.06, 5301.29, 10302.3, 21309.2]
shell_med = [166.7, 1033.56, 2533.9, 3600.8, 5801.34, 6974.91, 14369.9, 31845.3]

# 🔹 Selection Sort
selection_ale = [3100.7, 83270, 284846, 633213, 1096790, 1849810, 7002720, 26991900]
selection_cre = [3300.72, 75331.7, 280537, 609898, 1154150, 1872960, 6780020, 27063900]
selection_dec = [3401.37, 77517.4, 284554, 645851, 1230330, 1912550, 6935030, 27791700]
selection_med = [3267.6, 78706.4, 283312.3, 629654, 1163757, 1875106, 6905923, 27272500]

# 🔹 Quick Sort (pivô primeiro)
quick1_ale = [200.02, 1000.21, 1898.28, 3100.79, 5005.32, 5101.19, 11802.9, 32364.9]
quick1_cre = [1400.21, 40009, 164733, 397163, 709055, 1045210, 4311530, 16528800]
quick1_dec = [1500.44, 40124.5, 167903, 400489, 714066, 1080140, 3843240, 15402200]
quick1_med = [1033.6, 27044.6, 111511, 266918, 476042, 708817, 2725524, 10621121]

# 🔹 Quick Sort (pivô central)
quick2_ale = [99.85, 1012.05, 2031.7, 3329.01, 4545.94, 5127.91, 11130.3, 24414]
quick2_cre = [0, 400.09, 713.48, 1001.87, 1210.56, 1833.8, 3120.32, 8810.92]
quick2_dec = [0, 512.17, 814.54, 1404.95, 1812.25, 2000.5, 4518.41, 9407.53]
quick2_med = [33.28, 641.44, 1186.57, 1911.94, 2522.92, 2920.74, 6246.34, 14210.8]

# 🔹 Merge Sort
merge_ale = [612.18, 4022.98, 8274.23, 11971.8, 16019.2, 19406.9, 36802.7, 73310.7]
merge_cre = [500.24, 3934.54, 8041.24, 10365.2, 13202.3, 14988.3, 29588.8, 59356.7]
merge_dec = [499.92, 3008.35, 6711.22, 10001.2, 13499.1, 16559.7, 28836.5, 59055.2]
merge_med = [537.45, 3655.29, 7675.56, 10779.4, 14240.2, 16984.97, 31742.7, 63907.5]

# 🔹 Insertion Sort
insertion_ale = [2200.41, 53411.9, 212048, 456803, 819766, 1265600, 5343660, 21390000]
insertion_cre = [0, 100.07, 100.07, 300.07, 333.56, 370.89, 399.98, 1000.06]
insertion_dec = [4801.12, 102923, 413193, 909794, 1609560, 2513990, 10607100, 43512100]
insertion_med = [2333.84, 52011.65, 208447.02, 455632.36, 808775.33, 1259863.33, 5333853.33, 21901033.36]

# 🔹 Heap Sort
heap_ale = [400.08, 2000.45, 4200.77, 6401.37, 8801.76, 11502.6, 23913.9, 53812.2]
heap_cre = [300.1, 2155.74, 4801.16, 6301.36, 7801.73, 10452.9, 21383.1, 47010.6]
heap_dec = [300.15, 1800.36, 3700.88, 5901.25, 7101.74, 10202.2, 21104.7, 42909.7]
heap_med = [333.44, 1985.52, 4234.27, 6201.33, 7901.74, 10719.23, 22133.9, 47910.83]

# 🔹 Bubble Sort (sem melhorias)
bubble_ale = [11502.6, 292370, 1031760, 2345710, 4096440, 6310690, 25430900, 102670000]
bubble_cre = [6601.41, 151234, 559141, 1371390, 2229890, 3471640, 13978700, 55480200]
bubble_dec = [12702.9, 282163, 1104230, 2493690, 4411400, 6858360, 27707600, 110925000]
bubble_med = [6935.0, 241922.3, 898043.7, 2070263, 3585910, 5546897, 22372400, 89758333.3]

# 🔹 Bubble Sort (melhorado)
bubbleO_ale = [7401.69, 195544, 912656, 1745040, 3139160, 5316860, 21520900, 82054100]
bubbleO_cre = [0, 0, 0, 99.98, 188.24, 300.14, 400.16, 700.17]
bubbleO_dec = [10002.2, 288978, 891900, 2053130, 3485590, 5522050, 26235700, 97898400]
bubbleO_med = [5801.29, 161507.33, 601518.7, 1269423.33, 2207920, 3616403.38, 16032333.33, 60251066.72]

# =======================================================
# Função para plotar um gráfico por algoritmo
# =======================================================
def plotar_algoritmo(nome, ale, cre, dec, med):
    plt.figure(figsize=(8,5))
    plt.plot(tamanhos, ale, marker='o', label='Aleatório')
    plt.plot(tamanhos, cre, marker='o', label='Crescente')
    plt.plot(tamanhos, dec, marker='o', label='Decrescente')
    plt.plot(tamanhos, med, marker='o', linestyle='--', label='Médio', linewidth=2)
    plt.title(f"{nome} - Desempenho por Tipo de Vetor")
    plt.xlabel("Tamanho do Vetor")
    plt.ylabel("Tempo (µs)")
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.show()

# =======================================================
# Gere aqui os gráficos que quiser
# =======================================================
plotar_algoritmo("Shell Sort", shell_ale, shell_cre, shell_dec, shell_med)
plotar_algoritmo("Selection Sort", selection_ale, selection_cre, selection_dec, selection_med)
plotar_algoritmo("Quick Sort (Pivô Primeiro)", quick1_ale, quick1_cre, quick1_dec, quick1_med)
plotar_algoritmo("Quick Sort (Pivô Central)", quick2_ale, quick2_cre, quick2_dec, quick2_med)
plotar_algoritmo("Merge Sort", merge_ale, merge_cre, merge_dec, merge_med)
plotar_algoritmo("Insertion Sort", insertion_ale, insertion_cre, insertion_dec, insertion_med)
plotar_algoritmo("Heap Sort", heap_ale, heap_cre, heap_dec, heap_med)
plotar_algoritmo("Bubble Sort", bubble_ale, bubble_cre, bubble_dec, bubble_med)
plotar_algoritmo("Bubble Sort (Otimizado)", bubbleO_ale, bubbleO_cre, bubbleO_dec, bubbleO_med)
