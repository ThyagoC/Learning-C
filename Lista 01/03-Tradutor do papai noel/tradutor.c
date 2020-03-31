/*Você, como navegador, deverá
auxiliar o Papai Noel a gritar a frase “Feliz Natal” no idioma correto de cada país de que o trenó está
sobrevoando.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//struct guarda o nome dos paises e suas respectivas mensagens.
struct tradutor{

    char pais[15], mensagem[25];

}traduzir[24];
//a função abaixo preenche a struct acima.
void preenche_struct(){

    strcpy(traduzir[0].pais, "brasil");
    strcpy(traduzir[1].pais, "alemanha");
    strcpy(traduzir[2].pais, "austria");
    strcpy(traduzir[3].pais, "coreia");
    strcpy(traduzir[4].pais, "espanha");
    strcpy(traduzir[5].pais, "grecia");
    strcpy(traduzir[6].pais, "estados-unidos");
    strcpy(traduzir[7].pais, "inglaterra");
    strcpy(traduzir[8].pais, "australia");
    strcpy(traduzir[9].pais, "portugal");
    strcpy(traduzir[10].pais, "suecia");
    strcpy(traduzir[11].pais, "turquia");
    strcpy(traduzir[12].pais, "argentina");
    strcpy(traduzir[13].pais, "chile");
    strcpy(traduzir[14].pais, "mexico");
    strcpy(traduzir[15].pais, "antardida");
    strcpy(traduzir[16].pais, "canada");
    strcpy(traduzir[17].pais, "irlanda");
    strcpy(traduzir[18].pais, "belgica");
    strcpy(traduzir[19].pais, "italia");
    strcpy(traduzir[20].pais, "libia");
    strcpy(traduzir[21].pais, "siria");
    strcpy(traduzir[22].pais, "marrocos");
    strcpy(traduzir[23].pais, "japao");

    strcpy(traduzir[0].mensagem, "Feliz Natal!");
    strcpy(traduzir[1].mensagem, "Frohliche Weihnachten!");
    strcpy(traduzir[2].mensagem, "Frohe Weihnacht!");
    strcpy(traduzir[3].mensagem, "Chuk Sung Tan!");
    strcpy(traduzir[4].mensagem, "Feliz Navidad!");
    strcpy(traduzir[5].mensagem, "Kala Christougena!");
    strcpy(traduzir[6].mensagem, "Merry Christmas!");
    strcpy(traduzir[7].mensagem, "Merry Christmas!");
    strcpy(traduzir[8].mensagem, "Merry Christmas!");
    strcpy(traduzir[9].mensagem, "Feliz Natal!");
    strcpy(traduzir[10].mensagem, "God Jul!");
    strcpy(traduzir[11].mensagem, "Mutlu Noeller");
    strcpy(traduzir[12].mensagem, "Feliz Navidad!");
    strcpy(traduzir[13].mensagem, "Feliz Navidad!");
    strcpy(traduzir[14].mensagem, "Feliz Navidad!");
    strcpy(traduzir[15].mensagem, "Merry Christmas!");
    strcpy(traduzir[16].mensagem, "Merry Christmas!");
    strcpy(traduzir[17].mensagem, "Nollaig Shona Dhuit!");
    strcpy(traduzir[18].mensagem, "Zalig Kerstfeest!");
    strcpy(traduzir[19].mensagem, "Buon Natale!");
    strcpy(traduzir[20].mensagem, "Buon Natale!");
    strcpy(traduzir[21].mensagem, "Milad Mubarak!");
    strcpy(traduzir[22].mensagem, "Milad Mubarak!");
    strcpy(traduzir[23].mensagem, "Merii Kurisumasu!");

}
//função de comparação de strings.
int compara(char *nome1, char *nome2){
    //a função pode ser aprimorada sem o uso dos ifs:

    int i;
    //a função continua executando até que ambos os arrays tenham terminado sua extensão.
    for(i=0; nome1[i]!='\0' || nome2[i]!='\0'; i++){

        if(nome1[i]!=nome2[i]){
            return 1;
            break;
        }

    }

    return 0;
}

int main(){

    char nome_pais[50], i, i1;
    //carrega a struct com as informações colocadas na função.
    preenche_struct();
    //enquanto a condição for diferente de fim de arquivo.
    while(scanf("%s", nome_pais)!=EOF){

    //laço de comparação e exibição de resultados.
        for(i=0, i1=0; i<24; i++){

            if(compara(nome_pais, traduzir[i].pais)==0){
                puts(traduzir[i].mensagem);
                i1++;
                break;
            }

        }
        //se não entrar na função o i não incrementa, e será igual a zero.
        if(i1==0){
            printf("-- NOT FOUND --\n");
        }

    }
    return 0;
}
