#include <stdio.h>
#include <stdlib.h>

#define TAM_TAB 10

typedef enum { H = 0, V = 1 } NavioPosicao;

typedef struct {
  NavioPosicao navioPosicao;
  int tamanhoNavio;
  int x, y;
} Navio;

typedef struct {
  int tabuleiro[10][10];
  int quantidadeNavios;
  Navio **navios;
} Tabuleiro;

int verificarPosicao(int x, int y, int tabuleiro[TAM_TAB][TAM_TAB],
                     NavioPosicao posicao) {
  if (tabuleiro[y][x] == 3)
    return 1;
  if (posicao == 0) {
    if (tabuleiro[y][x - 1] == 3)
      return 1;
    if (tabuleiro[y][x + 1] == 3)
      return 1;
  } else {
    if (tabuleiro[y - 1][x] == 3)
      return 1;
    if (tabuleiro[y + 1][x] == 3)
      return 1;
  }

  return 0;
}

Navio novoNavio(NavioPosicao posicao, int x, int y,
                int tabuleiro[TAM_TAB][TAM_TAB]) {
  if (x > TAM_TAB || x < 0 || y < 0 || y > TAM_TAB) {
    printf("barco fora dos limites do tabuleiro.\n");
    exit(1);
  }

  if (posicao == 0 && (x == 0 || x == 10)) {
    printf("barco fora dos limites do tabuleiro.\n");
    exit(1);
  }

  if (posicao == 1 && (y == 0 || y == 10)) {
    printf("barco fora dos limites do tabuleiro.\n");
    exit(1);
  }

  if (verificarPosicao(x, y, tabuleiro, posicao)) {
    printf("Já existe um barco em tal local.\n");
    exit(1);
  }

  Navio navio = {posicao, 3, x, y};
  if (posicao == 0) {
    tabuleiro[y][x - 1] = navio.tamanhoNavio;
    tabuleiro[y][x] = navio.tamanhoNavio;
    tabuleiro[y][x + 1] = navio.tamanhoNavio;
  } else {
    tabuleiro[y - 1][x] = navio.tamanhoNavio;
    tabuleiro[y][x] = navio.tamanhoNavio;
    tabuleiro[y + 1][x] = navio.tamanhoNavio;
  }

  return navio;
}

int main() {
  int tabuleiro[TAM_TAB][TAM_TAB] = {
      {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0},
  };

  Navio navio = novoNavio(H, 2, 0, tabuleiro);
  Navio navio2 = novoNavio(V, 9, 8, tabuleiro);
  Navio navio3 = novoNavio(H, 5, 0, tabuleiro);

  for (int i = 0; i < TAM_TAB; i++) {
    for (int j = 0; j < TAM_TAB; ++j) {
      printf("%i ", tabuleiro[i][j]);
    }
    printf("\n");
  }

  return 0;
}
