//Faça um programa para somar ou subtrair polinômios.
#include<stdio.h>
#include<stdlib.h>

struct polinomio{

    float *coeficiente;
    int *expoente, tam;

}*termo, *resultado, aux;

void calcula(int tam1, char opera){

    int i1, i2, i3, i4, vali;

    //laço externo que representa a struct termo.
    for(i1=0; i1<(tam1*2); i1+=2){
            //definir um tamanho maximo possivel para a struct, levando em conta o tamanho maximo dos dois termos.
            resultado[i1/2].coeficiente=malloc(sizeof(float)*(termo[i1].tam+termo[i1+1].tam));
            resultado[i1/2].expoente=malloc(sizeof(float)*(termo[i1].tam+termo[i1+1].tam));
            resultado[i1/2].tam=(termo[i1].tam+termo[i1+1].tam);
        //laço que percorre o termo na primeira struct.
        for(i2=0, i4=0, vali=0; i2<termo[i1].tam; i2++, vali=0){
            //laço que percorre o termo da 2 struct.
            for(i3=0; i3<termo[i1+1].tam; i3++){
                //se o expoente do primeiro for igual ao expoente do segundo.
                if(termo[i1].expoente[i2]==termo[i1+1].expoente[i3]){
                    //realiza a soma ou subtração, dependendo do operador.
                    if(opera=='+'){
                        resultado[i1/2].coeficiente[i4]=(termo[i1].coeficiente[i2]+termo[i1+1].coeficiente[i3]);
                        resultado[i1/2].expoente[i4]=termo[i1].expoente[i2];
                        vali++;
                        i4++;
                    }
                    else if(opera=='-'){
                        resultado[i1/2].coeficiente[i4]=(termo[i1].coeficiente[i2]-termo[i1+1].coeficiente[i3]);
                        resultado[i1/2].expoente[i4]=termo[i1].expoente[i2];
                        vali++;
                        i4++;
                    }
                }
            }
            //Se o expoente do primeiro termo for diferente do expoente de todos os valores do segundo termo, vali retorna zero
            //o que significa que não há nenhum expoente igual a esse, e esse deve ser mandado para o vetor de resultados sem
            //qualquer operação.
            if(vali==0 && termo[i1].coeficiente[i2]!=0){
                resultado[i1/2].coeficiente[i4]=termo[i1].coeficiente[i2];
                resultado[i1/2].expoente[i4]=termo[i1].expoente[i2];
                i4++;
            }
        }

        //compara os valores do 2 termo por todos os valores do primeiro termo, com o objetivo de verificar algum expoente diferente
        //dentro do segundo termo.
        for(i2=0, vali=0; i2<termo[i1+1].tam; i2++, vali=0){

            for(i3=0; i3<termo[i1].tam; i3++){
                if(termo[i1+1].expoente[i2]==termo[i1].expoente[i3]){
                    vali++;
                }
            }
            //se não houver nenhum valor igual ao valor do segundo termo no primeiro termo, esse deverá ser levado ao vetor de
            //resultados sem qualquer operação.
            if(vali==0 && termo[i1+1].coeficiente[i2]!=0){
                resultado[i1/2].coeficiente[i4]=termo[i1+1].coeficiente[i2];
                resultado[i1/2].expoente[i4]=termo[i1+1].expoente[i2];
                i4++;
            }
        }
        resultado[i1/2].tam=i4;
        resultado[i1/2].coeficiente=realloc(resultado[i1/2].coeficiente, sizeof(float)*resultado[i1/2].tam);
        resultado[i1/2].coeficiente=realloc(resultado[i1/2].coeficiente, sizeof(float)*resultado[i1/2].tam);
        for(i2=0; i2<i4; i2++){
        }
    }

}

void ordena(int tam1){

    int i1, i2, i3;

    //é uma variavel para auxiliar na ordenação.
    aux.coeficiente=malloc(sizeof(float));
    aux.expoente=malloc(sizeof(int));
    //a função está ordenando os vetores internos na struct.
    for(i1=0; i1<tam1; i1++){
        for(i2=0; i2<resultado[i1].tam; i2++){
            for(i3=(i2+1); i3<resultado[i1].tam; i3++){
                if(resultado[i1].expoente[i3]>resultado[i1].expoente[i2]){
                    //os termos trocam de coeficiente e expoente ao mesmo tempo.
                    aux.coeficiente[0]=resultado[i1].coeficiente[i2];
                    aux.expoente[0]=resultado[i1].expoente[i2];
                    resultado[i1].coeficiente[i2]=resultado[i1].coeficiente[i3];
                    resultado[i1].expoente[i2]=resultado[i1].expoente[i3];
                    resultado[i1].coeficiente[i3]=aux.coeficiente[0];
                    resultado[i1].expoente[i3]=aux.expoente[0];
                }
            }
        }
    }

}

int main(){

    int casos, i1, i2, i3, lim1;
    char operador;
    scanf("%d", &casos);

    //cada caso tem 2 polinomios.
    termo=malloc(sizeof(struct polinomio)*(casos*2));
    //aloca o resultado, este sim com 1 função para cada caso.
    resultado=malloc(sizeof(struct polinomio)*casos);
    //teste de alocação
    if(termo==NULL || resultado==NULL){
        printf("MEMORIA INSULFICIENTE\n");
    }

    for(i1=0; i1<casos;i1++){

        getchar();
        scanf("%c", &operador);
        //vai ler 2 termos para cada numero de casos i1, guardando seu resultado na struct sem sobrescrever.
        for(i2=(i1*2), lim1=i2+2; i2<lim1; i2++){
            scanf("%d", &termo[i2].tam);
            //a cada iteração o coeficiente e o expoente são alocados dinamicamente.
            termo[i2].coeficiente=malloc(sizeof(float)*termo[i2].tam);
            termo[i2].expoente=malloc(sizeof(int)*termo[i2].tam);
            if(termo[i2].coeficiente==NULL || termo[i2].expoente==NULL){
                printf("MEMORIA INSULFICIENTE\n");
            }
            //guardar os valores.
            for(i3=0; i3<termo[i2].tam; i3++){
                scanf("%f %d", &termo[i2].coeficiente[i3], &termo[i2].expoente[i3]);
            }

        }

    }
    calcula(casos, operador);
    free(termo);
    ordena(casos);

    //QUESTAO DE FORMATAÇÃO.
    for(i1=0; i1<casos; i1++){
        for(i2=0; i2<resultado[i1].tam; i2++){
            if(resultado[i1].expoente[i2]==0 && resultado[i1].coeficiente[i2]!=0){
                printf("%+.2f", resultado[i1].coeficiente[i2]);
            }
            else if(resultado[i1].coeficiente[i2]!=0){
                printf("%+.2fX^%d", resultado[i1].coeficiente[i2], resultado[i1].expoente[i2]);
            }
        }
        printf("\n");
    }
    //FORMATAÇÃO.

    free(resultado);
    return 0;
}
