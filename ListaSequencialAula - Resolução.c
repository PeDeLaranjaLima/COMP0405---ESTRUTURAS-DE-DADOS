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

/*
 Funções implementadas:

• Inserção de nó em lista ordenada
• Pesquisa binária
• Remoção de nó em lista ordenada
• Remover o i-ésimo item da lista (exercicio) Lista ordenada
• Remover um ítem na i-ésima posição (exercicio) – Lista não ordenada (O terceiro item não eh igual a esse?)

*/

// Insere um elemento na lista ordenada
int insercaoOrdenada(int *vetor){
int aux0 = 0;
printf("\nDigite um numero inteiro:");
scanf("%d",&aux0);

while (quantElem >= 0){
    if (vetor[quantElem] >= aux0){
        vetor[quantElem+1] = vetor[quantElem]; 
    } else {
        return 1;
        break;
    }
quantElem--;
}
return 0;
}

// Realiza a busca binaria em uma lista ja ordenada
int buscaBinaria(int *vetor){
int aux1 = 0;
printf("\nDigite o elemento que deseja buscar:");
scanf("%d",&aux1);
int inicio = 0;
int fim = quantElem - 1;

while (inicio <= fim) {
    int meio = (inicio + fim) / 2;

    if (vetor[meio] == aux1)
        return 1;
    else if (vetor[meio] < aux1)
        inicio = meio + 1;
    else
        fim = meio - 1;
}

    return 0;
}

// Remove o i-esimo elemento de uma lista ordenada => Busca por elemento
int remocaoOrdenada(int *vetor){
int aux3 = 0;
int i = 0;
printf("\nDigite um numero inteiro:");
scanf("%d",&aux3);

while (i <= quantElem){
    if (vetor[quantElem] <= aux3){
        vetor[quantElem-1] = vetor[quantElem]; 
    } else {
        return 1;
        break;
    }
i++;
}
return 0;
}

// Remove o i-esimo item de uma lista ordenada => Busca por indice
int removerIesimoItem(int *vetor){
int aux4 = 0;
printf("\nDigite um numero inteiro:");
scanf("%d",&aux4);  
int i = aux4; 
while (i <= quantElem){
    vetor[quantElem-1] = vetor[quantElem]; 
    i++;
}
return 1;
}

void main(){

int *lista, aux, resp, op;
printf("\nDigite quantos elementos deseja ter na lista:");
scanf("%d",&maximo);
lista = criaLista();

do{
        printf("\n\n\nEscolha uma opcao\n1 - Insercao nao ordenada\n2 - Pesquisa sequencial");
        printf("\n3 - Remocao nao ordenada\n4 - Insercao Ordenada\n5 - Busca binária\n6 - Remover o i-esimo elemento da lista");
        printf("\n7 - Remocao do i-esimo item \n9 - Exibir lista \n0 - Sair do programa");    
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
                    printf("\nFalha na remocao do elemento.");
                break;
        case 4: 
                if(insercaoOrdenada(lista))
                    printf("\nElemento iserido com sucesso.");
                else
                    printf("\nFalha na remocao do elemento.");
                break; 
        case 5: 
                if(buscaBinaria(lista))
                    printf("\nElemento encontrado com sucesso.");
                else
                    printf("\nFalha na busca do elemento.");
                break;
        case 6: 
                if(remocaoOrdenada(lista))
                    printf("\nElemento i-esimo removido com sucesso.");
                else
                    printf("\nFalha na busca do elemento.");
                break;          
        case 7: 
                if(removerIesimoItem(lista))
                    printf("\nIndice i-esimo removido com sucesso.");
                else
                    printf("\nFalha na busca do elemento.");
                break;                       
        case 9: mostraVetor(lista);
                break;
        case 0: printf("\nEncerrando programa.");
        default: printf("\n\nOpcao indisponivel. Selecione uma nova opcao.");
        }
}while(op !=0);


free(lista); /*Libera mem�ria alocada para a lista*/
}
