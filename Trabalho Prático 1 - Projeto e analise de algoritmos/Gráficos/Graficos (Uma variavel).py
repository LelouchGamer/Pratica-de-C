import matplotlib.pyplot as plt

# Tamanhos dos vetores
tamanhos = [1000, 5000, 10000, 15000, 20000, 25000, 50000, 100000]

# Tempos em microssegundos 
tempos =  [5801.29, 161507.33, 601518.7, 1269423.33, 2207920, 3616403.38, 16032333.33, 60251066.72]



# Gerar gráfico
plt.plot(tamanhos, tempos, marker='o', color='b', label='Bubble Sort - Medio')

# Configurações do gráfico
plt.title("Desempenho do Bubble Sort (Melhorado) (Medio)")
plt.xlabel("Tamanho do vetor")
plt.ylabel("Tempo (microssegundos)")
plt.grid(True)
plt.legend()

# Mostrar
plt.show()
