#include <stdio.h>

double calculateSimpleDivision(double totalExpense, int peopleCount);
int calculateProportionalDivision(double totalExpense, int p1, int p2, int p3, int p4, double *v1, double *v2, double *v3, double *v4);
int calculateWeightedDivision(double totalExpense, int w1, int w2, int w3, int w4, double *v1, double *v2, double *v3, double *v4);

int main() {
  double totalExpense;
  int option;
  double value1, value2, value3, value4;
  int percent1, percent2, percent3, percent4;
  int weight1, weight2, weight3, weight4;

  printf("Qual foi a despesa total?:\n-> ");
  scanf("%lf", &totalExpense);
  printf("Como deseja fazer a divisao?:\n\t(1) Divisao igual simples\n\t(2) Divisao proporcional ao consumo\n\t(3) Rateio com pesos diferentes\n-> ");
  scanf("%d", &option);

  switch(option) {
    case 1: {
      double average = calculateSimpleDivision(totalExpense, 4);
      if (average == -1) {
        printf("ERRO: Divisao por zero.\n");
        return -1;
      }
      printf("O preco que cada um dos 4 vai ter que pagar é R$ %.2lf\n", average);
      break;
    }
    case 2: {
      printf("Digite os percentuais de consumo (ex: 25 25 25 25):\n-> ");
      scanf("%d %d %d %d", &percent1, &percent2, &percent3, &percent4);
      if (calculateProportionalDivision(totalExpense, percent1, percent2, percent3, percent4, &value1, &value2, &value3, &value4) == -1) {
	printf("ERRO: Percentual negativo ou soma dos percentuais é negativo ou nulo.\n");
        return -1;
      }
      printf("Valores a pagar:\n");
      printf("Estudante 1: R$ %.2lf\n", value1);
      printf("Estudante 2: R$ %.2lf\n", value2);
      printf("Estudante 3: R$ %.2lf\n", value3);
      printf("Estudante 4: R$ %.2lf\n", value4);
      break;
    }
    case 3: {
      printf("Digite os pesos de consumo (ex: 1 1 1 1):\n-> ");
      scanf("%d %d %d %d", &weight1, &weight2, &weight3, &weight4);
      if (calculateWeightedDivision(totalExpense, weight1, weight2, weight3, weight4, &value1, &value2, &value3, &value4) == -1) {
	printf("ERRO: Soma dos pesos zero ou negativa.\n");
        return -1;
      }
      printf("Valores a pagar:\n");
      printf("Estudante 1: R$ %.2lf\n", value1);
      printf("Estudante 2: R$ %.2lf\n", value2);
      printf("Estudante 3: R$ %.2lf\n", value3);
      printf("Estudante 4: R$ %.2lf\n", value4);
      break;
    }
    default:
      printf("ERRO: Opcao invalida.\n");
      return -1;
  }

  return 0;
}

double calculateSimpleDivision(double totalExpense, int peopleCount) {
  if(peopleCount == 0)
    return -1;
  return totalExpense / peopleCount;
}

int calculateProportionalDivision(double totalExpense, int p1, int p2, int p3, int p4, double *v1, double *v2, double *v3, double *v4) {
  if (p1 < 0 || p2 < 0 || p3 < 0 || p4 < 0) return -1;
  int sumPercent = p1 + p2 + p3 + p4;
  if (sumPercent <= 0) return -1;

  *v1 = (totalExpense * p1) / sumPercent;
  *v2 = (totalExpense * p2) / sumPercent;
  *v3 = (totalExpense * p3) / sumPercent;
  *v4 = (totalExpense * p4) / sumPercent;
  return 0;
}

int calculateWeightedDivision(double totalExpense, int w1, int w2, int w3, int w4, double *v1, double *v2, double *v3, double *v4) {
  int sumWeight = w1 + w2 + w3 + w4;
  if (sumWeight <= 0) return -1;

  double valuePerWeight = totalExpense / sumWeight;
  *v1 = valuePerWeight * w1;
  *v2 = valuePerWeight * w2;
  *v3 = valuePerWeight * w3;
  *v4 = valuePerWeight * w4;
  return 0;
}
