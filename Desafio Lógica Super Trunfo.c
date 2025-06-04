#include <stdio.h>

// Define uma estrutura para representar uma carta do jogo
typedef struct {
    char estado;                 // Letra representando o estado (A-H)
    char codigo[4];              // Código da carta (ex: A01)
    char nome[50];               // Nome da cidade
    int populacao;               // População da cidade
    float area;                  // Área em km²
    float pib;                   // PIB em bilhões de reais
    int pontosTuristicos;       // Número de pontos turísticos
    float densidade;            // Densidade populacional (calculada)
    float pibPerCapita;         // PIB per capita (calculado)
} Carta;

// Função para calcular densidade populacional e PIB per capita
void calcularDados(Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pibPerCapita = (c->pib * 1000000000) / c->populacao; // PIB em reais dividido pela população
}

// Função para imprimir todos os dados de uma carta
void imprimirCarta(Carta c) {
    printf("\n--- Carta: %s (%s) ---\n", c.nome, c.codigo);
    printf("Estado: %c\n", c.estado);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade: %.2f hab/km²\n", c.densidade);
    printf("PIB per Capita: %.2f\n", c.pibPerCapita);
}

int main() {
    // Declara duas cartas: uma para o jogador, outra para a máquina
    Carta jogador, maquina;
    int atributo; // Atributo escolhido para a disputa

    // Entrada dos dados da carta do jogador
    printf("=== Cadastro da carta do Jogador ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &jogador.estado);
    printf("Código: ");
    scanf("%s", jogador.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", jogador.nome);
    printf("População: ");
    scanf("%d", &jogador.populacao);
    printf("Área (km²): ");
    scanf("%f", &jogador.area);
    printf("PIB (bilhões): ");
    scanf("%f", &jogador.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &jogador.pontosTuristicos);
    calcularDados(&jogador); // Calcula densidade e PIB per capita

    // Entrada dos dados da carta da máquina
    printf("\n=== Cadastro da carta da Máquina ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &maquina.estado);
    printf("Código: ");
    scanf("%s", maquina.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", maquina.nome);
    printf("População: ");
    scanf("%d", &maquina.populacao);
    printf("Área (km²): ");
    scanf("%f", &maquina.area);
    printf("PIB (bilhões): ");
    scanf("%f", &maquina.pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &maquina.pontosTuristicos);
    calcularDados(&maquina); // Calcula densidade e PIB per capita

    // Exibe a carta do jogador para que ele decida qual atributo usar
    printf("\n=== Sua Carta ===\n");
    imprimirCarta(jogador);

    // Menu de escolha do atributo
    printf("\nEscolha o atributo para disputa:\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Populacional\n6. PIB per Capita\n");
    printf("Digite o número do atributo: ");
    scanf("%d", &atributo);

    // Variáveis auxiliares para armazenar o valor do atributo escolhido de cada carta
    float valorJogador, valorMaquina;

    // Compara os atributos selecionados
    switch(atributo) {
        case 1:
            valorJogador = jogador.populacao;
            valorMaquina = maquina.populacao;
            break;
        case 2:
            valorJogador = jogador.area;
            valorMaquina = maquina.area;
            break;
        case 3:
            valorJogador = jogador.pib;
            valorMaquina = maquina.pib;
            break;
        case 4:
            valorJogador = jogador.pontosTuristicos;
            valorMaquina = maquina.pontosTuristicos;
            break;
        case 5:
            valorJogador = jogador.densidade;
            valorMaquina = maquina.densidade;
            break;
        case 6:
            valorJogador = jogador.pibPerCapita;
            valorMaquina = maquina.pibPerCapita;
            break;
        default:
            printf("Atributo inválido.\n");
            return 1; // Encerra o programa se o atributo for inválido
    }

    // Exibe a carta da máquina para comparação
    printf("\n=== Carta da Máquina ===\n");
    imprimirCarta(maquina);

    // Exibe o resultado com base na comparação dos valores
    printf("\nResultado da Rodada:\n");
    if (valorJogador > valorMaquina)
        printf("Você venceu!\n");
    else if (valorJogador < valorMaquina)
        printf("A máquina venceu!\n");
    else
        printf("Empate!\n");

    return 0;
}
