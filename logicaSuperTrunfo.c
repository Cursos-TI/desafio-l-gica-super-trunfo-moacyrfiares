#include <stdio.h>

// SUPER TRUNFO – DESAFIO MESTRE
// Autor: Moacyr Fiares Pereira Junior
// Versão completa com comparação de 2 atributos, menus dinâmicos e soma final

int main() {

    // Declaração das variáveis da Carta 1
    char estado_1;
    char codigo_1[5];
    char cidade_1[50];
    float area_1, pib_1;
    unsigned long int populacao_1;
    int turismo_1;
    float densidade_1, pib_capita_1;

    // Declaração das variáveis da Carta 2
    char estado_2;
    char codigo_2[5];
    char cidade_2[50];
    float area_2, pib_2;
    unsigned long int populacao_2;
    int turismo_2;
    float densidade_2, pib_capita_2;

    //==============================//
    // CADASTRO DA CARTA 1
    //==============================//
    printf("Cadastro da Carta 1:\n");

    printf("Digite o Estado (A a H): ");
    scanf("%c", &estado_1);

    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%s", codigo_1);

    printf("Digite o Nome da Cidade: ");
    scanf("%s", cidade_1);

    printf("Digite a População: ");
    scanf("%lu", &populacao_1);

    printf("Digite a Área (em km²): ");
    scanf("%f", &area_1);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib_1);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &turismo_1);

    //==============================//
    // CADASTRO DA CARTA 2
    //==============================//
    printf("\nCadastro da Carta 2:\n");

    printf("Digite o Estado (A a H): ");
    scanf(" %c", &estado_2);

    printf("Digite o Código da Carta (ex: B01): ");
    scanf("%s", codigo_2);

    printf("Digite o Nome da Cidade: ");
    scanf("%s", cidade_2);

    printf("Digite a População: ");
    scanf("%lu", &populacao_2);

    printf("Digite a Área (em km²): ");
    scanf("%f", &area_2);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib_2);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &turismo_2);

    //==============================//
    // CÁLCULOS
    //==============================//
    densidade_1 = populacao_1 / area_1;
    densidade_2 = populacao_2 / area_2;

    pib_capita_1 = (pib_1 * 1000000000) / populacao_1;
    pib_capita_2 = (pib_2 * 1000000000) / populacao_2;

    //==============================//
    // MENU DE ATRIBUTOS
    //==============================//

    int atributo1, atributo2;
    float valor1_c1, valor1_c2;
    float valor2_c1, valor2_c2;

    printf("\nEscolha o PRIMEIRO atributo:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");

    scanf("%d", &atributo1);

    // MENU DINÂMICO PARA SEGUNDO ATRIBUTO
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");

    if (atributo1 != 1) printf("1 - População\n");
    if (atributo1 != 2) printf("2 - Área\n");
    if (atributo1 != 3) printf("3 - PIB\n");
    if (atributo1 != 4) printf("4 - Pontos Turísticos\n");
    if (atributo1 != 5) printf("5 - Densidade Populacional\n");
    if (atributo1 != 6) printf("6 - PIB per Capita\n");

    scanf("%d", &atributo2);

    // Garantir que são diferentes
    if (atributo1 == atributo2) {
        printf("\nErro: atributos iguais.\n");
        return 0;
    }

    //==============================//
    // FUNÇÃO DE COMPARAÇÃO COM SWITCH
    //==============================//

    // Primeiro atributo
    switch (atributo1) {
        case 1: valor1_c1 = populacao_1; valor1_c2 = populacao_2; break;
        case 2: valor1_c1 = area_1;      valor1_c2 = area_2; break;
        case 3: valor1_c1 = pib_1;       valor1_c2 = pib_2; break;
        case 4: valor1_c1 = turismo_1;   valor1_c2 = turismo_2; break;
        case 5: valor1_c1 = densidade_1; valor1_c2 = densidade_2; break;
        case 6: valor1_c1 = pib_capita_1; valor1_c2 = pib_capita_2; break;
    }

    // Segundo atributo
    switch (atributo2) {
        case 1: valor2_c1 = populacao_1; valor2_c2 = populacao_2; break;
        case 2: valor2_c1 = area_1;      valor2_c2 = area_2; break;
        case 3: valor2_c1 = pib_1;       valor2_c2 = pib_2; break;
        case 4: valor2_c1 = turismo_1;   valor2_c2 = turismo_2; break;
        case 5: valor2_c1 = densidade_1; valor2_c2 = densidade_2; break;
        case 6: valor2_c1 = pib_capita_1; valor2_c2 = pib_capita_2; break;
    }

    //==============================//
    // SOMA FINAL
    //==============================//

    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    //==============================//
    // EXIBIÇÃO DOS RESULTADOS
    //==============================//

    printf("\n=============================\n");
    printf("RESULTADO DA RODADA\n");
    printf("=============================\n");

    printf("\nCidade 1: %s\n", cidade_1);
    printf("Cidade 2: %s\n\n", cidade_2);

    printf("Atributo %d - Carta 1: %.2f | Carta 2: %.2f\n", atributo1, valor1_c1, valor1_c2);
    printf("Atributo %d - Carta 1: %.2f | Carta 2: %.2f\n\n", atributo2, valor2_c1, valor2_c2);

    printf("SOMA FINAL:\n");
    printf("%s = %.2f\n", cidade_1, soma1);
    printf("%s = %.2f\n\n", cidade_2, soma2);

    if (soma1 > soma2) {
        printf("VENCEDORA: Carta 1 - %s!\n", cidade_1);
    } else if (soma2 > soma1) {
        printf("VENCEDORA: Carta 2 - %s!\n", cidade_2);
    } else {
        printf("Resultado: EMPATE!\n");
    }

    return 0;
}