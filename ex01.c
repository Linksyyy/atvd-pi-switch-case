#include <stdio.h>
#include <ctype.h>

int main() {
    float valor, resultado;
    char opcao;

    printf("SISTEMA DE CONVERSAO DE MEDIDAS\n");
    printf("Escolha a conversão desejada:\n");
    printf("K - Quilômetros para Milhas\n");
    printf("M - Milhas para Quilômetros\n");
    printf("Q - Quilogramas para Libras\n");
    printf("P - Metros para Pés\n");
    printf("Opção: ");
    scanf(" %c", &opcao);

    printf("Digite o valor (quantitativo) para converter: ");
    scanf("%f", &valor);

    opcao = toupper(opcao);

    switch (opcao) {
        case 'K':
            resultado = valor * 0.621371;
            printf("Resultado: %.2f km equivalem a %.4f milhas.\n", valor, resultado); break;

        case 'M':
            resultado = valor / 0.621371;
            printf("Resultado: %.2f milhas equivalem a %.4f km.\n", valor, resultado); break;

        case 'Q':
            resultado = valor * 2.20462;
            printf("Resultado: %.2f kg equivalem a %.4f libras.\n", valor, resultado); break;

        case 'P':
            resultado = valor * 3.28084;
            printf("Resultado: %.2f metros equivalem a %.4f pés.\n", valor, resultado); break;

        default:
            printf("Opção inválida! Tente K, M, Q ou P.\n");
    }

    return 0;
}
