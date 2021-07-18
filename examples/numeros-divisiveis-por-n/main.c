/**
 * Código que sinaliza os números divisíveis por um 
 * número inteiro n dentro de um intervado 
 * Inteiro [x, y] (em que x e y pertencem ao intervalo).
 * 
 * @file examples/numeros-divisiveis-por-3/main.c
 * @author Gustavo Simões
 * @date 18 junho 2021
 * 
 */

#include <stdio.h>

int main()
{
    // Declaração das variáveis
    int n, x, y;

    // Título do código
    // Explicação ao usuário
    printf("Sinalizarei os números divisíveis por \033[0;36mn\033[0;0m em um intervalo Inteiro [\033[0;36m x \033[0;0m, \033[0;36m y \033[0;0m]");
    printf("\n");

    // Inserção de n
    printf("Qual valor de \033[0;36mn\033[0;0m? ");
    scanf("%i", &n);

    // Inserção de x
    printf("Qual o início do intervalo? (\033[0;36mx\033[0;0m) ");
    scanf("%i", &x);

    // Inserção de y
    printf("Qual o final do intervalo? (\033[0;36my\033[0;0m) ");
    scanf("%i", &y);

    // Para cada número no intervalo
    for (size_t i = 0; i < (y - x); i++) // x - y = quantidade de números no intervalo
    {
        int currentValue = x + i; // Começo do intervalo mais i (0, 1, 2, 3...)

        /* se o número é dividido por n e tiver resto 0, 
        portanto esse número é divisível por n*/
        if (currentValue % n == 0)
        {
            printf("\n");
            printf("\033[0;36m%i\033[0;0m é divisível por %i", currentValue, n);
        }
    }

    printf("\n"); // "Limpando" o terminal
    return 0;
}