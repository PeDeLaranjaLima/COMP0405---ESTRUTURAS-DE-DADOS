/************************************************ Atividade pontuada ************************************************

Aluno: Gabriel Lima Dantas

************************************************ Questão ************************************************

Considere o seguinte problema que pode ser resolvido de uma forma
bastante elegante usando uma lista circular. Esse problema é conhecido
como problema de Josephus. A seguir apresentamos uma versão mais light
do problema.
◼ Um agente de viagem selecionou n clientes para participar de uma
competição para ver que ganharia um cruzeiro em volta do mundo. O
agente colocou os clientes em um círculo e sorteou um número m, sendo m
<= n. Começando com o nome de um dos participantes, o agente conta no
sentido horário em torno do círculo. Quando a contagem atingir o número
m, o participante é removido do círculo e a contagem recomeça a partir do
próximo participante. O último participante que for removido ganhará a
competição.
◼ Faça um programa em C que usando uma lista circular implemente o
problema de Josephus. Leia os nomes e CPFs dos participantes do cruzeiro e
vá realizando os sorteios a cada sorteio deve ser mostrado:
◼ O nome do participante eliminado
◼ O número sorteado
◼ Os participantes que continuam concorrendo.
◼ Ao final deve ser mostrado o nome e CPF do grande vencedor.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Primeiro nome vazio
// Falta algo?

/*Implementação de Lista Circularmente Encadeada Com nó cabeça- Estrutura de nomes*/

/*Tipo de nome que representa um nó da lista encadeada*/
typedef struct no{
    char nome[30];
    struct no *proxNo;
    char cpf[12];
}tipoNo;

/*Tipo de nome que representa uma lista encadeada*/
typedef struct listaGerenciada{
    tipoNo *fim;
    //char nome[30];
    int quant;
}tipoLista;

void inicializa(tipoLista *lista){
    tipoNo *cabeca = (tipoNo *) malloc(sizeof(tipoNo));
    if (cabeca == NULL) {
        printf("Erro ao alocar nó cabeça.\n");
        exit(1);
    }
    cabeca->proxNo = cabeca; // lista circular
    lista->fim = cabeca;
    lista->quant = 0;
    //cabeca->nome[0] = '\0'; // Zera o nome do nó cabeça para não imprimir lixo
}

/*Função para inserção de nó em lista vazia*/
int insereListaVazia(tipoLista *listaEnc, const char *valor, const char *num){
    tipoNo *novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    if(novoNo == NULL)
        return 0;

    listaEnc->fim = novoNo;
    listaEnc->fim->proxNo = novoNo;  // o nó cabeça
    strcpy(novoNo->nome, valor);
    strcpy(novoNo->cpf, num);
    listaEnc->quant++;
    return 1;
}


/*Função que faz a inserção de um nó na frente de uma lista simplesmente encadeada*/
int insereNaFrente(tipoLista *listaEnc, const char *valor, const char *num){
    tipoNo *novoNo;
    if(listaEnc->fim->proxNo==NULL)
        return insereListaVazia(listaEnc, valor, num);
    else{
        novoNo = (tipoNo*)malloc(sizeof(tipoNo));
        if(novoNo==NULL)
            return 0;

        //novoNo->nome=valor;
        novoNo->proxNo=listaEnc->fim->proxNo;
        listaEnc->fim->proxNo=novoNo;
        strcpy(novoNo->nome, valor);
        strcpy(novoNo->cpf, num);
        listaEnc->quant++;
        return 1;
    }
}

/*Função de exibição da lista simplesmente encadeada*/
int exibeLista(tipoLista *listaEnc){
    tipoNo *atual;  //Variável que será usada para percorrer a lista*/
    if(listaEnc->fim == NULL)
        return 0;
    atual = listaEnc->fim->proxNo;
    printf("\nLista encadeada: ");
    printf("\nNome: %s | CPF: %s,",atual->nome, atual->cpf);
    while(atual != listaEnc->fim){
        atual = atual->proxNo;
        printf("\nNome: %s | CPF: %s,",atual->nome, atual->cpf);
        }
        return 1;
}

