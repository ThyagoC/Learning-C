/*Uma determinada professora quer ordenar seus alunos em ordem crescente de idade. Escreva um programa em C que leia os dados dos alunos, entre eles a data de nascimento, ordene os alunos em ordem
crescente de idade. Para isso seu programa deve ter uma função ComparaDataNasc() que recebe dois parâmetros. O primeiro corresponde a uma struct (ou um ponteiro para uma struct) que contém o dia, o mês e
o ano de nascimento de uma aluno. O segundo parâmetro tem o memo tipo de dado do primeiro e contém
a data de nascimento do segundo aluno. Essa função retorna 1 se o primeiro aluno é mais novo ou tem a
mesma idade do segundo aluno e retorna zero em caso contrário. Essa função deve ser chamada pela função
que ordena os alunos em ordem crescente de idade.*/
#include<stdio.h>
#include<stdlib.h>
//struct que comporta os dados dos alunos
struct pessoa{

    int matricula, dia, mes, ano, dias_vividos;
    char nome[200];

}*aluno, aux;

void tempo_vida(int quant){

    int i;
    //coloca, em dias, quanto tempo se passou desde o começo do ano até o nascimento.
    for(i=0; i<quant; i++){
        aluno[i].dias_vividos=(30*aluno[i].mes)+aluno[i].dia;
    }

}
int ComparaDataNasc(struct pessoa p1, struct pessoa p2){

    //verifica por ano ou por dias vividos
    if(p1.ano>p2.ano){
        return 1;
    }
    //se os dias passados desde o começo do ano forem maior, significa que a pessoa nasceu depois, ou seja, ela é mais nova.
    //só serve para comparar com anos iguais.
    else if(p1.ano==p2.ano && p1.dias_vividos>p2.dias_vividos){
        return 1;
    }
    //se for igual ou maior retorna o segundo.
    else{
        return 0;
    }

}
void ordena(int quant){

    int i1, i2;
    //Ordenação
    for(i1=0; i1<quant; i1++){
        for(i2=(i1+1); i2<quant; i2++){
            //Uso da função ComparaDataNasc para saber se o primeiro é menor que o segundo.
            if(ComparaDataNasc(aluno[i2], aluno[i1])==1){
                aux=aluno[i1];
                aluno[i1]=aluno[i2];
                aluno[i2]=aux;
            }
        }
    }

}

int main(){

    int num_alunos, i;
    scanf("%d", &num_alunos);

    aluno=malloc(sizeof(struct pessoa)*num_alunos);
    //leitura do vetor de structs
    for(i=0; i<num_alunos; i++){
        scanf("%d", &aluno[i].matricula);
        scanf("%d", &aluno[i].dia);
        scanf("%d", &aluno[i].mes);
        scanf("%d", &aluno[i].ano);
        getchar();
        gets(aluno[i].nome);
    }
    //função calcula o tempo de vida em dias.
    tempo_vida(num_alunos);
    //função ordena o vetor de struct.
    ordena(num_alunos);

    for(i=0; i<num_alunos; i++){
        printf("Matric.: %d Nome: %s Data Nasc: %d/%d/%d\n", aluno[i].matricula, aluno[i].nome, aluno[i].dia, aluno[i].mes, aluno[i].ano);
    }
    free(aluno);

    return 0;

}
