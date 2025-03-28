#include <stdio.h>

struct carta {
    char estado[4];
    char codigo[3];
    char cidade[30];
    int populacao;
    float area, pib, densidade_popula;
    int turismo;
};

void limparBuffer() {
    while (getchar() != '\n');
}

void exibirMenu(int selecionado) {
    printf("\nEscolha um atributo para comparar:\n");
    if (selecionado != 1) printf("1 - Popula\xE7\xE3o\n");
    if (selecionado != 2) printf("2 - \xC1rea\n");
    if (selecionado != 3) printf("3 - PIB\n");
    if (selecionado != 4) printf("4 - Pontos Tur\xEDsticos\n");
    if (selecionado != 5) printf("5 - Densidade Demogr\xE1fica\n");
    printf("Escolha: ");
}

int obterAtributoValido(int selecionado) {
    int opcao;
    do {
        scanf("%d", &opcao);
        limparBuffer();
        if (opcao < 1 || opcao > 5 || opcao == selecionado)
            printf("Op\xE7\xE3o inv\xE1lida! Escolha novamente.\n");
    } while (opcao < 1 || opcao > 5 || opcao == selecionado);
    return opcao;
}

float obterValorAtributo(struct carta c, int opcao) {
    switch (opcao) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.turismo;
        case 5: return c.densidade_popula;
        default: return 0;
    }
}

void compararCartas(struct carta c1, struct carta c2, int attr1, int attr2) {
    float valor1_attr1 = obterValorAtributo(c1, attr1);
    float valor2_attr1 = obterValorAtributo(c2, attr1);
    float valor1_attr2 = obterValorAtributo(c1, attr2);
    float valor2_attr2 = obterValorAtributo(c2, attr2);

    int vitorias_c1 = 0, vitorias_c2 = 0;

    printf("\nComparando atributos:\n");
    printf("%s (%s) - %d: %.2f, %d: %.2f\n", c1.cidade, c1.estado, attr1, valor1_attr1, attr2, valor1_attr2);
    printf("%s (%s) - %d: %.2f, %d: %.2f\n", c2.cidade, c2.estado, attr1, valor2_attr1, attr2, valor2_attr2);

    if ((attr1 == 5 && valor1_attr1 < valor2_attr1) || (attr1 != 5 && valor1_attr1 > valor2_attr1)) vitorias_c1++;
    else if ((attr1 == 5 && valor1_attr1 > valor2_attr1) || (attr1 != 5 && valor1_attr1 < valor2_attr1)) vitorias_c2++;
    
    if ((attr2 == 5 && valor1_attr2 < valor2_attr2) || (attr2 != 5 && valor1_attr2 > valor2_attr2)) vitorias_c1++;
    else if ((attr2 == 5 && valor1_attr2 > valor2_attr2) || (attr2 != 5 && valor1_attr2 < valor2_attr2)) vitorias_c2++;
    
    float soma_c1 = valor1_attr1 + valor1_attr2;
    float soma_c2 = valor2_attr1 + valor2_attr2;

    printf("\nSoma dos atributos:\n");
    printf("%s (%s): %.2f\n", c1.cidade, c1.estado, soma_c1);
    printf("%s (%s): %.2f\n", c2.cidade, c2.estado, soma_c2);

    if (soma_c1 > soma_c2)
        printf("%s (%s) venceu a rodada!\n", c1.cidade, c1.estado);
    else if (soma_c2 > soma_c1)
        printf("%s (%s) venceu a rodada!\n", c2.cidade, c2.estado);
    else
        printf("Empate!\n");
}

int main() {
    printf("Desafio cartas trunfo\n");

    struct carta carta1 = {"A", "A1", "Cidade1", 500000, 1500.0, 200.5, 0, 50};
    struct carta carta2 = {"B", "B1", "Cidade2", 600000, 1800.0, 180.0, 0, 40};

    carta1.densidade_popula = carta1.populacao / carta1.area;
    carta2.densidade_popula = carta2.populacao / carta2.area;

    int opcao1, opcao2;
    exibirMenu(0);
    opcao1 = obterAtributoValido(0);
    exibirMenu(opcao1);
    opcao2 = obterAtributoValido(opcao1);

    compararCartas(carta1, carta2, opcao1, opcao2);
    return 0;
}





