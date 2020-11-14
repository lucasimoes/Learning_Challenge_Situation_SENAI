#include<stdio.h>
//Criar um algoritmo para uma escola de inglês, que leia o nome e
//as 4 notas de um aluno, calcule e imprima o total e a média das notas.
 char aluno[30];
 int nota1, nota2, nota3, nota4, total;
 float media;

 int main(){
    printf("Digite o nome:");
    scanf("%s", &aluno);

    printf("Informe as notas: ");
    scanf("%i %i %i %i", &nota1, &nota2, &nota3, &nota4);

    total = nota1+nota2+nota3+nota4;
    media = total/4;
    printf("\nTotal das notas =%i", total);
    printf("\nMedia das notas =%.2f", media);
 }
