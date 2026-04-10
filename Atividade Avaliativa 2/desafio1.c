#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char dado;
    struct Node* proximo;
} Node;

int isEmpty(Node* topo) {
    return topo == NULL;
}

void push(Node** topo, char valor) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    if (novoNo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    novoNo->dado = valor;
    novoNo->proximo = *topo;
    *topo = novoNo;
}

char pop(Node** topo) {
    if (isEmpty(*topo)) {
        return '\0';
    }
    Node* aux = *topo;
    char valor = aux->dado;
    *topo = aux->proximo;
    free(aux);
    return valor;
}

int matches(char abertura, char fechamento) {
    if (abertura == '(' && fechamento == ')') return 1;
    if (abertura == '[' && fechamento == ']') return 1;
    if (abertura == '{' && fechamento == '}') return 1;
    return 0;
}

int main() {

    char expressao[100];  
    Node* pilha = NULL;
    int valida = 1;

    printf("Verificador de epxressao \n");
    printf("Digite a expressao: ");

    scanf("%99s", expressao);

    for (int i = 0; expressao[i] != '\0'; i++) {
        char atual = expressao[i];

        // Se for abertura
        if (atual == '(' || atual == '[' || atual == '{') {
            push(&pilha, atual);
        } 
        // Se for fechamento
        else if (atual == ')' || atual == ']' || atual == '}') {
            if (isEmpty(pilha)) {
                valida = 0;
                break;
            }
            char topo = pop(&pilha);
            if (!matches(topo, atual)) {
                valida = 0;
                break;
            }
        }
    }

    // Se ainda tiver elementos na pilha, é inválido
    if (!isEmpty(pilha)) {
        valida = 0;
    }

    while (!isEmpty(pilha)) {
        pop(&pilha);
    }

    if (valida) {
        printf("\nResultado: A expressao e valida.\n");
    } else {
        printf("\nResultado: A expressao e invalida.\n");
    }

    return 0;
}