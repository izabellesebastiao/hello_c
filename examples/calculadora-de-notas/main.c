/**
 * Código para calcular a média ponderada de n avaliações
 * entre n alun@s.
 * 
 * @file examples/media-ponderada.c
 * @author Gustavo Simões
 * @date 12 junho 2021
 * 
 * Esse programa assume que todas as avaliações vão de 0 à 10.
 */

#include <stdio.h>

int main()
{
    // Título do programa
    printf("\033[0;33m"); // Definindo texto para a cor amarela
    printf("\n");
    printf("************************");
    printf("\n--> Cálculo da média <--\n");
    printf("************************");
    printf("\033[0;0m"); // Resetando texto para cor padrão

    /**
     * Sessão 1
     * Definição das avaliações
     * 
     * Usuário insere a quantidade de avaliações
     * e, então, qual o peso de cada uma delas.
    */

    printf("\n\n");
    printf("\033[0;36m"); // Definindo texto para a cor azul
    printf("--------------------------------------");
    printf("\n1ª Sessão: Definição das avaliações.\n");
    printf("\033[0;0m"); // Resetando texto para cor padrão

    int numberOfTests;
    printf("\n");
    printf("Qual a quantidade de avaliações?");
    scanf("%i", &numberOfTests);

    float testsGrades[numberOfTests];
    float maxGradeOfTests = 0;

    for (size_t testId = 0; testId < numberOfTests; testId++)
    {
        float momentGrade = 10 - maxGradeOfTests; // o quanto falta para totalizar 10 (nota máxima)
        int nextTestId = testId + 1;

        printf("\n");
        printf("Insira o peso da %iª avaliação (0 a %f):", nextTestId, momentGrade);
        scanf("%f", &testsGrades[testId]);

        // Verifique se o valor inserido é valido
        while ((!((testsGrades[testId] <= momentGrade) && (testsGrades[testId] >= 0))))
        {
            printf("\033[0;31m"); // Definindo texto para a cor vermelho
            printf("! O peso deve ser de 0 à %f:", momentGrade);
            printf("\033[0;0m"); // Resetando texto para cor padrão

            scanf("%f", &testsGrades[testId]);
        }

        maxGradeOfTests = maxGradeOfTests + testsGrades[testId];
    }

    /**
     * Sessão 2
     * Definição da média (nota que separa aprovad@s de reprovad@s)
     * 
     * Usuário insere a média (de 0 à 10);
    */

    printf("\n\n");
    printf("\033[0;36m"); // Definindo texto para a cor ciano
    printf("--------------------------------------");
    printf("\n2ª Sessão: Definição da média.\n");
    printf("\033[0;0m"); // Resetando texto para cor padrão

    float testAverage;
    printf("\n");
    printf("Insira a média geral (0 à %f):", maxGradeOfTests);
    scanf("%f", &testAverage);

    // Verifique se o valor inserido é valido
    while ((!((testAverage <= maxGradeOfTests) && (testAverage >= 0))))
    {
        printf("\033[0;31m"); // Definindo texto para a cor vermelho
        printf("! A média deve ser de 0 à %f:", maxGradeOfTests);
        printf("\033[0;0m"); // Resetando texto para cor padrão
        scanf("%f", &testAverage);
    }

    /**
     * Sessão 3
     * Inserção das notas dos(as) alun@s
    */

    printf("\n\n");
    printf("\033[0;36m"); // Definindo texto para a cor ciano
    printf("--------------------------------------");
    printf("\n3ª Sessão: Inserção das notas dos(as) alunos(as).\n");
    printf("\033[0;0m"); // Resetando texto para cor padrão

    int numberOfStudents;

    printf("\n");
    printf("Qual a quantidade de estudantes avaliados?");
    scanf("%i", &numberOfStudents);

    double studentsTestsResults[numberOfStudents][numberOfTests];

    for (size_t studentId = 0; studentId < numberOfStudents; studentId++)
    {

        int nextStudentId = studentId + 1;

        printf("\n");
        printf("Insira as notas do(a) %iº aluno(a) (0 a 10)", nextStudentId);

        for (size_t testId = 0; testId < numberOfTests; testId++)
        {
            int nextTestId = testId + 1;
            float moment;

            printf("\n");
            printf("%iª avaliação:", nextTestId);
            scanf("%f", &moment);

            // Verifique se o valor inserido é valido
            while ((!((moment <= 10) && (moment >= 0))))
            {

                printf("\033[0;31m"); // Definindo texto para a cor vermelho
                printf("! Insira a nota de 10 a 0:");
                printf("\033[0;0m"); // Resetando texto para cor padrão

                scanf("%f", &moment);
            }

            studentsTestsResults[studentId][testId] = (moment * testsGrades[testId]) / maxGradeOfTests;
        }
    }

    /**
     * Sessão 4
     * Exibição dos resultados
    */

    printf("\n\n");
    printf("\033[0;36m"); // Definindo texto para a cor ciano
    printf("--------------------------------------");
    printf("\n4ª Sessão: Divulgação dos resultados.\n");
    printf("\033[0;0m"); // Resetando texto para cor padrão

    for (size_t studentId = 0; studentId < numberOfStudents; studentId++)
    {
        float momentStudentResult = 0;
        int nextStudentId = studentId + 1;

        for (size_t testId = 0; testId < numberOfTests; testId++)
        {
            momentStudentResult = momentStudentResult + studentsTestsResults[studentId][testId];
        }

        printf("\n\n");
        printf("\033[0;34m"); // Definindo texto para a cor azul
        printf("--------------------------------------");
        printf("\nResultado %iº aluno(a):\n", nextStudentId);
        printf("\033[0;0m"); // Resetando texto para cor padrão

        printf("\n");
        if (momentStudentResult >= testAverage)
        {
            printf("\033[0;32m"); // Definindo texto para a cor verde
            printf("Situação: ");
            printf("Aprovado(a)!");
            printf("\033[0;0m"); // Resetando texto para cor padrão
        }
        else
        {
            printf("\033[0;31m"); // Definindo texto para a cor vermelho
            printf("Situação: ");
            printf("Reprovado(a)!");
            printf("\033[0;0m"); // Resetando texto para cor padrão
        }

        printf("\n");
        printf("Nota: %f", momentStudentResult);

        printf("\n");
        switch ((int)momentStudentResult)
        {
        case 0 ... 3:
            printf("Grupo: D (péssimo)");
            break;
        case 4 ... 6:
            printf("Grupo: C (ruim)");
            break;
        case 7 ... 8:
            printf("Grupo: B (bom)");
            break;
        case 9 ... 10:
            printf("Grupo: A (Excelente)");
            break;

        default:
            break;
        }
    }

    printf("\033[0;33m"); // Definindo texto para a cor amarela
    printf("\n\n\n");
    printf("************************");
    printf("\nFim do programa\n");
    printf("************************");
    printf("\n");
    printf("\033[0;0m"); // Resetando texto para cor padrão

    return 0;
}