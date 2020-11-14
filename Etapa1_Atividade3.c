#include<stdio.h>
#include <math.h>
//Um professor de matemática, solicita um programa que calcule uma equação
//do segundo grau, onde ele informará os valores de A, B e C.
 int a, b, c;
float x1, x2, delta;

 int main(){
     printf("Informe os valores de A, B, C: ");
     scanf("%i %i %i", &a, &b, &c);

    delta=(b*b)-4*a*c;
    printf("%.2f", delta);
    if(delta<=0){
        printf("\n\nNAO EXISTE RAIZ REAL");
       return 0;
    }

    x1 = (-b+sqrt(delta))/2*a;
    x2 = (-b-sqrt(delta))/2*a;

    printf("\nO valor de X1 = %.2f e o X2 = %.2f", x1, x2);
 }
