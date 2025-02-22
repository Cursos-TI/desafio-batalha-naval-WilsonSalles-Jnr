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
    int LINHA = 10, COLUNA = 10;

    int pivot = 3;

    int tabuleiro[LINHA][COLUNA];

    // Próxima sequência é de 3, inicio é igual a (5 - área atingida) / 2
    int habilidadeCone[2] = {3, 5};
    int habilidadeOctaedro[2] = {3, 0};
    int habilidadeCruz[2] = {5, 0};

    int NAVIOS_MAX = 1;

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
        tabuleiro[linha - 1][coluna - 1] = 3;
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

    int linhaAtaque, colunaAtaque;
    printf("Escolha uma área para disparar atacar: \n");
    printf("Linha: ");
    scanf("%i", &linhaAtaque);
    printf("Coluna: ");
    scanf("%i", &colunaAtaque);

    linhaAtaque--;
    colunaAtaque--;
    tabuleiro[linhaAtaque][colunaAtaque] = 1;

    int opcao;
    int *habilidade;

    printf("Seleciona a habilidade: \n");
    printf("1 - Cone [padrão] \n");
    printf("2 - Octaedro \n");
    printf("3 - Cruz \n");
    scanf("%i", &opcao);

    switch (opcao)
    {
    case 1:
        habilidade = habilidadeCone;
        break;
    case 2:
        habilidade = habilidadeOctaedro;
        break;
    case 3:
        habilidade = habilidadeCruz;
        break;

    default:
        habilidade = habilidadeCone;
        break;
    }

    for (int i = 0; i < 2; i++)
    {
        int jLoopCount = 0;
        tabuleiro[linhaAtaque + 1 + i][colunaAtaque] = 1;
        for (int j = 0; j < habilidade[i] - jLoopCount; j++)
        {
            tabuleiro[linhaAtaque + 1 + i][colunaAtaque] = 1;
            if (colunaAtaque - (1 + j) >= 0)
            {
                tabuleiro[linhaAtaque + 1 + i][colunaAtaque - (1 + j)] = 1;
            }
            if (colunaAtaque + (1 + j) < COLUNA)
            {
                tabuleiro[linhaAtaque + 1 + i][colunaAtaque + (1 + j)] = 1;
            }
            jLoopCount += 2;
        }
    }

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
