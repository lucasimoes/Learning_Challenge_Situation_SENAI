#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<stdbool.h>
#include "BibliotecaViana.c"

bool validarCPF(char *cpf);
char dadosViagem[100][100][100], numeroVoo[100];
int i, numeroAeronaves, j=0, repeticaoLayout=0, welington=0, a=0;

void layoutCadastro();
void layoutRelatorio();
void DadosAeronave();
void relatorioDeVoo();
bool validarCPF(char *cpf);
void layoutMenu();
void layoutQuantidadeCadastro();

int main(){
    int menu;
    do{
        layoutMenu();
        gotoxy(2,4);printf("Para cadastrar DIGITE 1 ");
        gotoxy(4,4);printf("Para consultar DIGITE 2 ");
        gotoxy(6,4);printf("   Para sair DIGITE 3 ");
        gotoxy(7,15);scanf("%i", &menu);
        system("cls");
        switch(menu){
        case 1:
             DadosAeronave();
             system("cls");
             break;
        case 2:
              relatorioDeVoo();
               system("cls");
             break;

        }
    } while(menu!=3);

}
void layoutCadastro(){
    corFundo(116);
    cor(116);
    gotoxy(1,1);printf("%c",218); //canto de cima esquerdo
    for(i=1; i<60; i++){
        gotoxy(0,i);printf("%c", 196); //linha de cima
    }
    gotoxy(1,60);printf("%c",191); //canto de cima direito
    for(i=2;i<24;i++){
        gotoxy(i,1);printf("%c",179); //linha da esquerda
    }
    gotoxy(24,1);printf("%c",192);//canto debaixo esquerdo
    for(i=2;i<60;i++){
        gotoxy(24,i);printf("%c", 196);//linda de baixo
    }
    gotoxy(24,60); printf("%c", 217);//canto debaixo direto

    for(i=2; i<24; i++){
        gotoxy(i,60);printf("%c",179);//linha da direita
        }
}

void layoutRelatorio(){

    gotoxy(1+repeticaoLayout,1);printf("%c",218); //canto de cima esquerdo
    for(i=2; i<60; i++){
        gotoxy(1+repeticaoLayout,i);printf("%c", 196); //linha de cima
    }
    gotoxy(1+repeticaoLayout,60);printf("%c",191); //canto de cima direito
    for(i=2;i<14;i++){
        gotoxy(i+repeticaoLayout,1);printf("%c",179); //linha da esquerda
    }
    gotoxy(14+repeticaoLayout,1);printf("%c",192);//canto debaixo esquerdo
    for(i=2;i<60;i++){
        gotoxy(14+repeticaoLayout,i);printf("%c", 196);//linda de baixo
    }
    gotoxy(14+repeticaoLayout,60); printf("%c", 217);//canto debaixo direto

    for(i=2; i<14; i++){
        gotoxy(i+repeticaoLayout,60);printf("%c",179);//linha da direita
        }
}

