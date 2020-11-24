#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

//FUNÇÃO LAYOUT
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


char nome[20][30], sexo[20][20];
int idade[20], vetorCanalPreferido[20], vetorCanalOdiado[20], i, j=0,canalPreferido=0, canalOdiado=0;
int canalPreferido1=0, canalPreferido2=0, canalPreferido3=0, canalOdiado1=0, canalOdiado2=0, canalOdiado3=0;
int masculino1=0, masculino2=0, masculino3=0, feminino1 = 0, feminino2 = 0, feminino3 = 0;
float mediaIdadeCanalPreferido, mediaIdadeCanalOdiado, somaIdadePreferido1 = 0, somaIdadePreferido2 = 0, somaIdadePreferido3 = 0;
float somaIdadeOdiado1=0, somaIdadeOdiado2=0, somaIdadeOdiado3=0;

int main(){
    for(i=0; i<20; i++){
        printf("Digite o nome: ");
        scanf("%s", &nome[i][j]);

        fflush(stdin);
        printf("Digite a idade: ");
        scanf("%i", &idade[i]);

        fflush(stdin);
        printf("Sexo Masculino(M) ou Feminino(F): ");
        scanf("%s", &sexo[i][j]);

        //CANAL PREFERIDO
        fflush(stdin);
        printf("Canal Preferido (1), (2) ou (3): ");
        scanf("%i", &vetorCanalPreferido[i]);

        //CANAL ODIADO
        printf("Canal Odiado (1), (2) ou (3): ");
        scanf("%i", &vetorCanalOdiado[i]);

        //SOMAS DOS CANAIS PREFERIDOS
        if(vetorCanalPreferido[i]==1)canalPreferido1++;
        if(vetorCanalPreferido[i]==2)canalPreferido2++;
        if(vetorCanalPreferido[i]==3)canalPreferido3++;
        //COMPARAÇÃO CANAIS PREFERIDOS
        if(canalPreferido1>canalPreferido2 && canalPreferido1>canalPreferido3){
            canalPreferido=1;
                if(vetorCanalPreferido[i]==1)somaIdadePreferido1+=idade[i];
        }
        if(canalPreferido2>canalPreferido1 && canalPreferido2>canalPreferido3){
            canalPreferido=2;
                if(vetorCanalPreferido[i]==2)somaIdadePreferido2+=idade[i];
        }
        if(canalPreferido3>canalPreferido1 && canalPreferido3>canalOdiado2){
            canalPreferido=3;
                if(vetorCanalPreferido[i]==3)somaIdadePreferido3+=idade[i];
        }

        //SOMAS DOS CANAIS ODIADOS
        if(vetorCanalOdiado[i]==1)canalOdiado1++;
        if(vetorCanalOdiado[i]==2)canalOdiado2++;
        if(vetorCanalOdiado[i]==3)canalOdiado3++;
        //COMPARAÇÃO DOS CANAIS ODIADOS
        if(canalOdiado1>canalOdiado2 && canalOdiado1>canalOdiado3){
            canalOdiado=1;
            if(vetorCanalOdiado[i]==1)somaIdadeOdiado1+=idade[i];
        }
        if(canalOdiado2>canalOdiado1 && canalOdiado2>canalOdiado3){
            canalOdiado=2;
            if(vetorCanalOdiado[i]==2)somaIdadeOdiado2+=idade[i];
        }
        if(canalOdiado3>canalOdiado1 && canalOdiado3>canalOdiado2){
            canalOdiado=3;
            if(vetorCanalOdiado[i]==3)somaIdadeOdiado3+=idade[i];
        }
        //COMPARAÇÃO DE SEXO MASCULINO P/CANAIS PREFERIDOS
        if (vetorCanalPreferido[i] == 1 && sexo[i][j] == 'M')masculino1++;
		if (vetorCanalPreferido[i] == 2 && sexo[i][j] == 'M')masculino2++;
		if (vetorCanalPreferido[i] == 3 && sexo[i][j] == 'M')masculino3++;
		//COMPARAÇÃO DE SEXO MASCULINO P/ CANAIS ODIADOS
		if (vetorCanalOdiado[i] == 1 && sexo[i][j] == 'M')masculino1++;
		if (vetorCanalOdiado[i] == 2 && sexo[i][j] == 'M')masculino2++;
		if (vetorCanalOdiado[i] == 3 && sexo[i][j] == 'M')masculino3++;

        //COMPARAÇÃO DE SEXO FEMININO P/ CANAIS PREFERIDOS
        if (vetorCanalPreferido[i] == 1 && sexo[i][j] == 'F')feminino1++;
        if (vetorCanalPreferido[i] == 2 && sexo[i][j] == 'F')feminino2++;
        if (vetorCanalPreferido[i] == 3 && sexo[i][j] == 'F')feminino3++;
        //COMPARAÇÃO DE SEXO FEMININO P/ CANAIS ODIADOS
        if (vetorCanalOdiado[i] == 1 && sexo[i][j] == 'F')feminino1++;
        if (vetorCanalOdiado[i] == 2 && sexo[i][j] == 'F')feminino2++;
        if (vetorCanalOdiado[i] == 3 && sexo[i][j] == 'F')feminino3++;

        system("cls");
    }
    //MÉDIA DOS CANAIS PREFERIDOS
    if (canalPreferido == 1)mediaIdadeCanalPreferido = somaIdadePreferido1 / canalPreferido1;
    if (canalPreferido == 2)mediaIdadeCanalPreferido = somaIdadePreferido2 / canalPreferido2;
    if (canalPreferido == 3)mediaIdadeCanalPreferido = somaIdadePreferido3 / canalPreferido3;
    //MÉDIA DOS CANAIS ODIADOS
    if (canalOdiado == 1)mediaIdadeCanalOdiado = somaIdadeOdiado1 / canalOdiado1;
    if (canalOdiado == 2)mediaIdadeCanalOdiado = somaIdadeOdiado2 / canalOdiado2;
    if (canalOdiado == 3)mediaIdadeCanalOdiado = somaIdadeOdiado3 / canalOdiado3;

    //EXIBIR NA TELA LAYOUT
    gotoxy(0,0);printf("%c",218); //canto de cima esquerdo
    for(i=1; i<75; i++){
        gotoxy(i,0);printf("%c", 196); //linha de cima
    }
    gotoxy(75,0);printf("%c",191); //canto de cima direito
    for(i=1;i<8;i++){
        gotoxy(0,i);printf("%c",179); //linha da esquerda
    }
    gotoxy(0,8);printf("%c",192);//canto debaixo esquerdo
    for(i=1;i<75;i++){
        gotoxy(i,8);printf("%c", 196);//linda de baixo
    }
    gotoxy(75,8); printf("%c", 217);//canto debaixo direto

    for(i=1; i<8; i++){
        gotoxy(75,i);printf("%c",179);//linha da direita
        }
    for (i=1; i<75; i++){
        gotoxy(i,2);printf("%c", 196);//divisoria 1
    }
     for (i=1; i<75; i++){
        gotoxy(i,4);printf("%c", 196);//divisoria 2
    }
     for (i=1; i<75; i++){
        gotoxy(i,6);printf("%c", 196);//divisoria 3
    }
    gotoxy(1,1);
    printf("Canal Preferido: %i. Canal Odiado: %i\n", canalPreferido, canalOdiado);
    gotoxy(1,3);
    printf("Masculino canal 1: %i. Masculino canal 2: %i. Masculino canal 3: %i\n", masculino1, masculino2, masculino3);
    gotoxy(1,5);
    printf("Feminino canal 1: %i. Feminino canal 2: %i. Feminino canal 3: %i\n", feminino1, feminino2, feminino3);
    gotoxy(1,7);
    printf("Media idade canal MAIS favorito %.2f. Media Idade canal MAIS odiado %.2f\n", mediaIdadeCanalPreferido, mediaIdadeCanalOdiado);

    printf("\n\n");
    system("pause");
}
