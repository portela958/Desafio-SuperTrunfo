#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Converte letras de colunas (A-H) para números (0-7)
int colunaParaIndice(char letra) {
    return toupper(letra) - 'A';
}

// Retorna 1 se o movimento for válido para a peça, 0 caso contrário
int movimentoValido(char peca, int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    switch (toupper(peca)) {
        case 'P': // Peão (considerando movimento para cima no tabuleiro)
            return (dx == 0 && dy == 1);
        case 'T': // Torre
            return (dx == 0 || dy == 0);
        case 'B': // Bispo
            return (dx == dy);
        case 'C': // Cavalo
            return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
        case 'D': // Dama
            return (dx == dy || dx == 0 || dy == 0);
        case 'R': // Rei
            return (dx <= 1 && dy <= 1);
        default:
            return 0;
    }
}

int main() {
    char peca;
    char colunaOrigem, colunaDestino;
    int linhaOrigem, linhaDestino;

    printf("Digite a peça (P/T/B/C/D/R): ");
    scanf(" %c", &peca);

    printf("Digite a posição inicial (ex: A2): ");
    scanf(" %c%d", &colunaOrigem, &linhaOrigem);

    printf("Digite a posição final (ex: A3): ");
    scanf(" %c%d", &colunaDestino, &linhaDestino);

    // Converte coluna letra para índice de 0 a 7
    int x1 = colunaParaIndice(colunaOrigem);
    int y1 = linhaOrigem - 1;
    int x2 = colunaParaIndice(colunaDestino);
    int y2 = linhaDestino - 1;

    // Verifica validade
    if (movimentoValido(peca, x1, y1, x2, y2))
        printf("Movimento VÁLIDO!\n");
    else
        printf("Movimento INVÁLIDO!\n");

    return 0;
}
