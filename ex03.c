#include <stdio.h>
#include <ctype.h>

#define LITROS_NO_TANQUE 100.0

double custoDaViagem(double litros_consumidos, double preco_litro) {
    return litros_consumidos * preco_litro;
}

double consumoMedio(double distancia_percorrida, double litros_consumidos) {
    if (litros_consumidos == 0.0) {
        printf("\nErro: o valor nao pode ser zero.\n");
        return 0.0;
    }
    return distancia_percorrida / litros_consumidos; 
}

double autonomiaEstimada(double consumo_medio) {
    return LITROS_NO_TANQUE * consumo_medio; 
}

double custoKm(double custo_total, double distancia_percorrida) {
    if (distancia_percorrida == 0.0) {
        printf("\nErro: o valor nao pode ser zero.\n");
        return 0.0;
    }
    return custo_total / distancia_percorrida; 
}

int main() {

    double valor1, valor2;


    char tipoDeCalculo;
    printf("Que tipo de cálculo deseja fazer?");
    printf("\n'C' - Custo da viagem,");  
    printf("\n'M' -  Consumo Médio,");
    printf("\n'A' - Autonomia Estimada, ");
    printf("\n'Q' - Custo por quilômetro \n");

    scanf(" %c", &tipoDeCalculo);
    tipoDeCalculo = toupper(tipoDeCalculo);

    switch(tipoDeCalculo) {
        case 'C':
            printf("Digite os litros consumidos: ");
            scanf("%lf", &valor1);

            printf("Digite o preço por litro: ");
            scanf("%lf", &valor2);

            printf("O custo da viagem foi de: R$%.2lf", custoDaViagem(valor1, valor2));
            break;

        case 'M':
            printf("Digite a distância percorrida (km): ");
            scanf("%lf", &valor1);

            printf("Digite os litros consumidos (l): ");
            scanf("%lf", &valor2);

            printf("O consumo médio da viagem foi de: %.2lf km/l", consumoMedio(valor1, valor2));
            break;

        case 'A':

            printf("Digite o consumo médio do veículo (km/l): ");
            scanf("%lf", &valor2);

            printf("A autonomia estimada é de: %.2lf km", autonomiaEstimada(valor2));
            break;

        case 'Q':
            printf("Digite o custo total da viagem (R$): ");
            scanf("%lf", &valor1);

            printf("Digite a distância percorrida (km): ");
            scanf("%lf", &valor2);

            printf("O custo por quilômetro é de: R$%.2lf/km", custoKm(valor1, valor2));
            break;

        default:
            printf("Opção inválida");
    }
    return 0;
}
