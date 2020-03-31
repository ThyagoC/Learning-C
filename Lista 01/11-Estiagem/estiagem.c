/* o programa verificar� como est� sendo o consumo de cada uma das pessoas da cidade e o consumo
m�dio de cada cidade por habitante.*/
#include<stdio.h>
#include<stdlib.h>
//struct casa abriga os moradores e o consumo de cada morador.
struct residencia{

    int moradores, consumo, consumo_pessoa;

};
//struct cidade abriga a struct casa.
struct regiao{

    int tam, morador, consumototal;
    float media_consumo;
    struct residencia *casa;

}*cidade;

void consumopessoal(int cidades){

    int i1, i2;
    //calcula o consumo por pessoa no valor inteiro -para quebrar o numero- faz isso para todas as cidades.
    for(i1=0; i1<cidades; i1++){
        for(i2=0; i2<cidade[i1].tam; i2++){
            cidade[i1].casa[i2].consumo_pessoa=(cidade[i1].casa[i2].consumo/cidade[i1].casa[i2].moradores);
        }
    }

}

void ordena(int cidades){

    int i1, i2, i3;
    struct residencia *aux;

    //aux recebe aloca��o dinamica.
    aux=malloc(sizeof(struct residencia));

    //ordena��o da struct de todas as cidades.
    for(i1=0; i1<cidades; i1++){ //la�o externo representando as cidades.
        for(i2=0; i2<cidade[i1].tam; i2++){//la�o interno representando a posi��o a ser comparada.
            for(i3=(i2+1); i3<cidade[i1].tam; i3++){//la�o mais interno representando os numeros que vao ser testados para ocupar i2.
                if(cidade[i1].casa[i3].consumo_pessoa<cidade[i1].casa[i2].consumo_pessoa){
                    aux[0]=cidade[i1].casa[i2];
                    cidade[i1].casa[i2]=cidade[i1].casa[i3];
                    cidade[i1].casa[i3]=aux[0];
                }
            }
        }
    }

    free(aux);


}

void mediacidade(int cidades){

    int i1, i2;

    for(i1=0; i1<cidades; i1++){
        cidade[i1].media_consumo=((float)cidade[i1].consumototal/(float)cidade[i1].morador);
    }

}

void junta(int cidades){

    int i1, i2, i3;
    struct residencia *aux;

    aux=malloc(sizeof(struct residencia));

    for(i1=0; i1<cidades; i1++){//percorre a cidade.
        for(i2=0; i2<cidade[i1].tam; i2++){//percorre a posi��o almejada.
            for(i3=(i2+1); i3<cidade[i1].tam; i3++){//percorre o numero candidato a posi��o.
                if(cidade[i1].casa[i2].consumo_pessoa==cidade[i1].casa[i3].consumo_pessoa){//se o consumo por pessoa for igual.
                    cidade[i1].casa[i2].moradores+=cidade[i1].casa[i3].moradores;//soma-se os moradores e mantem o consumo.
                    cidade[i1].tam--;//o indicador de tamanho diminui em 1.
                    cidade[i1].casa[i3]=cidade[i1].casa[cidade[i1].tam];//a ultima posi��o passa para a posi��o que era igual a i2.
                    cidade[i1].casa=realloc(cidade[i1].casa, sizeof(struct residencia)*cidade[i1].tam);//h� uma realoca��o de memoria.
                }                                                                                      //diminuindo uma casa.
            }
        }
    }

}

int main(){

    //i1 serve de indexa��o e indicador de tamanho da struct cidade.
    int casas=1, i1=0, i2, i3;
    //alocar uma quantidade inicial.
    cidade=malloc(sizeof(struct regiao)*i1);

    while(casas!=0){

        scanf("%d", &casas);
        if(casas==0){
            break;
        }
        //realocar sempre que o usu�rio precisar de mais um espa�o.
        cidade=realloc(cidade, sizeof(struct regiao)*(i1+1));
        cidade[i1].casa=malloc(sizeof(struct residencia)*casas); //para cada posi��o de cidade, aloca a quantidade de casas.
        cidade[i1].tam=casas;
        cidade[i1].morador=0;
        cidade[i1].consumototal=0;

        for(i2=0; i2<casas; i2++){
            scanf("%d %d", &cidade[i1].casa[i2].moradores, &cidade[i1].casa[i2].consumo);
            cidade[i1].morador+=cidade[i1].casa[i2].moradores;
            cidade[i1].consumototal=(cidade[i1].consumototal+cidade[i1].casa[i2].consumo);
        }
        i1++;
    }
    consumopessoal(i1);
    mediacidade(i1);
    junta(i1);
    ordena(i1);

    for(i2=0; i2<i1; i2++){
        printf("Cidade# %d:\n", (i2+1));
        for(i3=0; i3<cidade[i2].tam; i3++){
            printf("%d-%d ", cidade[i2].casa[i3].moradores, cidade[i2].casa[i3].consumo_pessoa);
        }
        printf("\n");
        printf("Consumo medio: %.2f m3.", cidade[i2].media_consumo);
        if(i2==i1-1){
            break;
            exit(0);
        }
        else{
            printf("\n\n");
        }
    }

}
