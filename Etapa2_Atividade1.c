#include<stdio.h>
char nome[1000][50], turma[1000], sair[10]={"sair"}, turmaMaior[3];
int RA[1000], mediaAluno[1000], somaMedia=0, j=0, i=0, contadorAlunos = 0, comparador=0, turmaA=0, turmaB=0, turmaC=0;
int RAMaior=0;
float  mediaFacul, mediaTurmaA, mediaTurmaB, mediaTurmaC, maiorMedia=0;

int main(){
    for(i=0; i<3; i++){
        printf("\nDigite o nome do aluno:");
        scanf("%[^\n]s", &nome[j]);
        comparador = strcmp(nome[j], sair);
        if(comparador == 0){
            break;
        }
        printf("Digite o RA do aluno:");
        scanf("%i", &RA[i]);
        fflush(stdin);
        printf("Informe a MEDIA do Aluno:");
        scanf("%i", &mediaAluno[i]);
        fflush(stdin);
        printf("Informe a turma A, B ou C:");
        scanf("%c", &turma[i]);
        fflush(stdin);
        if(turma[i] == 'A'){
            turmaA++;
            mediaTurmaA+=mediaAluno[i];
        }
        if(turma[i]== 'B'){
            turmaB++;
            mediaTurmaB+=mediaAluno[i];
        }
        if(turma[i] == 'C'){
            turmaC++;
            mediaTurmaC+=mediaAluno[i];
        }
        if(mediaAluno[i]>maiorMedia){
            maiorMedia = mediaAluno[i];
            RAMaior=RA[i];
            turmaMaior[j]=turma[i];
        }
        contadorAlunos++;
        somaMedia+=mediaAluno[i];
    }
    if(i){
    printf("\nNumero de Alunos CADASTRADOS: %i", contadorAlunos);

    mediaFacul = somaMedia/contadorAlunos;
    printf("\nMedia de NOTAS DA FACULDADE = %.2f", mediaFacul);

    mediaTurmaA = mediaTurmaA/turmaA;
    mediaTurmaB = mediaTurmaB/turmaB;
    mediaTurmaC = mediaTurmaC/turmaC;
    printf("\nMedia Turma A = %.0f Media Turma B = %.0f Media Turma C = %.0f", mediaTurmaA, mediaTurmaB, mediaTurmaC);

    printf("\nRA do Aluno com maior Media e %i e a sua turma e: %s",RAMaior, turmaMaior);
    }
}
