// 3) Construa um programa que armazene nome, matrícula e média de até N alunos e dê ao usuário a possibilidade de ver a listagem dos
// alunos em ordem alfabética ou em ordem de classificação.

// Obs: uma vez que os dados sejam digitados, o usuário deve poder ver as listagens quantas vezes ele desejar.

#include <stdio.h>

// Criação da struct que representa os atletas
typedef struct alunos{
char nome[30];
int matricula;
float media;
} tipoAlunos;

void main() {

    // Criação das variáveis iniciais
    tipoAlunos *aluno;
    int n = 0;

    // Reconhecimento do valor de elementos do vetor
    printf("Digite o tamanho N do vetor: ");
    scanf("%d", &n);

    aluno = (aluno*) calloc(n, sizeof(aluno)); // Caso aluno++ -> de alocação

    // Fazendo a verificação como indicado na aula
    if(!aluno){
        printf("Não foi possível alocar a memória.");
        return;
    }

    // Recepção dos valores dos elementos do vetor
    for (int i = 0; i < n; i++){
        printf("\nDigite um nome do aluno: ");
        scanf("%s", aluno[i].nome);

        printf("Digite a matricula do aluno: ");
        scanf("%d",  &aluno[i].matricula);

        printf("Digite a media do aluno: ");
        scanf("%f",  &aluno[i].media);
    }

    int modo = 0; // Criação da variável do case
 
    // Início do oolp infinito
    while (1) {

        printf("\nDigite 1 para ver a listagem em ordem alfabetica e 2 para ver em ordem de classificacao: ");
        scanf("%d", &modo);

        switch (modo) {
            case 1:
                printf("\nListagem em ordem alfabetica:");

                tipoAlunos aux1; // Struct temporaria para curar os alunos durante a reorganixação
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (strcmp(aluno[i].nome, aluno[j].nome) > 0) {
                            aux1 = aluno[i];
                            aluno[i] = aluno[j];
                            aluno[j] = aux1;
                        }
                    }
                }
                // Apresentação dos dados dos struct
                for (int i = 0; i < n; i++){
                    printf("\nDados %d:\nNome: %s | Matricula: %d | Media: %.2f\n",
                        i, aluno[i].nome, aluno[i].matricula, aluno[i].media);
                }
                break;
            case 2:
            printf("Listagem em ordem de classicacao:");
            
                tipoAlunos aux2; // Struct temporaria para curar os alunos durante a reorganixação
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (aluno[i].media < aluno[j].media) {
                            aux2 = aluno[i];
                            aluno[i] = aluno[j];
                            aluno[j] = aux2;
                        }
                    }
                }
                // Apresentação dos dados dos struct
                for (int i = 0; i < n; i++){
                    printf("\nDados %d:\nNome: %s | Matricula: %d | Media: %.2f\n",
                        i, aluno[i].nome, aluno[i].matricula, aluno[i].media);
                }
                break;
        }
    }  
}