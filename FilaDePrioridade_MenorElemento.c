#include <stdio.h>
#include <stdlib.h>

// Variável global para definir o tamanho máximo da fila
#define tamanhoMaximo 50

// Definição da fila usando vetor
typedef struct {
    int dados[tamanhoMaximo]; // Pode ser dinâmico, mas o objetivo é ser um array com tamanho fixo
    int tamanho;
} tipoPriorityQueue;

// Função para criar uma fila
tipoPriorityQueue* criaFila() {
    tipoPriorityQueue* fila = (tipoPriorityQueue*) malloc(sizeof(tipoPriorityQueue));
    if (fila == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    fila->tamanho = 0;
    return fila;
}
// Métodos da fila de prioridade

// Função para inserir com prioridade (min-heap) -> sempre o topo é o menor valor
void inserir(tipoPriorityQueue* fila, int valor) {
    if (fila->tamanho == tamanhoMaximo) {
        printf("Fila cheia!\n");
        return;
    }
    int i = fila->tamanho++;
    fila->dados[i] = valor;

    // Ajusta o heap para cima
    while (i > 0 && fila->dados[i] < fila->dados[(i - 1) / 2]) {
        int tmp = fila->dados[i];
        fila->dados[i] = fila->dados[(i - 1) / 2];
        fila->dados[(i - 1) / 2] = tmp;
        i = (i - 1) / 2;
    }
}

// Remove e retorna o elemento de maior prioridade (menor valor no min-heap)
int remover(tipoPriorityQueue* fila) {
    if (fila->tamanho == 0) {
        printf("Fila vazia!\n");
        return -1;
    }

    // Remove a raiz (menor valor)
    int raiz = fila->dados[0];
    fila->dados[0] = fila->dados[--fila->tamanho];

    // Ajusta o heap para baixo
    int i = 0;
    while (1) {
        int menor = i;
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;

        // Calcula os índices dos filhos esquerdo e direito
        if (esq < fila->tamanho && fila->dados[esq] < fila->dados[menor]) menor = esq;
        if (dir < fila->tamanho && fila->dados[dir] < fila->dados[menor]) menor = dir;

        if (menor == i) break; // Se algum filho for menor, marca ele como o menor

        // Se já está no lugar certo (menor que os filhos), termina, se não, troca o nó com o menor filho
        int tmp = fila->dados[i];
        fila->dados[i] = fila->dados[menor];
        fila->dados[menor] = tmp;

        i = menor;
    }

    return raiz;
}

// Exibe a fila de prioridade
void exibirFila(tipoPriorityQueue* fila) {
    printf("Fila: ");
    int i = 0;
    while (i < fila->tamanho){
        printf("%d ", fila->dados[i]);
        i++;
    }
    printf("\n");
}


void main(){

tipoPriorityQueue* fila = criaFila();
int valor;
int op;

do {
    printf("\nSelecione uma opcao:\n1-Inserir elemento na fila;\n2-Exibir fila;\n3-Remover um elemento da fila;\n0-Sair do programa.\n");
    scanf("%d", &op);

    switch (op) {
        case 1:
            printf("Digite o valor que deseja inserir: ");
            scanf("%d",&valor);
            inserir(fila, valor);
        break;
        case 2:
            exibirFila(fila);
        break;
        case 3:
             printf("Removido: %d\n", remover(fila));
        break;
        case 0:
            op = 0;
        break;
    }
    } while(op != 0);
}
