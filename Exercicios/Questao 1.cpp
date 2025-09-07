#include <stdio.h>

int main() {
  int n, i, cont = 0;
  printf("Digite um numero inteiro: ");
  scanf("%d", &n);

  for (i = 2; i <= n / 2; ++i) { 
    if (n % i == 0) {
      cont = 1;
      break;
    }
  }

  if (n == 1) {
    printf("o numero 1 nao e primo");
    return 0;
  } 
  else {
    if (cont == 0)
      printf("o numero %d e primo.", n);
    else
      printf("o numero %d nao e primo.", n);
  }
    if (cont == 0) {
        return 1;
    }
    if (cont != 0) {
        return 0;
    }
}
