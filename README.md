Desafio 1
Verificador de Expressões com Pilha em C
Este projeto implementa um verificador de expressões utilizando pilha dinâmica em linguagem C. O objetivo é analisar se os símbolos de agrupamento — (), [] e {} — estão corretamente balanceados em uma expressão.

Como funciona:
O programa utiliza uma estrutura de dados do tipo pilha, implementada com listas encadeadas. A lógica é baseada no seguinte:

Cada vez que um símbolo de abertura ((, [, {) é encontrado, ele é empilhado.
Quando um símbolo de fechamento (), ], }) aparece, o programa verifica:
Se a pilha está vazia → a expressão já é inválida.
Caso contrário, remove o topo da pilha e verifica se os símbolos correspondem corretamente.
Validação da expressão

Ao final da leitura da expressão:
Se todos os símbolos foram corretamente fechados e a pilha estiver vazia → a expressão é válida 
Se houver algum erro de correspondência ou ainda existirem elementos na pilha → a expressão é inválida 

Principais funções
push: insere um elemento no topo da pilha
pop: remove o elemento do topo
isEmpty: verifica se a pilha está vazia
matches: confere se os símbolos de abertura e fechamento são compatíveis


Desafio 2: 
Inversão de String com Pilha em C

Descrição:

Este programa em C recebe uma string digitada pelo usuário e retorna essa string invertida utilizando uma pilha renovada manualmente com alocação dinâmica.

A inversão ocorre devido ao comportamento da pilha (LIFO - Last In, First Out), onde o último elemento inserido é o primeiro a ser removido.

Funcionamento: O usuário digita uma string Cada caractere é empilhado Os caracteres são desempilhados e impressos O resultado é uma string invertida

Estrutura: struct No: representa um nó da pilha (armazena um caractere e um ponteiro) struct Pilha: representa a pilha (guarda o topo)

Funções principais: push: inserir um elemento na pilha pop: remover e retorna o elemento do topo vazio: verifica se a pilha está vazia inicializa: inicializa a pilha

Restrições atendidas não utiliza funções prontas para inversor string não utiliza vetor auxiliar manipulação feita apenas com pilha

Exemplo de uso:

Entrada: abc

senhor: cba

Compilação e execução: gcc programa.c -o programa ./programa

Conceitos utilizados: Estrutura de dados: Pilha (Stack) Alocação dinâmica (malloc / free) Ponteiros Lista encadeada
