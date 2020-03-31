/*Faça uma função que calcule, imprima e retorne as as raízes de uma equação
de segundo grau. Para isso, crie as estruturas Complex e RaizEqu2, sendo Complex formada por duas
variáveis do tipo float, representando a parte real e imaginária; e RaizEqu2, contendo duas variáveis
Complex, representando as duas raízes da equação.*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct complex{

    float real, imaginaria;

};

struct RaizEqu2{

    struct complex raiz1, raiz2;

};

struct RaizEqu2 calcula_raiz_equ_2(float a, float b, float c){

    struct RaizEqu2 requad;

    if((pow(b, 2)-4*a*c)<0){
        requad.raiz1.real=((-b)/(2*a));
        requad.raiz2.real=((-b)/(2*a));
        requad.raiz1.imaginaria=(sqrt((-1)*(pow(b, 2)-4*a*c))/(2*a));
        requad.raiz2.imaginaria=-(sqrt((-1)*(pow(b, 2)-4*a*c))/(2*a));

    }
    else{
        requad.raiz1.real=((-b)+sqrt(pow(b, 2)-4*a*c))/(2*a);
        requad.raiz2.real=((-b)-sqrt(pow(b, 2)-4*a*c))/(2*a);
        requad.raiz1.imaginaria=0;
        requad.raiz2.imaginaria=0;
    }

    return requad;

}

void complex_print(struct complex c){

    if(c.real!=0 && c.imaginaria!=0){
        if(c.imaginaria==1){
            printf("%.2f+i", c.real);
        }
        else if(c.imaginaria==-1){
            printf("%.2f-i", c.real);
        }
        else{
            printf("%.2f%+.2fi", c.real, c.imaginaria);
        }
    }
    else if(c.real!=0){
        printf("%.2f", c.real);
    }
    else if(c.imaginaria!=0){
        if(c.imaginaria==1){
            printf("i");
        }
        else if(c.imaginaria==-1){
            printf("-i");
        }
        else{
            printf("%.2fi", c.imaginaria);
        }
    }
    else{
        printf("0.00");
    }

}

int main(){

    float a, b, c;
    struct RaizEqu2 resultado;
    scanf("%f%f%f", &a, &b, &c);

    resultado=calcula_raiz_equ_2(a, b, c);
    printf("x1 = ");
    complex_print(resultado.raiz1);
    printf("\n");
    printf("x2 = ");
    complex_print(resultado.raiz2);

    return 0;

}
