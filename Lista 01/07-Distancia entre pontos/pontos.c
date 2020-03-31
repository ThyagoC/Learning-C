//Fa�a um programa que leia v�rios pares de pontos no espa�o de quatro dimens�es e calcule a dist�ncia entre eles.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct coordenadas{

    float p[4];

}*ponto;
//calcula um par de pontos.
float calcula(struct coordenadas p1, struct coordenadas p2){

    int i;
    float distancia=0;

    for(i=0; i<4; i++){
        distancia+=pow((p1.p[i]-p2.p[i]), 2);
    }
    distancia=sqrt(distancia);

    return distancia;

}

int main(){

    int quant_pontos, i1, i2;
    scanf("%d", &quant_pontos);

    ponto=malloc(sizeof(struct coordenadas)*quant_pontos);
    //preenche os pontos.
    for(i1=0; i1<quant_pontos; i1++){
        for(i2=0; i2<4; i2++){
            scanf("%f", &ponto[i1].p[i2]);
        }
    }
    //chama a fun��o para calcular um par de pontos e imprimir
    for(i1=0; i1<(quant_pontos-1); i1++){
        printf("%.2f\n", calcula(ponto[i1], ponto[i1+1]));
    }

    free(ponto);
    return 0;

}
