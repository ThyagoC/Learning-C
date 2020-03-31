/*e faça um programa capaz de ler sequências de frações e para cada sequência
indicar quais pares são equivalentes entre si. O programa deve comparar a primeira fração com todas as
outras seguintes, depois deve comparar a segunda com todas as outras seguintes e assim por diante, de modo
que a posição na lista da primeira fração de um par de frações seja sempre menor que a posição da segunda
fração do par. NESTA VERSÃO A ENTRADA NÃO É INDICADA*/
#include<stdio.h>
#include<stdlib.h>

struct numero{

    int *x;
    int *y;
    //recebe o valor da divisão da fração
    float *valor;

}*fracao;

void valorf(int tam, int *tam2){

    //calcula o valor da fração
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
        //i2 representa o indice dos vetores internos à struct
        for(i2=0; i2<tam2[i1]; i2++){
            for(i3=(i2+1); i3<tam2[i1]; i3++){
                if(fracao[i1].valor[i2]==fracao[i1].valor[i3]){
                    printf("%d/%d equivalente a %d/%d\n", fracao[i1].x[i2], fracao[i1].y[i2], fracao[i1].x[i3], fracao[i1].y[i3]);
                    //indica se o programa entrou aqui, ou seja, se há fraçoes equivalentes.
                    val++;
                }
            }
        }
        //se não houver equivalencia entre nenhum dos casos o validador continua como 0. Ao incrementar i1 o validador volta a receber 0.
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
    //ti2 é um vetor que guarda todos os indices de i2
    ti2=malloc(sizeof(int)*casos);
    for(i1=0; i1<casos; i1++, c=0){
        //aloca um valor inicial para o numerador e numerador
        fracao[i1].x=malloc(sizeof(int));
        fracao[i1].y=malloc(sizeof(int));
        //o caractere com o valor inteiro 10 representa o enter. Para isso foi usado a função getchar.
        for(i2=0;c!=10;i2++){
            //realoca a memória sempre que o usuário quiser digitar um novo valor
            fracao[i1].x=realloc(fracao[i1].x, sizeof(int)*(i2+1));
            fracao[i1].y=realloc(fracao[i1].y, sizeof(int)*(i2+1));
            //lê o x e o y de uma fração. o getchar do meio pega a /
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
