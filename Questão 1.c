// 1)Guarde N números em um vetor alocado dinamicamente. Exiba a média dos números lidos e os múltiplos de 6 digitados.

#include <stdio.h>

void main() {

    // Criação das variáveis iniciais
    int *vetor, *multiplosDeSeis, n, somatorio = 0, j; 
    float media = 0.0;

    // Reconhecimento do valor de elementos do vetor
    printf("Digite o tamanho N do vetor: ");
    scanf("%d", &n);

    vetor = (int*) calloc(n, sizeof(int)); // Cálculo do tamanho do vetor em relação a alocação de memória

    // Fazendo a verificação como indicado na aula
    if(!vetor){
        printf("Não foi possível alocar a memória.");
        return;
    }

    // Recepção dos valores dos elementos do vetor
    for (int i = 0; i < n; i++){
        printf("Digite um valor para ser o elemento %d do vetor:", i);
        scanf("%d", &vetor[i]);
        somatorio += vetor[i];
    }

    // Cálculo do tamamanho do vetor de múltiplos em relação a memória
    for (int i = 0; i < n; i++){
        if (vetor[i] % 2 == 0 && vetor[i] % 3 == 0){
            j++;
        }
    }
    multiplosDeSeis = (int*) calloc(j, sizeof(int)); // Poderia ter colocado ele com o tamanho n, porém seria uma solição preguiçosa

    int h = 0; // Cria uma variável para o for
     for (int i = 0; i < n; i++){
        if (vetor[i] % 2 == 0 && vetor[i] % 3 == 0){ // Testa se os números são múltiplos de seis
            multiplosDeSeis[h] = vetor[i]; // Salva somente os múltiplos de seis
            h++;
        }
    }

    media = somatorio / n;

    // Apresentação os resultados

    printf("A media dos elementos do vetor eh %.3f", media);

    for(int x = 0; x <= j; x++)
        printf("\nOs numero multiplos de seis sao: %d", multiplosDeSeis[x]);
}


