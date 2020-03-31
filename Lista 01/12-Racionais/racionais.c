/*Faça um programa que defina um novo tipo de dado através de uma estrutura chamada tRacional, com
os componentes inteiros a e b, conforme a definição anterior.*/
#include<stdio.h>
#include<stdlib.h>

struct tRacional{

    int numerador, denominador;
    char operador;

};

int MMC(int num1, int num2){

    int i1=2, mmc=1;

    while(num1!=1 || num2!=1){

        if(num1%i1==0 && num2%i1==0){//se o resto da divisão dos dois por i1 for igual a zero, os dois são divididos por i1.
            num1/=i1;
            num2/=i1;
            mmc*=i1;//mmc multiplica por i1.
            i1=2;//reinicia os divisores
        }
        else if(num2%i1==0){//se o numero 2 tiver o resto 0, só o numero 2 divide.
            num2/=i1;
            mmc*=i1;
            i1=2;
        }
        else if(num1%i1==0){//se o numero 1 tiver o resto 0, só o numero 1 divide
            num1/=i1;
            mmc*=i1;
            i1=2;
        }
        else{//caso nenhum seja divisível, aumentamos em um o divisor.
            i1++;
        }

    }
    return mmc;

}

struct tRacional racional(int numerador, int denominador){//a atividade pede para fazer essa função. Pega 2ints e coloca na frac.

    struct tRacional rac;
    rac.numerador=numerador;
    rac.denominador=denominador;
    return rac;

}

struct tRacional negativo(struct tRacional r){//transforma a fração em negativo.

    r.numerador*=(-1);

    return r;

}

struct tRacional soma(struct tRacional f1, struct tRacional f2){//soma duas frações. Utiliza a função MMC.

    int mmc;
    struct tRacional sum;

    mmc=MMC(f1.denominador, f2.denominador);
    sum.numerador=((mmc/f1.denominador)*f1.numerador)+((mmc/f2.denominador)*f2.numerador);
    sum.denominador=mmc;

    return sum;

}

struct tRacional mult(struct tRacional f1, struct tRacional f2){//multiplica duas frações.

    struct tRacional r;
    r.numerador=f1.numerador*f2.numerador;
    r.denominador=f1.denominador*f2.denominador;

    return r;

}

struct tRacional divisao(struct tRacional f1, struct tRacional f2){//divide duas frações.

    struct tRacional r;
    r.numerador=(f1.numerador*f2.denominador);
    r.denominador=(f1.denominador*f2.numerador);

    return r;

}

void reduzFracao(struct tRacional *r){//resuz a fração ao menor possível.

    int i1;

    if(r[0].numerador>r[0].denominador){
            i1=r[0].numerador;
    }
    else{
        i1=r[0].denominador;
    }

    while(i1!=1){

        if(r[0].numerador%i1==0 && r[0].denominador%i1==0){//se denominador e numerador dividirem por i1.
            r[0].numerador/=i1;
            r[0].denominador/=i1;

            if(r[0].numerador>r[0].denominador){
                i1=r[0].numerador;
            }
            else{
                i1=r[0].denominador;
            }
        }
        else{
            i1--;
        }

    }

}

int main(){

    int tamfrac=2, numerador1, numerador2, denominador1, denominador2, i1;
    struct tRacional *fracao, *resultado;


    //LEITURA - GRAVACAO DE DADOS
    fracao=malloc(sizeof(struct tRacional)*2);//lembrar de diminuir 2 do tamanho ao final.
    resultado=malloc(sizeof(struct tRacional)*1);
    if(fracao==NULL || resultado==NULL){
        printf("Memoria insulficiente\n");
    }

    while(scanf("%d %d %c %d %d", &numerador1, &denominador1, &resultado[(tamfrac/2)-1].operador, &numerador2, &denominador2)!=EOF){

        fracao[tamfrac-2]=racional(numerador1, denominador1);//preenche a struct com o numerador e o denominador.
        fracao[tamfrac-1]=racional(numerador2, denominador2);

        //PROCESSAMENTO.
        if(resultado[(tamfrac/2)-1].operador=='+'){
            resultado[(tamfrac/2)-1]=soma(fracao[tamfrac-2], fracao[tamfrac-1]);
            reduzFracao(&resultado[(tamfrac/2)-1]);
        }
        else if(resultado[(tamfrac/2)-1].operador=='-'){
            fracao[tamfrac-1]=negativo(fracao[tamfrac-1]);
            resultado[(tamfrac/2)-1]=soma(fracao[tamfrac-2], fracao[tamfrac-1]);
            reduzFracao(&resultado[(tamfrac/2)-1]);
        }
        else if(resultado[(tamfrac/2)-1].operador=='*'){
            resultado[(tamfrac/2)-1]=mult(fracao[tamfrac-2], fracao[tamfrac-1]);
            reduzFracao(&resultado[(tamfrac/2)-1]);
        }
        else if(resultado[(tamfrac/2)-1].operador=='/'){
            resultado[(tamfrac/2)-1]=divisao(fracao[tamfrac-2], fracao[tamfrac-1]);
            reduzFracao(&resultado[(tamfrac/2)-1]);
        }
        //PROCESSAMENTO.


        tamfrac+=2;//ja aloca para a proxima chamada, tendo em vista que nao sabemos quando o arquivo termina.
        fracao=realloc(fracao, sizeof(struct tRacional)*tamfrac);
        resultado=realloc(resultado, sizeof(struct tRacional)*(tamfrac/2));
        if(fracao==NULL || resultado==NULL){
            printf("Memoria insulficiente\n");
        }

    }

    tamfrac-=2;
    fracao=realloc(fracao, sizeof(struct tRacional)*tamfrac);//diminuição do 2 que sobra.
    resultado=realloc(resultado, sizeof(struct tRacional)*(tamfrac/2));
    if(fracao==NULL || resultado==NULL){
        printf("Memoria insulficiente\n");
    }
    //LEITURA - GRAVACAO DE DADOS

    free(fracao);

    //SAIDA
    for(i1=0; i1<(tamfrac/2); i1++){//imprime os resultados
        printf("%d %d\n", resultado[i1].numerador, resultado[i1].denominador);
    }
    //SAIDA
    free(resultado);

    return 0;

}
