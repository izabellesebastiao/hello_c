/**
 * Código que intercala os valores de dois vetores
 * 
 * @file /examples/intercalacao-dos-vetores/main.c
 * @author Gustavo Simões
 * @date 03 agosto 2021
 * 
 */

#include <stdio.h>

int main()
{
    // Título do programa
    printf("\nIntercalador de vetores \n");

    int a[5] = {1, 2, 3, 4, 5};  // Vetor A
    int b[5] = {6, 7, 8, 9, 10}; // Vetor B

    // Exibição dos vetores A e B
    printf("\nVetor A:  {1, 2, 3, 4, 5};");
    printf("\nVetor B:  {6, 7, 8, 9, 10};");

    int c[10]; // Vetor C: resultado

    for (int i = 0; i < 10; i++) // Para cada item no vetor C
    {
        // Se i for par, c[i] recebe um valor de A
        // Se i for impar, c[i] recebe um valor de B
        c[i] = i % 2 == 0 ? a[i / 2] : b[i / 2];
    }

    // Exibição do resultado do código
    printf("\n\nO vetor intercalado (C) é: { ");

    for (int i = 0; i < 10; i++)
    {
        printf("%i, ", c[i]);
    }
    printf("};\n");

    // Retorno main()
    return 0;
}