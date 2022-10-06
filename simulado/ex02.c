#include <stdio.h>
#include <stdlib.h>

#define AC 1
#define AL 2
#define AM 3
#define AP 4
#define BA 5
#define CE 6
#define DF 7
#define ES 8
#define GO 9
#define MA 10
#define MG 11
#define MS 12
#define MT 13
#define PA 14
#define PB 15
#define PE 16
#define PI 17
#define PR 18
#define RJ 19
#define RN 20
#define RO 21
#define RR 22
#define RS 23
#define SC 24
#define SE 25
#define SP 26
#define TO 27

typedef struct vertice{
    int visitado;
    int lista_adj[10];
    int tamanho_lista;
}Vertice;

void addAresta(Vertice * v, int x, int y)
{
    v[x].lista_adj[ v[x].tamanho_lista++ ] = y;
}

char * traduz(int i);

void dfs(Vertice * v, int i)
{
    v[i].visitado = 1;
    printf("%s, ", traduz(i));

    for(int j = 0; j < v[i].tamanho_lista; j++){
        int elemento = v[i].lista_adj[j];
        if(v[elemento].visitado == 0){
            dfs(v, elemento);
        }
    }
}

int main(){

    int n = 27;

    Vertice * vertices = malloc(sizeof(Vertice)*(n+1));

    addAresta(vertices, AC, AM);
    addAresta(vertices, AC, RO);

    addAresta(vertices, AL, BA);
    addAresta(vertices, AL, PE);
    addAresta(vertices, AL, SE);

    addAresta(vertices, AM, AC);
    addAresta(vertices, AM, MT);
    addAresta(vertices, AM, PA);
    addAresta(vertices, AM, RO);
    addAresta(vertices, AM, RR);

    addAresta(vertices, AP, PA);

    addAresta(vertices, BA, AL);
    addAresta(vertices, BA, ES);
    addAresta(vertices, BA, GO);
    addAresta(vertices, BA, MG);
    addAresta(vertices, BA, PE);
    addAresta(vertices, BA, PI);
    addAresta(vertices, BA, SE);
    addAresta(vertices, BA, TO);

    addAresta(vertices, CE, PB);
    addAresta(vertices, CE, PE);
    addAresta(vertices, CE, PI);
    addAresta(vertices, CE, RN);

    addAresta(vertices, DF, GO);

    addAresta(vertices, ES, BA);
    addAresta(vertices, ES, MG);
    addAresta(vertices, ES, RJ);

    addAresta(vertices, GO, BA);
    addAresta(vertices, GO, DF);
    addAresta(vertices, GO, MG);
    addAresta(vertices, GO, MS);
    addAresta(vertices, GO, MT);
    addAresta(vertices, GO, TO);

    addAresta(vertices, MA, PA);
    addAresta(vertices, MA, PI);
    addAresta(vertices, MA, TO);

    addAresta(vertices, MG, BA);
    addAresta(vertices, MG, ES);
    addAresta(vertices, MG, GO);
    addAresta(vertices, MG, MS);
    addAresta(vertices, MG, RJ);
    addAresta(vertices, MG, SP);

    addAresta(vertices, MS, GO);
    addAresta(vertices, MS, MG);
    addAresta(vertices, MS, MT);
    addAresta(vertices, MS, PR);
    addAresta(vertices, MS, SP);

    addAresta(vertices, MT, AM);
    addAresta(vertices, MT, GO);
    addAresta(vertices, MT, MS);
    addAresta(vertices, MT, PA);
    addAresta(vertices, MT, RO);
    addAresta(vertices, MT, TO);

    addAresta(vertices, PA, AM);
    addAresta(vertices, PA, AP);
    addAresta(vertices, PA, MA);
    addAresta(vertices, PA, MT);
    addAresta(vertices, PA, RR);
    addAresta(vertices, PA, TO);

    addAresta(vertices, PB, CE);
    addAresta(vertices, PB, PE);
    addAresta(vertices, PB, RN);

    addAresta(vertices, PE, AL);
    addAresta(vertices, PE, BA);
    addAresta(vertices, PE, CE);
    addAresta(vertices, PE, PB);
    addAresta(vertices, PE, PI);

    addAresta(vertices, PI, BA);
    addAresta(vertices, PI, CE);
    addAresta(vertices, PI, MA);
    addAresta(vertices, PI, PE);
    addAresta(vertices, PI, TO);

    addAresta(vertices, PR, MS);
    addAresta(vertices, PR, SC);
    addAresta(vertices, PR, SP);

    addAresta(vertices, RJ, ES);
    addAresta(vertices, RJ, MG);
    addAresta(vertices, RJ, SP);

    addAresta(vertices, RN, CE);
    addAresta(vertices, RN, PB);

    addAresta(vertices, RO, AC);
    addAresta(vertices, RO, AM);
    addAresta(vertices, RO, MT);

    addAresta(vertices, RR, AM);
    addAresta(vertices, RR, PA);

    addAresta(vertices, RS, SC);

    addAresta(vertices, SC, PR);
    addAresta(vertices, SC, RS);

    addAresta(vertices, SE, AL);
    addAresta(vertices, SE, BA);

    addAresta(vertices, SP, MG);
    addAresta(vertices, SP, MS);
    addAresta(vertices, SP, PR);
    addAresta(vertices, SP, RJ);

    addAresta(vertices, TO, BA);
    addAresta(vertices, TO, GO);
    addAresta(vertices, TO, MA);
    addAresta(vertices, TO, MT);
    addAresta(vertices, TO, PA);
    addAresta(vertices, TO, PI);

    printf("dfs: ");
    dfs(vertices, TO);

    printf("\n");
    return 0;
}

char * traduz(int i)
{
    switch(i){
        case 1: 
            return "AC";
        case 2: 
            return "AL";
        case 3: 
            return "AM";
        case 4: 
            return "AP";
        case 5: 
            return "BA";
        case 6: 
            return "CE";
        case 7: 
            return "DF";
        case 8: 
            return "ES";
        case 9: 
            return "GO";
        case 10: 
            return "MA";
        case 11: 
            return "MG";
        case 12: 
            return "MS";
        case 13: 
            return "MT";
        case 14: 
            return "PA";
        case 15: 
            return "PB";
        case 16: 
            return "PE";
        case 17: 
            return "PI";
        case 18: 
            return "PR";
        case 19: 
            return "RJ";
        case 20: 
            return "RN";
        case 21: 
            return "RO";
        case 22: 
            return "RR";
        case 23: 
            return "RS";
        case 24: 
            return "SC";
        case 25: 
            return "SE";
        case 26: 
            return "SP";
        case 27: 
            return "TO";
        default:
            return "--";
    }
}