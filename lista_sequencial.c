#include <stdio.h>
#include <stdlib.h>
#include "lista_sequencial.h"

void inicializar(struct lista *l, int capacidade)
{
    l->elementos = (int *)malloc(sizeof(int) * capacidade);
    l->particao = 0;
    l->capacidade = capacidade;
}

int inserir_inicio(struct lista *l, int valor)
{
    // movimentando todos os valores para a direita
    // repetindo do fim para o inicio
    int i;
    if (l->particao < l->capacidade)
    {
        for (i = l->particao; i > 0; i--)
        {
            l->elementos[i] = l->elementos[i - 1];
        }

        l->elementos[0] = valor;
        l->particao++;

        return 1;
    }
    else
    {
        return 0;
    }
}

int inserir_fim(struct lista *l, int valor)
{
    if (l->particao < l->capacidade)
    {
        l->elementos[l->particao] = valor;
        l->particao++;
        return 1;
    }
    else
    {
        return 0;
    }
}
int inserirPosicao(int valor, int posicao, struct lista *l)
{
    int i;
    if (l->particao < l->capacidade && posicao <= l->particao && posicao >= 0)
    {
        for (i = l->particao; i > posicao; i--)
        {
            l->elementos[i] = l->elementos[i - 1];
        }
        l->elementos[posicao] = valor;
        l->particao++;
        return 1;
    }
    else
    {
        return 0;
    }
}

int inserirOrdem(struct lista *l, int valor)
{
    if (l->particao < l->capacidade)
    {
        int i, posicao;
        for (i = 0; i < l->particao; i++)
        {
            if (l->elementos[i] > valor)
            {
                for (posicao = l->particao; posicao > i; posicao--)
                {
                    l->elementos[posicao] = l->elementos[posicao - 1];
                }
                l->elementos[i] = valor;
                l->particao++;
                return 1;
            }
        }
        l->elementos[l->particao] = valor;
        l->particao++;
        return 1;
    }
    else
    {
        return 0;
    }
}

void exibir_lista(struct lista *l)
{
    int i;
    for (i = 0; i < l->particao; i++)
    {
        printf("[%d]", l->elementos[i]);
    }
    printf("\n");
}

void reverso(struct lista *l)
{
    int i;
    for (i = l->particao - 1; i >= 0; i--)
    {
        printf("[%d]", l->elementos[i]);
    }
    printf("\n");
}

int removerInicio(struct lista *l)
{
    int i;
    if (l->particao > 0)
    {
        for (i = 0; i <= l->particao - 2; i++)
        {
            l->elementos[i] = l->elementos[i + 1];
        }
        l->particao--;
        return 1;
    }
    else
    {
        return 0;
    }
}

int removerFim(struct lista *l)
{
    if (l->particao > 0)
    {
        l->particao--;
        return 1;
    }
    else
    {
        return 0;
    }
}

int removerPosicao(struct lista *l, int posicao)
{
    int i;
    if (l->particao > posicao)
    {
        for (i = posicao; i <= l->particao - 2; i++)
        {
            l->elementos[i] = l->elementos[i + 1];
        }
        l->particao--;
        return 1;
    }
    else
    {
        return 0;
    }
}

int removerValor(struct lista *l, int n)
{
    int i;
    int posicao = -1;
    for (i = 0; i < l->particao; i++)
    {
        if (l->elementos[i] == n)
        {
            posicao = i;
        }
    }
    if (posicao != -1)
    {
        for (i = posicao; i <= l->particao - 2; i++)
        {
            l->elementos[i] = l->elementos[i + 1];
        }
        l->particao--;
        return 1;
    }
    else
    {
        return 0;
    }
}

int procurar(struct lista *l, int n)
{
    int i;
    for (i = 0; i < l->particao; i++)
    {
        if (l->elementos[i] == n)
        {
            return i;
        }
    }
    if (l->elementos[i] != n)
    {
        return -1;
    }
}

int somatorio(struct lista *l)
{
    int i;
    int somatorio = 0;
    for (i = 0; i < l->particao; i++)
    {
        somatorio = somatorio + l->elementos[i];
    }
    return somatorio;
}

int tamanho(struct lista *l)
{
    return l->particao;
}

int quadrado(struct lista *l)
{
    int i;
    for (i = 0; i < l->particao; i++)
    {
        l->elementos[i] = l->elementos[i] * l->elementos[i];
    }
}

int qtdPrimo(struct lista *l)
{
    int i, n;
    int contador = 0;

    for (i = 0; i < l->particao; i++)
    {
        if (l->elementos[i] > 1)
        {
            int primo = 1;

            for (n = 2; n < l->elementos[i]; n++)
            {
                if (l->elementos[i] % n == 0)
                {
                    primo = 0;
                }
            }

            if (primo == 1)
            {
                contador++;
            }
        }
    }
    return contador;
}
