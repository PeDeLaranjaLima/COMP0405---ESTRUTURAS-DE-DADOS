#include <stdio.h>
#include <stdlib.h>

//Código para iniciar o estudo da implementação de árvore binária dinamicamente estruturada

typedef struct node{
int dado;
struct node *pai;
struct node *filhoEsq;
struct node *filhoDir;
}tipoNode;

tipoNode *achou;

/*Função para criar um nó*/
tipoNode* criaNo(int n, tipoNode* pai){
tipoNode *novo;
novo = (tipoNode*) malloc(sizeof(tipoNode));
novo->dado = n;
novo->filhoDir = NULL;
novo->filhoEsq = NULL;
novo->pai = pai;
return novo;
}

int temFilhoEsq(tipoNode *no){
if(no->filhoEsq != NULL)
    return 1;
else
    return 0;
}

int temFilhoDir(tipoNode *no){
if(no->filhoDir != NULL)
    return 1;
else
    return 0;
}

/* Funções criadas pelo aluno: Gabriel Lima Dantas */

typedef struct {
    int encontrou; //Retorna 1 caso o nó já exista e 0 caso não tenha sido encontrado
    tipoNode* noOuPai;
    char tipoFilho;
} tipoVolta;

void exibePosOrdem(tipoNode *atual) {
    if (atual){
      exibePosOrdem(atual->filhoEsq);
      exibePosOrdem(atual->filhoDir);
      printf("%8d", atual->dado);
    }
}

void exibeInOrdem(tipoNode *atual) {
    if (atual){
      exibeInOrdem(atual->filhoEsq);
      printf("%8d", atual->dado);
      exibeInOrdem(atual->filhoDir);
    }
}

void exibePreOrdem(tipoNode *atual) {
    if (atual){
      printf("%8d", atual->dado);
      exibePreOrdem(atual->filhoEsq);
      exibePreOrdem(atual->filhoDir);
    }
}

char getDirecao(tipoNode *filho) {
    if(filho) {
        tipoNode *pai = (tipoNode*) malloc(sizeof(tipoNode));
        pai = filho->pai;
        if (filho == pai->filhoDir) return 'd';
        if (filho == pai->filhoEsq) return 'e';
    } else {
        return '\0';
    }
}

// Função explicada na aula
tipoNode* busque(tipoNode *raiz, int procura){
    if(raiz){
        if(raiz->dado == procura) return raiz;

        tipoNode *r1 = busque(raiz->filhoEsq, procura);

        if (r1) return r1;

        tipoNode *r2 = busque(raiz->filhoDir, procura);

        if (r2) return r2;
    } else {
        return NULL;
    }
}

tipoNode* excluiNode(tipoNode *atual){
    tipoNode *aux = (tipoNode*) malloc(sizeof(tipoNode)); // Cria um auxiliar
    tipoNode *pai = (tipoNode*) malloc(sizeof(tipoNode)); // Para facilitar meu entendimento, e não poluir de notação, crio esse outro auxiliar

    if(atual){
        pai = atual->pai; // Se o no exite, eu guardo a informação do pai no auxiliar
        if (atual->filhoDir && atual->filhoEsq){
                printf("No completo, exclua os filhos antes de prosseguir.");
                return NULL;
        } else if (pai == NULL) {
            free(atual);
            printf("O no era uma raiz, a arvore foi excluida!!!");
            return NULL;
        } else {
            if (atual == pai->filhoDir && atual->filhoDir && !atual->filhoEsq){
                aux = atual;
                pai->filhoDir = atual->filhoDir;
                free(aux);
                return pai->filhoDir;
            }
            if (atual == pai->filhoDir && atual->filhoEsq && !atual->filhoDir){
                aux = atual;
                pai->filhoDir = atual->filhoEsq;
                free(aux);
                return pai->filhoDir;
            }
            if (atual == pai->filhoEsq && atual->filhoDir && !atual->filhoEsq){
                aux = atual;
                pai->filhoEsq = atual->filhoDir;
                free(aux);
                return pai->filhoEsq;
            }
            if (atual == pai->filhoEsq && atual->filhoEsq && !atual->filhoDir){
                aux = atual;
                pai->filhoEsq = atual->filhoEsq;
                free(aux);
                return pai->filhoEsq;
            }
            if (!atual->filhoDir && !atual->filhoEsq) {
                if (pai->filhoDir == atual){
                pai->filhoDir = NULL;
                free(atual);
                return pai;
                } else {
                pai->filhoEsq = NULL;
                free(atual);
                return pai;
                }
            }
            }
        } else {
            return NULL;
        }
}

