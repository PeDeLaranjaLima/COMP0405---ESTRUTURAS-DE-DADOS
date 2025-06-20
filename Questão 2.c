// 2) Crie um struct que guarde nome, idade e peso um atletas. Em um vetor, alocado dinamicamente, guarde os dados de N atletas.
//    Exiba uma listagem dos dados dos atletas cadastrados. Ao final exiba a média dos pesos e quantos atletas são menores de idade.

#include <stdio.h>

// Criação da struct que representa os atletas
// Posso dizer que ela é uma abstração dos alunos?
typedef struct atletas{
char nome[30];
int idade;
float peso;
} tipoAtletas;

void main() {

    // Criação das variáveis iniciais
    tipoAtletas *atleta;
    int n = 0, somatorio = 0;
    float media;

    // Reconhecimento do valor de elementos do vetor
    printf("Digite o tamanho N do vetor: ");
    scanf("%d", &n);

    atleta = (int*) calloc(n, sizeof(atleta));

    // Fazendo a verificação como indicado na aula
    if(!atleta){
        printf("Não foi possível alocar a memória.");
        return;
    }

    // Recepção dos valores dos elementos do vetor
    for (int i = 0; i < n; i++){
        printf("Digite um nome do atleta: ");
        scanf("%s", atleta[i].nome);

        printf("Digite a idade do atleta: ");
        scanf("%d",  &atleta[i].idade);

        printf("Digite o peso do atleta: ");
        scanf("%f",  &atleta[i].peso);
        somatorio += atleta[i].peso;

    }

    // Apresentação dos dados dos struct
    for (int i = 0; i < n; i++){
        printf("\nDados %d:\nNome: %s | Idade: %d | Peso: %.2f\n",
            i, atleta[i].nome, atleta[i].idade, atleta[i].peso);
    }

    media = somatorio / n;
    printf("\nA media de pesos dos atletas eh: %f", media); // Apresentação da média geral
    
    // Verificação dos atletas menores de 18 anos
    int h = 0;
    for (int i = 0; i < n; i++){
        if (atleta[i].idade < 18)
            h++;
    }
    printf("\nO numero de atletas menores de 18 anos eh: %d", h);

}