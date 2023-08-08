#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

void menu_opcoes()
{
    printf("Selecione uma opcao: \n\n");
    printf("\t 0 - inicializar\n");
    printf("\t 1 - inserir no inicio\n");
    printf("\t 2 - inserir no fim\n");
    printf("\t 3 - inserir na posicao\n");
    printf("\t 4 - inserir na ordem\n");
    printf("\t 5 - exibir lista\n");
    printf("\t 6 - exibir reverso\n");
    printf("\t 7 - remover inicio\n");
    printf("\t 8 - remover fim\n");
    printf("\t 9 - remover posicao\n");
    printf("\t 10 - remover valor\n");
    printf("\t 11 - procurar\n");
    printf("\t 12 - somatorio\n");
    printf("\t 13 - tamanho\n");
    printf("\t 14 - quadrado\n");
    printf("\t 15 - quantidade de primos\n");
    printf("\t 99 - sair\n");
}

int main(int argc, char *argv)
{
    int opcao;
    int valor;
    int capacidade;
    int posicao;

    // declaracao das listas
    struct lista *l1;
    struct lista *l_ordenada;

    l1 = (struct lista *)malloc(sizeof(struct lista));
    l_ordenada = (struct lista *)malloc(sizeof(struct lista));

    // lista ordenada para testes da função inserirOrdem
    inicializar(l_ordenada, 8);
    inserir_fim(l_ordenada, 10);
    inserir_fim(l_ordenada, 20);
    inserir_fim(l_ordenada, 30);
    inserir_fim(l_ordenada, 40);
    inserir_fim(l_ordenada, 50);

    // recebendo opcoes do usuario
    while (1)
    {
        // exibindo opcoes
        menu_opcoes();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 0:
            printf("Digite a capacidade da lista:\n");
            scanf("%d", &capacidade);
            inicializar(l1, capacidade);
            break;
        case 1:
            printf("Digite o valor a ser inserido no inicio:\n");
            scanf("%d", &valor);
            if (inserir_inicio(l1, valor) == 1)
            {
                printf("Valor inserido no inicio!\n");
                exibir_lista(l1);
            }
            else
            {
                printf("Valor nao inserido!\n");
            }
            break;
        case 2:
            printf("Digite o valor a ser inserido no fim:\n");
            scanf("%d", &valor);
            if (inserir_fim(l1, valor) == 1)
            {
                printf("Valor inserido no fim!\n");
                exibir_lista(l1);
            }
            else
            {
                printf("Valor nao inserido!\n");
            }
            break;
        case 3:
            printf("Digite o valor a ser inserido na posicao:\n");
            scanf("%d", &valor);
            printf("Digite a posicao:\n");
            scanf("%d", &posicao);
            if (inserirPosicao(valor, posicao, l1) == 1)
            {
                printf("Valor inserido na posicao!\n");
                exibir_lista(l1);
            }
            else
            {
                printf("Valor nao inserido!\n");
            }
            break;
        case 4:
            printf("Lista ordenada atual:\n");
            exibir_lista(l_ordenada);

            printf("Digite o valor a ser inserido na ordem:\n");
            scanf("%d", &valor);

            if (inserirOrdem(l_ordenada, valor) == 1)
            {
                printf("Valor inserido!\n");
                printf("Lista ordenada atualizada:\n");
                exibir_lista(l_ordenada);
            }
            else
            {
                printf("Valor nao inserido! (lista cheia)\n");
            }
            break;
        case 5:
            printf("Lista 1:\n");
            exibir_lista(l1);
            break;
        case 6:
            printf("Lista na ordem reversa:\n");
            reverso(l1);
            break;
        case 7:
            if (removerInicio(l1) == 1)
            {
                printf("Inicio removido!\n");
                printf("Lista atualizada:\n");
                exibir_lista(l1);
            }
            else
            {
                printf("Inicio nao removido!\n");
            }
            break;
        case 8:
            if (removerFim(l1) == 1)
            {
                printf("Fim removido!\n");
                printf("Lista atualizada:\n");
                exibir_lista(l1);
            }
            else
            {
                printf("Fim nao removido!\n");
            }
            break;
        case 9:
            printf("Digite a posicao para remover:\n");
            scanf("%d", &posicao);
            if (removerPosicao(l1, posicao) == 1)
            {
                printf("Posicao removida!\n");
                printf("Lista atualizada:\n");
                exibir_lista(l1);
            }
            else
            {
                printf("Posicao nao removida!\n");
            }
            break;
        case 10:
            printf("Digite o valor para remover:\n");
            scanf("%d", &valor);
            if (removerValor(l1, valor) == 1)
            {
                printf("Valor removido!\n");
                printf("Lista atualizada:\n");
                exibir_lista(l1);
            }
            else
            {
                printf("Nao foi possivel remover o valor digitado!\n");
            }
            break;
        case 11:
            printf("Digite o valor para procurar:\n");
            scanf("%d", &valor);
            if (procurar(l1, valor) == -1)
            {
                printf("Valor nao encontrado!\n");
            }
            else
            {
                printf("Valor encontrado na posicao: %d!\n", procurar(l1, valor));
            }
            break;
        case 12:
            printf("Somatorio dos valores da lista:\n %d\n", somatorio(l1));
            break;
        case 13:
            printf("Tamanho da lista: %d\n", tamanho(l1));
            break;
        case 14:
            quadrado(l1);
            printf("Quadrado dos valores da lista:\n");
            exibir_lista(l1);
            break;
        case 15:
            printf("Quantidade de primos encontrada:\n %d\n", qtdPrimo(l1));
            break;
        case 99:
            exit(0);
        default:
            printf("Opcao invalida!\n");
        }
    }
}
