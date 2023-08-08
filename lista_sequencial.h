#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

struct lista
{
        int *elementos;
        int particao;
        int capacidade;
};

void inicializar(struct lista *l, int capacidade);
int inserir_inicio(struct lista *l, int valor);
int inserir_fim(struct lista *l, int valor);
int inserirPosicao(int valor, int posicao, struct lista *l);
int inserirOrdem(struct lista *l, int valor);
void exibir_lista(struct lista *l);
void reverso(struct lista *l);
int removerInicio(struct lista *l);
int removerFim(struct lista *l);
int removerPosicao(struct lista *l, int posicao);
int removerValor(struct lista *l, int n);
int procurar(struct lista *l, int n);
int somatorio(struct lista *l);
int tamanho(struct lista *l);
int quadrado(struct lista *l);
int qtdPrimo(struct lista *l);

#endif // LISTA_SEQUENCIAL_H
