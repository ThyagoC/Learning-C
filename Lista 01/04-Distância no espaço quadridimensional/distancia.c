/*Fa�a um programa que leia v�rios pares de pontos no espa�o de quatro dimens�es e calcule a norma
do vetor correspondente a cada vetor e imprima as normas dos vetores em ordem crescente. */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//s�o os valores dos pontos quadridimensionais.
struct valores{

    int val;
    float n[4], norma;

}*ponto, aux;
//calcular a norma do vetor
void norma(int posi){

    ponto[posi].norma=sqrt(pow(ponto[posi].n[0], 2)+pow(ponto[posi].n[1], 2)+pow(ponto[posi].n[2], 2)+pow(ponto[posi].n[3], 2));

}
void ordena(int tam){

    int i1, i2;
    //coloca sempre o menor no com�o do vetoor.
    for(i1=0; i1<tam; i1++){
        for(i2=(i1+1); i2<tam; i2++){
            if(ponto[i2].norma<ponto[i1].norma){
                aux=ponto[i1];
                ponto[i1]=ponto[i2];
                ponto[i2]=aux;
            }
        }
    }

}

int main(){

    int num_pontos, i, i1;
    scanf("%d", &num_pontos);
    ponto=malloc(sizeof(struct valores)*num_pontos);

    //l� os pontos da struct atrav�s de uma estrutura de repeti��o.
    for(i=0; i<num_pontos; i++){
        for(i1=0; i1<4; i1++){
            scanf("%f", &ponto[i].n[i1]);
        }
        //chama a fun��o norma para calcular struct por struct.
        norma(i);
    }
    //chama a fun��o para ordenar as structs.
    ordena(num_pontos);

    for(i=0; i<num_pontos; i++){
        printf("Vetor: (%.2f, %.2f, %.2f, %.2f) Norma: %.2f\n", ponto[i].n[0], ponto[i].n[1], ponto[i].n[2], ponto[i].n[3], ponto[i].norma);
    }

    free(ponto);

    return 0;

}
