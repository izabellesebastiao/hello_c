/**
 * Código para calcular o determinante de uma matriz 3x3
 * 
 * @file /examples/calculadora-determinante-matriz/main.c
 * @author Gustavo Simões
 * @date 28 junho 2021
 * 
 */

#include <stdio.h>

int main()
{

    // Título do programa
    printf("\033[0;33m"); // Definindo texto para a cor amarela
    printf("************************");
    printf("\n--> Caluculadora determinante matriz 3x3 <--\n");
    printf("************************");
    printf("\033[0;0m"); // Resetando texto para cor padrão
    printf("\n\n");

    // Definição da matriz m
    float m[3][3];

    // Para cada elemento da matriz... (matriz 3x3 = 9 elementos)
    for (size_t i = 1; i < 10; i++)
    {
        /* 
            Queremos que a seguinte sequência apareça para o usuário:
            a11, a12, a13, a21, a22, a23, a31, a32, a33.

            Para isso, dividimos os números de 1 a 9 em três grupos 
            A (1, 2, 3), 
            B (4, 5, 6) e 
            C (7, 8, 9).

            Assim, 

            para n1: 
            
            Se i for divisível por 3 (3, 6, 9), então basta 
            n1 exibir i/3; 
            Caso contrário, basta dividir o i/3 e somar 1.

            Ex1: Para saber se 9 faz parte do grupo A, B ou C, verificamos 
            se 9 é divisível por 3 (9 % 3), como sim, basta obeter a divisão
            9 por 3, que resultará em 3, portanto, grupo C.

            Ex2: Agora, para saber qual grupo o número 7 participa, verificamos 
            se 7 é divisível por 3 e, como não é, dividimos 7 por 3 que resulta no número 2.
            Isso erroneamente poderia indicar que 7 faz parte do grupo B, 
            mas é importante perceber que números do grupo A quando divisíveis por 3
            ou resultam em 0 (caso do 1 e 2) ou em 1 (caso do 3), assim, como a contagem 
            começa com 0 (para o número 1), devemos somar 1 nos números não divisíveis por 3,
            de modo que na divisão de 7 por 3, somamos 1 ao resultado, obtendo o 
            número 3, classificando 7 no grupo C.


            para n2:

            O caso é parecido, mas agora os grupos são:
            
            A (1, 4, 7),
            B (2, 5, 8) e
            C (3, 6, 9).

            Ou seja, pegamos os primeiros membros dos grupos anterior e criamos 
            outro grupo, os segundos membros do grupo anterior...
            
            Assim, caso o número seja divisível por 3 (i % 3 == 0), 
            n2 deve receber 3 e, caso não seja, deve receber o resto da divisão por 3
            (i % 3).

            Para o grupo A, percebe-se que o resto da divisão por 3 é sempre 1.
            Ex3: 7 dividido por 3 dá 2 com resto 1.

            Para o grupo B, o resto da divisão por 3 é sempre 2.

            E para o grupo C, o resto da divisão por 3 é sempre 0, portanto,
            precisa-se somar 3, ou, então, declarar que n2 recebe o valor 3.

        */

        int n1 = i % 3 == 0 ? i / 3 : i / 3 + 1;
        int n2 = i % 3 == 0 ? 3 : i % 3;

        printf("a%i%i: ", n1, n2);
        scanf("%f", &m[n1 - 1][n2 - 1]);
    }
    /*

        A matriz m 3x3 tem formato genérico:

        a b c 
        d e f 
        g h i 

        ou, seguindo a linguagem matemática 
        (usada na estrutura for(){} acima):

        a11  a12  a13 
        a21  a22  a23
        a31  a32  a33


        Assim, para se calcular o determinante de m
        pela regra de Sarrus, temos:

        det m = (aei + bfg + cdh) – (ceg + afh + dbi)
    */

    float result =
        ((m[0][0] * m[1][1] * m[2][2]) +

         (m[1][0] * m[2][1] * m[0][2]) +

         (m[2][0] * m[0][1] * m[1][2])) -

        ((m[2][0] * m[1][1] * m[0][2]) +

         (m[0][0] * m[2][1] * m[1][2]) +

         (m[0][1] * m[1][0] * m[2][2]));

    // Exibção do resultado
    printf("\033[0;36m"); // Definindo texto para a cor ciano
    printf("\nO determinante da matriz é: %g \n\n", result);
    printf("\033[0;0m"); // Resetando texto para cor padrão
}
