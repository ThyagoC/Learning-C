/*e fa�a um programa capaz de ler sequ�ncias de fra��es e para cada sequ�ncia
indicar quais pares s�o equivalentes entre si. O programa deve comparar a primeira fra��o com todas as
outras seguintes, depois deve comparar a segunda com todas as outras seguintes e assim por diante, de modo
que a posi��o na lista da primeira fra��o de um par de fra��es seja sempre menor que a posi��o da segunda
fra��o do par. NESTA VERS�O A ENTRADA N�O � INDICADA*/
#include<stdio.h>
#include<stdlib.h>

struct numero{

    int *x;
    int *y;
    //recebe o valor da divis�o da fra��o
    float *valor;

}*fracao;

void valorf(int tam, int *tam2){

    //calcula o valor da fra��o
    int i1, i2;
    for(i1=0; i1<tam; i1++){
        for(i2=0; i2<tam2[i1]; i2++){
            fracao[i1].valor[i2]=((float)fracao[i1].x[i2]/(float)fracao[i1].y[i2]);
        }
    }

}

void compara(int tam, int *tam2){

    int i1, i2, i3, val;
    //i1 representa o caso numero 1
    for(i1=0, val=0; i1<tam; i1++, val=0){

        printf("Caso de teste %d\n", i1+1);
        //i2 representa o indice dos vetores internos � struct
        for(i2=0; i2<tam2[i1]; i2++){
            for(i3=(i2+1); i3<tam2[i1]; i3++){
                if(fracao[i1].valor[i2]==fracao[i1].valor[i3]){
                    printf("%d/%d equivalente a %d/%d\n", fracao[i1].x[i2], fracao[i1].y[i2], fracao[i1].x[i3], fracao[i1].y[i3]);
                    //indica se o programa entrou aqui, ou seja, se h� fra�oes equivalentes.
                    val++;
                }
            }
        }
        //se n�o houver equivalencia entre nenhum dos casos o validador continua como 0. Ao incrementar i1 o validador volta a receber 0.
        if(val==0){
            printf("Nao ha fracoes equivalentes na sequencia\n");
        }

    }

}

int main(){

    int casos, i1, i2, tam, *ti2;
    //o caractere serve para pegar o digito do teclado e transformar em uma variavel para usar de parada no programa.
    char c;
    scanf("%d", &casos);

    //aloca o struct com o numero de casos
    fracao=malloc(sizeof(struct numero)*casos);
    //ti2 � um vetor que guarda todos os indices de i2
    ti2=malloc(sizeof(int)*casos);
    for(i1=0; i1<casos; i1++, c=0){
        //aloca um valor inicial para o numerador e numerador
        fracao[i1].x=malloc(sizeof(int));
        fracao[i1].y=malloc(sizeof(int));
        //o caractere com o valor inteiro 10 representa o enter. Para isso foi usado a fun��o getchar.
        for(i2=0;c!=10;i2++){
            //realoca a mem�ria sempre que o usu�rio quiser digitar um novo valor
            fracao[i1].x=realloc(fracao[i1].x, sizeof(int)*(i2+1));
            fracao[i1].y=realloc(fracao[i1].y, sizeof(int)*(i2+1));
            //l� o x e o y de uma fra��o. o getchar do meio pega a /
            scanf("%d", &fracao[i1].x[i2]);
            getchar();
            scanf("%d", &fracao[i1].y[i2]);
            //este getchar pega o ultimo valor inserido para ver se foi enter e coloca na variavel c.
            c=getchar();
        }
        //cada vez que um caso itera, temos um indice diferente para i2. Depende do usuario.
        ti2[i1]=i2;
        fracao[i1].valor=malloc(sizeof(float)*(i2+1));
    }

    valorf(casos, ti2);
    compara(casos, ti2);

    free(fracao);

}
