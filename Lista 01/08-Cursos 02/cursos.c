//Fazer um programa que calcule a mensalidade dos alunos, desta vez com alocação dinamica.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//struct de cursos.
struct dados{

    int cod;
    float val_credito;
    char *curso;

}*curso;
//struct de alunos.
struct pessoa{

    char *nome;
    int cod, creditos, indice;
    float mensalidade;

}*aluno;

//recebe a quantidade de alunos.
void mensalidade(int quant){

    int i;

    //a variavel indice guarda o indice do curso do aluno.
    for(i=0; i<quant; i++){
        aluno[i].mensalidade=(aluno[i].creditos*curso[aluno[i].indice].val_credito);
    }

}
void encontra(int quant_curso, int quant_aluno){

    int i1, i2;

    //guarda o indice do curso na variavel indice para facilitar o vinculo com o curso.
    for(i1=0; i1<quant_aluno; i1++){
        for(i2=0; i2<quant_curso; i2++){
            if(aluno[i1].cod==curso[i2].cod){
                aluno[i1].indice=i2;
                break;
            }
        }
    }

}

int main(){

    int num_curso, num_aluno, i;
    char buffer[1000];
    scanf("%d", &num_curso);

    //processamento/entrada - preenchimento das variaveis
    curso=malloc(sizeof(struct dados)*num_curso);
    for(i=0; i<num_curso; i++){
        scanf("%d", &curso[i].cod);
        scanf("%f", &curso[i].val_credito);
        getchar();
        gets(buffer);
        curso[i].curso=malloc(sizeof(char)*(strlen(buffer)+1));
        strcpy(curso[i].curso, buffer);
    }
    //entrada - leitura
    scanf("%d", &num_aluno);
    //processamento/entrada - preenchimento das variaveis
    aluno=malloc(sizeof(struct pessoa)*num_aluno);
    for(i=0; i<num_aluno; i++){
        getchar();
        gets(buffer);
        aluno[i].nome=malloc(sizeof(char)*(strlen(buffer)+1));
        strcpy(aluno[i].nome, buffer);
        scanf("%d", &aluno[i].cod);
        scanf("%d", &aluno[i].creditos);
    }
    //processamento - chamada de funções
    encontra(num_curso, num_aluno);
    mensalidade(num_aluno);
    //saida - informações processadas
    for(i=0; i<num_aluno; i++){
        printf("Aluno(a): %s Curso: %s Num. Creditos: %d Valor Credito: %.2f Mensalidade: %.2f\n", aluno[i].nome, curso[aluno[i].indice].curso, aluno[i].creditos, curso[aluno[i].indice].val_credito, aluno[i].mensalidade);
    }
    free(curso);
    free(aluno);

}
