#include <stdio.h>

int main() {
    printf("Desafio cartas trunfo\n");

    // Estrutura para montar os dados da carta
    struct carta {
        char estado[4];
        char codigo[3];
        char cidade[30];
        int populacao;
        float area, pib, densidade_popula, pib_perca, super_poder;
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
    scanf(" %[^\n]s", carta1.cidade); // Permitir espaços no nome da cidade

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
    scanf(" %[^\n]s", carta2.cidade); // Permitir espaços no nome da cidade

    printf("População: ");
    scanf("%d", &carta2.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta2.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.turismo);

    // Cálculos para carta1
    carta1.densidade_popula = carta1.populacao / carta1.area;
    carta1.pib_perca = carta1.pib / carta1.populacao;
    carta1.super_poder = carta1.populacao + carta1.area + carta1.pib + carta1.turismo + carta1.pib_perca + (1 / carta1.densidade_popula);

    // Cálculos para carta2
    carta2.densidade_popula = carta2.populacao / carta2.area;
    carta2.pib_perca = carta2.pib / carta2.populacao;
    carta2.super_poder = carta2.populacao + carta2.area + carta2.pib + carta2.turismo + carta2.pib_perca + (1 / carta2.densidade_popula);

    // Exibindo os dados das cartas
    printf("\nDados da primeira carta:\n");
    printf("Estado: %s\n", carta1.estado);
    printf("Código da Carta: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.cidade);
    printf("População: %d\n", carta1.populacao);
    printf("Área (em km²): %.2f\n", carta1.area);
    printf("PIB: %.2f bilhões de reais\n", carta1.pib);
    printf("Número de Pontos Turísticos: %d\n", carta1.turismo);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidade_popula);
    printf("PIB per Capita: %.2f reais\n", carta1.pib_perca);
    printf("Super Poder: %.2f\n", carta1.super_poder);

    printf("\nDados da segunda carta:\n");
    printf("Estado: %s\n", carta2.estado);
    printf("Código da Carta: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.cidade);
    printf("População: %d\n", carta2.populacao);
    printf("Área (em km²): %.2f\n", carta2.area);
    printf("PIB: %.2f bilhões de reais\n", carta2.pib);
    printf("Número de Pontos Turísticos: %d\n", carta2.turismo);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidade_popula);
    printf("PIB per Capita: %.2f reais\n", carta2.pib_perca);
    printf("Super Poder: %.2f\n", carta2.super_poder);

    // Comparação das cartas
    printf("\nComparação de Cartas:\n");
    printf("População: %d\n", carta1.populacao > carta2.populacao);
    printf("Área: %d\n", carta1.area > carta2.area);
    printf("PIB: %d\n", carta1.pib > carta2.pib);
    printf("Pontos Turísticos: %d\n", carta1.turismo > carta2.turismo);
    printf("Densidade Populacional: %d\n", carta1.densidade_popula < carta2.densidade_popula);
    printf("PIB per Capita: %d\n", carta1.pib_perca > carta2.pib_perca);
    printf("Super Poder: %d\n", carta1.super_poder > carta2.super_poder);

    return 0;
}




