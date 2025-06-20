#include <stdio.h>
#include <stdlib.h>

int quantElem = 0;
int maximo = 0;

/* Fun��o que cria uma lista vazia com N elementos e retorna um ponteiro para a lista criada*/
int* criaLista(){
int *vetor;
vetor = malloc(maximo*sizeof(int));
if(!vetor){
    printf("\nOcorreu um erro! A memoria n�o foi alocada.");
    exit(1);
}
return vetor;
}

/* Fun��o que faz inser��o n�o ordenada no vetor*/
int insereNaoOrd(int *vetor){
if(quantElem < maximo){
   printf("\nDigite um numero inteiro:");
   scanf("%d",&vetor[quantElem++]);
   return 1;
}
else
   return 0;
}

/*Fun��o que faz pesquisa sequencial*/
int pesqSeq(int *vetor, int elemento){
for(int x = 0; x < quantElem; x++)
    if(elemento == vetor[x])
       return x;
return -1;
}

/*Fun��o que exibe os elementos do vetor*/
void mostraVetor(int *vetor){
printf("\nConteudo do vetor:");
for(int x = 0; x<quantElem; x++)
    printf("%5d",vetor[x]);
}


/*Fun��o que faz a remo��o de vetor n�o ordenado*/
int remocaoNaoOrd(int *vetor,int elemento){
int resp = pesqSeq(vetor, elemento);
if(resp != -1){
    vetor[resp] = vetor[quantElem - 1];
    quantElem--;
    return 1;
    }
return 0;
}


void main(){

int *lista, aux, resp, op;
printf("\nDigite quantos elementos deseja ter na lista:");
scanf("%d",&maximo);
lista = criaLista();

do{
        printf("\n\n\nEscolha uma opcao\n1 - Inser��o nao ordenada\n2 - Pesquisa sequencial");
        printf("\n3 - Remocao nao ordenada\n9 - Exibir lista \n0 - Sair do programa");
        printf("\nDigite sua opcao: ");
        scanf("%d",&op);
        switch(op){
        case 1: if(!insereNaoOrd(lista))
                    printf("\nLista cheia. Insercao nao realizada.");
                else
                    printf("\Elemento inserido com sucesso");
                break;
        case 2: printf("\nDigite o elemento que deseja procurar:");
                scanf("%d",&aux);
                resp = pesqSeq(lista, aux);
                if(resp == -1)
                    printf("\nElemento nao encontrado");
                else
                    printf("\nElemento encontrado na posicao %d do vetor.",resp);
                break;
        case 3: printf("\nDigite o elemento que deseja remover:");
                scanf("%d",&aux);
                if(remocaoNaoOrd(lista,aux))
                    printf("\nElemento removido com sucesso.");
                else
                    printf("\nFalha na remo��o do elemento.");
                break;
        case 9: mostraVetor(lista);
                break;
        case 0: printf("\nEncerrando programa.");
        default: printf("\n\nOpcao indisponivel. Selecione uma nova opcao.");
        }
}while(op !=0);



}
