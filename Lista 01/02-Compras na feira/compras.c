/*e faça um programa que calcule o valor que precisa
levar para poder comprar tudo que está em sua lista de compras, considerando a quantidade de cada tipo de
fruta ou legume e os preços destes itens.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct itens{

    char nome[50];
    float preco;

}*produto;
struct comprar{

    char nome[50];
    int quant;
    float valor;

}*lista_compras;

int compara_string(char *feira, char *comprar){

    int c, f, com;

    for(c=0, f=0, com=0; feira[c]!='\0' || comprar[c]!='\0'; c++){

        if(feira[c]==comprar[c]){
            f++;
            com++;
        }
        else{
            return 1;
            break;
        }

    }

    if(f==com){
        return 0;
    }

}
float valor_total(int num_prod, int num_fei){

    int c, c1;
    float vt;

    for(c=0; c<num_prod; c++){

        for(c1=0; c1<num_fei; c1++){
            if(compara_string(produto[c1].nome, lista_compras[c].nome)==0){
                lista_compras[c].valor=lista_compras[c].quant*produto[c1].preco;
            }
        }

    }
    for(c=0, vt=0; c<num_prod; c++){
        vt+=lista_compras[c].valor;
    }

    return vt;

}

int main(){

    int num_casos, i;
    scanf("%d", &num_casos);

    for(i=0; i<num_casos; i++){

        int num_produtos_feira, num_produtos_comprar, c, c1;

        scanf("%d", &num_produtos_feira);
        produto=malloc(sizeof(struct itens)*num_produtos_feira);

        for(c=0; c<num_produtos_feira; c++){

            scanf("%s", produto[c].nome);
            getchar();
            scanf("%f", &produto[c].preco);

        }

        scanf("%d", &num_produtos_comprar);
        lista_compras=malloc(sizeof(struct comprar)*num_produtos_comprar);

        for(c=0; c<num_produtos_comprar; c++){

            scanf("%s", &lista_compras[c].nome);
            getchar();
            scanf("%d", &lista_compras[c].quant);

        }
        printf("R$ %.2f\n", valor_total(num_produtos_comprar, num_produtos_feira));
    }

}
