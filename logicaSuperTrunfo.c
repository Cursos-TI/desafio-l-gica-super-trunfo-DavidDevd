#include <stdio.h>

int main() {
    printf("Desafio cartas trunfo\n");

    // Estrutura para montar os dados da carta
    struct carta {
        char estado[4];
        char codigo[3];
        char cidade[30];
        int populacao;
        float area, pib, densidade_popula;
        int turismo;
    };

    struct carta carta1, carta2;

    // Entrada dos dados da primeira carta
    printf("Insira os dados da primeira carta: \n");
    printf("Estado (A - H): ");
    scanf("%s", carta1.estado);
    printf("Código da carta (ex: A01): ");
    scanf("%s", carta1.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^"]s", carta1.cidade);
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta1.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.turismo);

    // Entrada dos dados da segunda carta
    printf("\nInsira os dados da segunda carta:\n");
    printf("Estado (A-H): ");
    scanf("%s", carta2.estado);
    printf("Código da Carta (ex: A02): ");
    scanf("%s", carta2.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^"]s", carta2.cidade);
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.turismo);

    // Cálculos para as cartas
    carta1.densidade_popula = carta1.populacao / carta1.area;
    carta2.densidade_popula = carta2.populacao / carta2.area;

    int opcao;
    printf("\nEscolha um atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    printf("\nResultado da comparação:\n");
    if (opcao >= 1 && opcao <= 5) {
        float valor1, valor2;
        switch (opcao) {
            case 1: valor1 = carta1.populacao; valor2 = carta2.populacao; break;
            case 2: valor1 = carta1.area; valor2 = carta2.area; break;
            case 3: valor1 = carta1.pib; valor2 = carta2.pib; break;
            case 4: valor1 = carta1.turismo; valor2 = carta2.turismo; break;
            case 5: valor1 = carta1.densidade_popula; valor2 = carta2.densidade_popula; break;
        }

        if (opcao == 5) { // Regra especial para Densidade Demográfica (menor valor vence)
            if (valor1 < valor2) {
                printf("%s (%s) venceu!\n", carta1.cidade, carta1.estado);
            } else if (valor2 < valor1) {
                printf("%s (%s) venceu!\n", carta2.cidade, carta2.estado);
            } else {
                printf("Empate entre %s (%s) e %s (%s)!\n", carta1.cidade, carta1.estado, carta2.cidade, carta2.estado);
            }
        } else { // Regra geral (maior valor vence)
            if (valor1 > valor2) {
                printf("%s (%s) venceu!\n", carta1.cidade, carta1.estado);
            } else if (valor2 > valor1) {
                printf("%s (%s) venceu!\n", carta2.cidade, carta2.estado);
            } else {
                printf("Empate entre %s (%s) e %s (%s)!\n", carta1.cidade, carta1.estado, carta2.cidade, carta2.estado);
            }
        }
    } else {
        printf("Opção inválida!\n");
    }
    
    return 0;
}




