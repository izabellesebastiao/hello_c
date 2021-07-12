/**
 * @file examples/sum-two-numbers.c
 * @author Gustavo Simões
 * @date 02 junho 2021
 * 
 * @brief Código para somar dois números inteiros inseridos.
 */

// Biblioteca cabeçalho padrão de entrada/saída
#include <stdio.h>

/// Main function
int main()
{
    // Declarando as variáveis n1, n2 e sum como inteiras
    int n1, n2, sum;

    // Exibir mensagem inicial
    printf("\nBora calcular a soma de dois números inteiros?! \n\n");

    // Primeira atribuição
    printf("Insira o primeiro número ");
    scanf("%i", &n1); // Atribuir o primeiro número à n1

    // Segunda atribuição
    printf("Insira o segundo número ");
    scanf("%i", &n2); // Atribuir o segundo número à n2

    // Somando n1 e n2 e atribuindo à variável sum
    sum = n1 + n2;

    // Exibindo o resultado
    printf("\033[0;34m"); // Definindo texto para a cor azul
    printf("\n\nA soma entre %i e %i é %i\n\n", n1, n2, sum);
    printf("\033[0;0m"); // Resetando texto para cor padrão

    return 0;
}