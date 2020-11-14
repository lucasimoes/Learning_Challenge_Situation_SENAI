#include<stdio.h>
//Criar um algoritmo para uma livraria que leia o valor do livro
//calcule 15% de desconto e imprima o valor a pagar.
char nomeLivro[50];
int valorLivro;
float valorFinal, valorDesconto;

int main(){
    printf("Digite o nome do Livro: ");
    scanf("%[^\n]s", &nomeLivro);

    printf("Informe o valor do Livro:");
    scanf("%i", &valorLivro);
    valorDesconto = valorLivro*0.15;
    valorFinal = valorLivro - valorDesconto;

    printf("\nO desconto e de %.1f e o Valor final do Produto = %.2f", valorDesconto, valorFinal);
}
