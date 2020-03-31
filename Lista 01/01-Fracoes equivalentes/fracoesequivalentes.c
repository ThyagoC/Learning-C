/*faça um programa capaz de ler sequências de frações e para cada sequência
indicar quais pares são equivalentes entre si. O programa deve comparar a primeira fração com todas as
outras seguintes, depois deve comparar a segunda com todas as outras seguintes e assim por diante, de modo
que a posição na lista da primeira fração de um par de frações seja sempre menor que a posição da segunda
fração do par.*/
#include<stdio.h>
#include<stdlib.h>

int quant_frac_equi(int *v, int tamv){

    int c, c1, acum;

    for(c=0, acum=0; c<(tamv*2); c+=2){
        for(c1=(c+2); c1<(tamv*2); c1+=2){
            float x=((float)v[c]/(float)v[c+1]), y=((float)v[c1]/(float)v[c1+1]);
            if(x==y){
                acum++;
            }
        }
    }

    return acum;

}

int *compara_frac(int *v, int tamv){

    int *frac_equi, c, c1, p;

    frac_equi=malloc(sizeof(int)*quant_frac_equi(v, tamv)*4);
    for(c=0, p=0; c<(tamv*2); c+=2){

        for(c1=(c+2); c1<(tamv*2); c1+=2){
            if(((float)v[c]/(float)v[c+1])==((float)v[c1]/(float)v[c1+1])){

                frac_equi[p]=v[c];
                frac_equi[p+1]=v[c+1];
                frac_equi[p+2]=v[c1];
                frac_equi[p+3]=v[c1+1];
                p+=4;

            }
        }
    }

    return frac_equi;

}

int main(){

    int i, i2, i1, num_casos, num_frac, *frac, *fequi;

    scanf("%d", &num_casos);
    for(i=0; i<num_casos; i++){

        scanf("%d", &num_frac);
        frac=malloc(sizeof(int)*2*num_frac);
        for(i1=0;frac[i1]!='\0'; i1+=2){

            scanf("%d", &frac[i1]);
            getchar();
            scanf("%d", &frac[i1+1]);

        }

        printf("Caso de teste %d\n", i+1);
        if(quant_frac_equi(frac, num_frac)==0){

            printf("Nao ha fracoes equivalentes na sequencia\n");

        }
        else{

            fequi=compara_frac(frac, num_frac);
            for(i1=0, i2=0; i1<quant_frac_equi(frac, num_frac); i1++, i2+=4){

                printf("%d/%d equivalente a %d/%d\n", fequi[i2], fequi[i2+1], fequi[i2+2], fequi[i2+3]);

            }
            free(fequi);
        }
        free(frac);
    }

    return 0;

}