void DadosAeronave(){
    layoutQuantidadeCadastro();
    gotoxy(2,63);printf("Quantas cadastros deseja fazer: ");
    scanf("%i", &numeroAeronaves);
    if(numeroAeronaves<=welington)numeroAeronaves+=welington;

    for(a=welington; a<numeroAeronaves; a++){
    layoutCadastro();
    gotoxy(2,14);printf("NOS TRUPICA MAS NUM CAI AIRLINES");
    //DADOS DA AERONAVE
    gotoxy(4,2);printf("Insira o numero do Voo: ");
    scanf("%s", &dadosViagem[a][0]);
    fflush(stdin);
    gotoxy(6,2);printf("Insira o prefixo da Aeronave: ");
    scanf("%[^\n]s", &dadosViagem[a][1]);
    fflush(stdin);
    gotoxy(8,2);printf("Insira a capacidade da Aeronave: ");
    scanf("%s", &dadosViagem[a][2]);
    fflush(stdin);
    gotoxy(10,2);printf("Informe a autonomia da Aeronave: ");
    scanf("%s", &dadosViagem[a][3]);

    //DADOS DO PILOTO
    gotoxy(12,2);printf("Insira o registro do Piloto: ");
    scanf("%s", &dadosViagem[a][4]);
    fflush(stdin);
    gotoxy(14,2);printf("Nome do Piloto: ");
    scanf("%[^\n]s", &dadosViagem[a][5]);
    fflush(stdin);
    gotoxy(16,2);printf("Insira a quantidade de horas de voos do piloto: ");
    scanf("%s", &dadosViagem[a][6]);
    fflush(stdin);

    //DADOS DO CLIENTE
    gotoxy(18,2);printf("Digite o nome do CLIENTE: ");
    scanf("%[^\n]s", &dadosViagem[a][7]);
    fflush(stdin);
    gotoxy(20,2);printf("Qual e o DESTINO desejado: ");
    scanf("%[^\n]s", &dadosViagem[a][8]);
    fflush(stdin);
    gotoxy(22,2);printf("Digite o CPF do CLIENTE: ");
    scanf("%s", &dadosViagem[a][9]);
    fflush(stdin);

        //VALIDANDO O CPF
        while(!validarCPF(dadosViagem[a][9])){
            gotoxy(23,2);printf("CPF INVALIDO!! DIGITE NOVAMENTE: ");
            scanf("%s", &dadosViagem[a][9]);
        }
    welington++;
    printf("\n");
    system("cls");
    }
}
//FUNCAO RELATORIO VOO
void relatorioDeVoo(){
    int x;
    repeticaoLayout=0;
    gotoxy(2+repeticaoLayout,2);printf("Digite o numero voo para imprimir o RELATORIO DE VOO: ");
    scanf("%s", &numeroVoo);
    system("cls");

    corFundo(116);
    cor(116);
    for(a=0; a<numeroAeronaves; a++){
        x=strcmp(numeroVoo,dadosViagem[a][0]);
        if(x==0){
            layoutRelatorio();
            gotoxy(3+repeticaoLayout,14);printf("NOS TRUPICA MAS NUM CAI AIRLINES");
            gotoxy(5+repeticaoLayout,2);printf("Prefixo aeroanave: %s", dadosViagem[a][1]);
            gotoxy(7+repeticaoLayout,2);printf("O Registro do piloto: %s", dadosViagem[a][4]);
            gotoxy(9+repeticaoLayout,2);printf("Destino: %s", dadosViagem[a][8]);
            gotoxy(11+repeticaoLayout,2);printf("Nome do Cliente: %s", dadosViagem[a][7]);
            gotoxy(13+repeticaoLayout,2);printf("CPF do cliente: %s", dadosViagem[a][9]);
            repeticaoLayout+=18;
        }
    }
        printf("\n\n\n");
        system("pause");
        system("cls");
}
   //FUNCAO DE VALIDAR CPF
bool validarCPF(char *cpf)
{
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11)
        return 0;
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0))
        return 0; ///se o CPF tiver todos os números iguais ele é inválido.
    else
    {
        ///digito 1---------------------------------------------------
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        else
        ///digito 2--------------------------------------------------
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;
}

void layoutMenu(){
    corFundo(116);
    cor(116);
    gotoxy(1,1);printf("%c",218); //canto de cima esquerdo
    for(i=1; i<30; i++){
        gotoxy(0,i);printf("%c", 196); //linha de cima
    }
    gotoxy(1,30);printf("%c",191); //canto de cima direito
    for(i=2;i<8;i++){
        gotoxy(i,1);printf("%c",179); //linha da esquerda
    }
    gotoxy(8,1);printf("%c",192);//canto debaixo esquerdo
    for(i=2;i<30;i++){
        gotoxy(8,i);printf("%c", 196);//linda de baixo
    }
    gotoxy(8,30); printf("%c", 217);//canto debaixo direto

    for(i=2; i<8; i++){
        gotoxy(i,30);printf("%c",179);//linha da direita
        }
}
void layoutQuantidadeCadastro(){
    corFundo(116);
    cor(116);
    gotoxy(1,62);printf("%c",218); //canto de cima esquerdo
    for(i=63; i<101; i++){
        gotoxy(1,i);printf("%c", 196); //linha de cima
        gotoxy(3,i);printf("%c", 196); //linha de baixo
    }
    gotoxy(1,101);printf("%c",191); //canto de cima direito
        gotoxy(2,62);printf("%c",179); //linha da esquerda
        gotoxy(2,101);printf("%c",179);//linha da direita

    gotoxy(3,62);printf("%c",192);//canto debaixo esquerdo
    gotoxy(3,101); printf("%c", 217);//canto debaixo direto

}