inserirNo(tipoNode* raiz, int valor){
    if (raiz == NULL) return NULL;

    // getDirecao(raiz);

    if (valor < raiz->dado) {
        raiz->filhoEsq = inserirNo(raiz->filhoEsq, valor);
    } else if (valor > raiz->dado) {
        raiz->filhoDir = inserirNo(raiz->filhoDir, valor);
    } else {
        printf("Valor ja existe na arvore!\n");
    }

    return raiz;
}

 // retorno é o anterior do atual, o que assumiu o lugar
  // Verificar se é a raiz, e se for ela assume nulo, então tem que lidar com isso no main para poder verificar erros

void main(){

tipoNode *raiz = NULL;
int valor;
int op;
int cade;
tipoNode *aux;
tipoNode *aux2;

do {
    printf("\nSelecione uma opcao:");
    printf("\n1-Criar uma arvore;\n2-Incluir um no;\n3-Procurar um no;");
    printf("\n4-Exibir pre-ordem;\n5-Exibir in-ordem;\n6-Exibir pos-ordem;\n7-Excluir no;\n0-Fechar o programa.\n");
    scanf("%d", &op);

    switch (op) {
        case 1:
            printf("Digite o valor da a raiz a arvore: ");
            scanf("%d",&valor);
            raiz = criaNo(valor, NULL);
        break;
        case 2: // Insercao ABB
            printf("Digite o valor do no que deseja inserir: ");
            scanf("%d", &cade);
            inserirNo(raiz, cade);
        break;
        case 3:
            printf("Digite o valor do no que deseja buscar: ");
            scanf("%d", &cade);
            aux = busque(raiz, cade);
            if (!aux || !raiz) {
                printf("\nNo nao existe!");
            } else {
                printf("\n\nNo: %d\nPai: %d\nFilho da direita: %d\nFilho da esquerda: %d\n", aux->dado, aux->pai, aux->filhoDir, aux->filhoEsq);
            }
        break;
        case 4: printf("\nA arvore exibida pre-ordem:\n");
            exibePreOrdem(raiz);
        break;
        case 5: printf("\nA arvore exibida in-ordem:\n");
            exibeInOrdem(raiz);
        break;
        case 6: printf("\nA arvore exibida pos-ordem:\n");
            exibePosOrdem(raiz);
        break;
        case 7:
            printf("Digite o valor do no que deseja excluir: ");
            scanf("%d", &cade);
            aux = busque(raiz, cade);
            if (aux == NULL) {
                printf("\nNo nao existe!");
            } else {
                // Talvez por a raiz como aux2 em casos de excluir  a raiz
                aux2 = excluiNode(aux);
                if (aux == raiz) {
                    raiz = aux2;
                    printf("Nao existe mais arvore\n");
                }
                else if (aux2){
                        printf("No excluido com sucesso!\nEm seu lugar esta o No: %d\nPai: %d\nFilho da direita: %d\nFilho da esquerda: %d\n\n",
                                                                                        aux2->dado, aux2->pai, aux2->filhoDir, aux2->filhoEsq);
                } else printf("\nNo nao excluido!\n");
            }
        break;
        case 0:
            op = 0;
        break;
    }
    } while(op != 0);
}
