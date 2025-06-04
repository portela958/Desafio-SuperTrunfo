#include <stdio.h>

// Tamanho fixo do tabuleiro
#define TAMANHO 5

int main() {
    int linhaNavio, colunaNavio;
    int tentativaLinha, tentativaColuna;
    int acertou = 0;

    printf("=== BATALHA NAVAL ===\n");
    printf("Escolha a posição do navio (linha e coluna de 1 a 5):\n");
    
    // Entrada da posição do navio
    printf("Linha: ");
    scanf("%d", &linhaNavio);
    printf("Coluna: ");
    scanf("%d", &colunaNavio);

    // Validação simples
    if (linhaNavio < 1 || linhaNavio > TAMANHO || colunaNavio < 1 || colunaNavio > TAMANHO) {
        printf("Posição inválida! Use valores entre 1 e 5.\n");
        return 1;
    }

    // Limpa a tela (opcional)
    for (int i = 0; i < 20; i++) printf("\n");

    // Jogadas da máquina (simuladas com entrada manual neste caso)
    for (int i = 1; i <= 3; i++) {
        printf("Jogada %d - Tente acertar a posição (linha e coluna):\n", i);
        printf("Linha: ");
        scanf("%d", &tentativaLinha);
        printf("Coluna: ");
        scanf("%d", &tentativaColuna);

        if (tentativaLinha == linhaNavio && tentativaColuna == colunaNavio) {
            printf("🎯 ACERTOU O NAVIO!\n");
            acertou = 1;
            break;
        } else {
            printf("💦 ÁGUA! Tente novamente.\n");
        }
    }

    if (!acertou) {
        printf("💥 Você perdeu! O navio estava em (%d, %d)\n", linhaNavio, colunaNavio);
    }

    return 0;
}
