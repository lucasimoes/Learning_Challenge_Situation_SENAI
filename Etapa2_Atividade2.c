#include<stdio.h>
int saque, nota2=0, nota5=0, nota10=0, nota20=0, nota50=0, nota100=0, nota200=0;

int main(){
    printf("Digite o valor de saque R$");
    scanf("%i", &saque);
    while(saque==3 ||saque ==1){
        printf("\nNAO POSSUI NOTAS DE R$1,00 DIGITE NOVAMENTE OUTRO VALOR:");
        scanf("%i", &saque);
    }
    if(saque%2 ==1){
        saque-=5;
        nota5++;
    }
    while(saque>=200){
        nota200++;
        saque-=200;
    }
    while(saque>=100){
        nota100++;
        saque-=100;
    }
    while(saque>=50){
        nota50++;
        saque-=50;
    }
    while(saque>=20){
        nota20++;
        saque-=20;
    }
    while(saque>=10){
        nota10++;
        saque-=10;
    }
    while(saque>=2){
        nota2++;
        saque-=2;
    }
    printf("\nNotas de R$200 usadas: %i", nota200);
    printf("\nNotas de R$100 usadas: %i", nota100);
    printf("\nNotas de R$50 usadas: %i", nota50);
    printf("\nNotas de R$20 usadas: %i", nota20);
    printf("\nNotas de R$10 usadas: %i", nota10);
    printf("\nNotas de R$5 usadas: %i", nota5);
    printf("\nNotas de R$2 usadas: %i", nota2);
}