/*Função que faz a remoção de vetor não ordenado*/
int remocao(tipoLista *lista, tipoNo *noRemover){
    if (lista->fim == NULL){
        return 0;
    }
   
    tipoNo *anterior = lista->fim;
    tipoNo *atual = lista->fim->proxNo;
    while(atual != lista->fim){
        if(strcmp(atual->cpf, noRemover->cpf) == 0){
            anterior->proxNo = atual->proxNo;
            if(atual == lista->fim){
                lista->fim = anterior;
            }
            if(atual->proxNo == atual){
                lista->fim = NULL;
            }
            free(atual);
            lista->quant--;
            return 1;
        }
        anterior = atual;
        atual = atual->proxNo;
    }
    return 1;
}

/*Função que faz pesquisa sequencial*/
int pesqSeq(tipoLista *listaEnc, const char *elemento){
    tipoNo *atual;  //Variável que será usada para percorrer a lista*/
    if(listaEnc->fim->proxNo == NULL)
        return 0;
    atual = listaEnc->fim->proxNo;    
    while(atual != listaEnc->fim){
        if((strcmp(elemento, atual->cpf) == 0)){
            printf("\nElemento encontrado:\nNome: %s | CPF: %s", atual->nome, atual->cpf);
            return 1;
        } 
        atual = atual->proxNo;
    }
    printf("Elemento não encontrado");
    return 0;
}

int comecarSorteio(tipoLista *lista, int *ponto){
    if(lista->fim == NULL){
        return 0;
    }
    while (lista->quant > 1){

        int passo = rand() % lista->quant;
        *ponto += passo; // Soma ao valor anterior

        printf("\nValor sorteado: %d", *ponto);
        // Navega até o nó que será removido
        tipoNo *atual = lista->fim;
        for (int i = 0; i < *ponto % lista->quant; i++) {
            atual = atual->proxNo;
        }
        // Exibe o participante eliminado
        printf("\nParticipante sorteado\n: Nome: %s | CPF: %s\n", atual->nome, atual->cpf);
        // Remove o nó sorteado
        remocao(lista, atual);
        // Exibe a lista atualizada
        printf("\nParticipantes restantes:\n");
        exibeLista(lista);
    }
    // Exibe o grande vencedor
    printf("\nO vencedor do soretio foi %s, inscrito sob o CPF: %s, parabéns!\n", lista->fim->nome, lista->fim->cpf);
    return 1;

}


int main(){
    tipoLista lista;
    int op;
    int parada = 0;
    char aux[30];
    char aux2[12];
    inicializa(&lista);
  
    do{
        printf("\n      Menu do sorteio");
        printf("\n1 - Inicia uma nova lista de participantes");
        printf("\n2 - Insere elemento no inicio da lista de participantes");
        printf("\n3 - Pesquisa elemento na lista de participantes");
        printf("\n4 - Sorteia um participante aleatório da lista");
        printf("\n9 - Exibe a lista atual de participantes");
        printf("\n0 - Encerra o sorteio");
        printf("\nDigite sua opção:");
        scanf("%d",&op);
        switch(op){
        case 1:printf("\nDigite o elemento que deseja inserir (Nome CPF):");
            scanf("%s %s", aux, aux2);
            insereListaVazia(&lista, aux, aux2);
            break;
        case 2:printf("\nDigite o elemento que deseja inserir (Nome CPF):");
            scanf("%s %s", aux, aux2);
            insereNaFrente(&lista, aux, aux2);
            break;
        case 3:printf("\nDigite o elemento que deseja encontrar (CPF):");
            scanf("%s", aux2);
            pesqSeq(&lista, aux2);
            break;  
        case 4:printf("\nIniciar o sorteio:");
            //parada = rand() % lista.quant; // Sorteia o número de passos
            comecarSorteio(&lista, &parada);
            break;           
        case 9: if(!exibeLista(&lista))
                    printf("\nLista vazia!\n");
            break;
        case 0: printf("\nEncerrando programa.");
            break;
        default: printf("\nOpção inválida!");
        }
     printf("\n\n\n\n");
    }while(op != 0);

return 1;    
}