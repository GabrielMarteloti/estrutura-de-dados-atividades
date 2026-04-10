//Este programa em C recebe uma string digitada pelo usuário
//e retorna essa string invertida utilizando uma pilha renovada manualmente com alocação dinâmica.
//A inversão ocorre devido ao comportamento da pilha (LIFO - Last In, First Out), 
//onde o último elemento inserido é o primeiro a ser removido.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// nó da pilha — guarda o char e aponta pro próximo
typedef struct No {
    char dado;
    struct No *prox;
} No;

// a pilha em si, só precisa saber quem tá no topo
typedef struct {
    No *topo;
} Pilha;

void inicializa(Pilha *p) {
    p->topo = NULL;
}

// empilha: aloca um nó novo e bota no topo
void push(Pilha *p, char c) {
    No *novo = malloc(sizeof(No));
    if (!novo) {
        fprintf(stderr, "Erro: sem memoria\n");
        exit(1);
    }
    novo->dado = c;
    novo->prox = p->topo;
    p->topo = novo;
}

// desempilha: tira do topo e devolve o char
char pop(Pilha *p) {
    if (p->topo == NULL) {
        fprintf(stderr, "Erro: pilha vazia\n");
        exit(1);
    }
    No *tmp = p->topo;
    char c = tmp->dado;
    p->topo = tmp->prox;
    free(tmp);
    return c;
}

int vazia(Pilha *p) {
    return p->topo == NULL;
}

int main(void) {
    char entrada[256];

    printf("Digite uma string: ");
    fgets(entrada, sizeof(entrada), stdin);

    // remove o \n que o fgets deixa no final
    int tam = strlen(entrada);
    if (tam > 0 && entrada[tam - 1] == '\n') {
        entrada[tam - 1] = '\0';
        tam--;
    }

    Pilha p;
    inicializa(&p);

    // empilha letra por letra
    for (int i = 0; i < tam; i++)
        push(&p, entrada[i]);

    // desempilha direto no printf — sem vetor auxiliar
    printf("String invertida: ");
    while (!vazia(&p))
        putchar(pop(&p));
    putchar('\n');

    return 0;
}

