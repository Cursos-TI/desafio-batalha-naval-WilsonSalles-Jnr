#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void validaLinha(int LIMITE, int input)
{
}

int main()
{
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Valor máximo de linha e coluna
    int LINHA = 5, COLUNA = 5;

    int tabuleiro[LINHA][COLUNA];
    int NAVIOS_MAX = 3;

    // Definindo todas as casas como 0;
    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }
    do
    {
        int linha, coluna;
        printf("Posicione os navios (%i Restantes):\n", NAVIOS_MAX);

        do
        {
            printf("Linha: ");
            scanf("%i", &linha);
            while (linha > LINHA || linha <= 0)
            {
                printf("O limite é de %d linhas, insira outro valor: ", LINHA);
                scanf("%i", &linha);
            };

            printf("Coluna: ");
            scanf("%i", &coluna);
            while (coluna > COLUNA || coluna <= 0)
            {
                printf("O limite é de %d linhas, insira outro valor: ", COLUNA);
                scanf("%i", &coluna);
            };
            if (tabuleiro[linha - 1][coluna - 1])
            {
                printf("Navio já posicionado, escolha outra posição!\n");
            }

        } while (tabuleiro[linha - 1][coluna - 1]);
        tabuleiro[linha - 1][coluna - 1] = 1;
        NAVIOS_MAX--;
    } while (NAVIOS_MAX);

    printf("Seu tabuleiro: \n");
    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            printf("%i ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1

    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
