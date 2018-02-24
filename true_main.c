/*
* Created by soren5 on 2/23/18.
*/
#include <stdio.h>

#define NUM_RETANGULOS 3 /*Numero de retangulos a colocar*/
#define MAX_POI 100
#define DEBUG 1
/*int solucoes[10000][NUM_RETANGULOS][4];*/
int iteracoes = 0;
int numeroSolucoes = 0;
int recursivas = 0;

/*Espaco de solucoes, cada solucao individual e descrita por dois pontos que descrevem a posicao de cada retangulo
solucoes[i][j][0] = coordenada x do canto inferior esquerdo
solucoes[i][j][1] = coordenada y do canto inferior esquerdo
solucoes[i][j][2] = coordenada x do canto superior direito
solucoes[i][j][3] = coordenada y do canto superior direito
*/

int verificarSolucao(int solucao[NUM_RETANGULOS][4]){
    /*Para verificar a solucao vamos encontrar o ponto mais alto no eixo do X e do Y, se o ultimo canto colocado
     * estiver alinhado com estes valores, a solucao e valida*/
    iteracoes += 1;
    int xMaximo = -1;
    int yMaximo = -1;
    int i;
    for(i = 0; i < NUM_RETANGULOS; i++){
        /*Para verificar a solucao vamos encontrar o ponto mais alto no eixo do X e do Y, se o ultimo canto colocado
     *
         * estiver alinhado com estes valores, a solucao e valida*/
        if(solucao[i][1] == 0 && solucao[i][2] > xMaximo)
            xMaximo = solucao[i][0] + solucao[i][2];
        if(solucao[i][0] == 0 && solucao[i][3] > yMaximo)
            yMaximo = solucao[i][1] + solucao[i][3];
    }
    int j;
    if(DEBUG) printf("X = %d , Y = %d\n", xMaximo, yMaximo);
    for(i = 0; i < NUM_RETANGULOS; i++){
        if(solucao[i][2] == xMaximo && solucao[i][3] == yMaximo){
            for(j = 0; j < NUM_RETANGULOS; j++){
                if(DEBUG) printf("%d, %d, %d, %d\n", solucao[j][0], solucao[j][1], solucao[j][2], solucao[j][3]);
            }
            if(DEBUG) printf("----------------------------\n");
            numeroSolucoes += 1;
            return 1;
        }
    }
    return 0;
}

int encontraIndice(int solucao[NUM_RETANGULOS][4]){
    int i;
    for(i = 0; i < NUM_RETANGULOS; i++){
        if(solucao[i][0] == -1){
            return i;
        }
    }
    return -1;
}

int* colocaRetangulo(int retanguloAColocar[2], int pontoOndeColocar[2], int indiceParaColocar, int solucao[NUM_RETANGULOS][4], int pontosInteresse[MAX_POI][2], int indicesDosPontos[2]){
    int i = 0;
    if(DEBUG) printf("COLOCANDO: Retangulo %d, %d em %d, %d\n", retanguloAColocar[0], retanguloAColocar[1], pontoOndeColocar[0], pontoOndeColocar[1]);
    solucao[indiceParaColocar][0] = pontoOndeColocar[0];
    solucao[indiceParaColocar][1] = pontoOndeColocar[1];
    solucao[indiceParaColocar][2] = pontoOndeColocar[0] + retanguloAColocar[0];
    solucao[indiceParaColocar][3] = pontoOndeColocar[1] + retanguloAColocar[1];

    for(i = 0; i < MAX_POI; i++){
        if(pontosInteresse[i][0] == -1){
            pontosInteresse[i][0] = pontoOndeColocar[0];
            pontosInteresse[i][1] = pontoOndeColocar[1] + retanguloAColocar[1];
            indicesDosPontos[0] = i;
            break;
        }
    }
    for(i = 0; i < MAX_POI; i++){
        if(pontosInteresse[i][0] == -1){
            pontosInteresse[i][0] = pontoOndeColocar[0] + retanguloAColocar[0];
            pontosInteresse[i][1] = pontoOndeColocar[1];
            indicesDosPontos[1] = i;
            break;
        }
    }
}

void retiraRetangulo(int indicesDosPontos[2], int indiceParaColocar, int solucao[NUM_RETANGULOS][4], int pontosInteresse[MAX_POI][2], int pontoUsado[2]) {
    if(DEBUG) printf("REMOVENDO: Retangulo em %d, %d\n", solucao[indiceParaColocar][0], solucao[indiceParaColocar][1]);
    solucao[indiceParaColocar][0] = -1;
    solucao[indiceParaColocar][1] = -1;
    solucao[indiceParaColocar][2] = -1;
    solucao[indiceParaColocar][3] = -1;
    pontosInteresse[indicesDosPontos[0]][0] = pontoUsado[0];
    pontosInteresse[indicesDosPontos[0]][1] = pontoUsado[1];
    pontosInteresse[indicesDosPontos[1]][0] = -1;
    pontosInteresse[indicesDosPontos[1]][1] = -1;
}
int recursiva(int retanguloEscolhido[2], int pontosInteresse[MAX_POI][2], int solucao[NUM_RETANGULOS][4], int retanguloPorColocar[NUM_RETANGULOS][2], int pontoUsado[2]){
    int i, j = 0;
    recursivas += 1;
    for(i = 0; i < MAX_POI; i++){
        if(pontosInteresse[i][0] != -1){
            int indiceParaColocar = encontraIndice(solucao);
            int xPontoInteresse = pontosInteresse[i][0];
            int yPontoInteresse = pontosInteresse[i][1];
            pontosInteresse[i][0] = -1;
            pontosInteresse[i][1] = -1;
            int indicesDosPontosUsados[2];
            int auxiliar[2];
            auxiliar[0] = xPontoInteresse;
            auxiliar[1] = yPontoInteresse;
            colocaRetangulo(retanguloEscolhido, auxiliar, indiceParaColocar, solucao, pontosInteresse, indicesDosPontosUsados);
            int check = 1;
            for(j = 0; j < NUM_RETANGULOS; j++){
                if(retanguloPorColocar[j][0] != -1){
                    check = 0;
                    int xRetanguloAColocar = retanguloPorColocar[j][0];
                    int yRetanguloAColocar = retanguloPorColocar[j][1];
                    retanguloPorColocar[j][0] = -1;
                    retanguloPorColocar[j][1] = -1;
                    int auxRetangulo[2];
                    auxRetangulo[0] = xRetanguloAColocar;
                    auxRetangulo[1] = yRetanguloAColocar;
                    recursiva(auxRetangulo, pontosInteresse, solucao, retanguloPorColocar, auxiliar);
                    auxRetangulo[0] = yRetanguloAColocar;
                    auxRetangulo[1] = xRetanguloAColocar;
                    recursiva(auxRetangulo, pontosInteresse, solucao, retanguloPorColocar, auxiliar);
                    retanguloPorColocar[j][0] = xRetanguloAColocar;
                    retanguloPorColocar[j][1] = yRetanguloAColocar;
                }
            }
            if(check){
                verificarSolucao(solucao);
            }
            pontosInteresse[i][0] = xPontoInteresse;
            pontosInteresse[i][1] = yPontoInteresse;
            retiraRetangulo(indicesDosPontosUsados, indiceParaColocar, solucao, pontosInteresse, auxiliar);
            return 0;
        }
    }
    return 0;
}

int main(){
    int pontosInteresse[MAX_POI][2];
    int solucao[NUM_RETANGULOS][4];
    int retanguloPorColocar[NUM_RETANGULOS][2];
    int i = 0;
    int j = 0;
    for(i = 0; i < NUM_RETANGULOS ; i++){
        for(j = 0; j < 4; j++){
            solucao[i][j] = -1;
        }
    }
    for(i = 0; i <= MAX_POI; i++){
        for(j = 0; j < 2; j++){
            pontosInteresse[i][j] = -1;
        }
    }
    pontosInteresse[0][0] = 0;
    pontosInteresse[0][1] = 0;
    retanguloPorColocar[0][0] = 4;
    retanguloPorColocar[0][1] = 12;
    retanguloPorColocar[1][0] = 6;
    retanguloPorColocar[1][1] = 5;
    retanguloPorColocar[2][0] = 5;
    retanguloPorColocar[2][1] = 6;
    int auxiliar[2];
    auxiliar[0] = -1;
    auxiliar[1] = -1;
    for(j = 0; j < NUM_RETANGULOS; j++){
        int xRetanguloAColocar = retanguloPorColocar[j][0];
        int yRetanguloAColocar = retanguloPorColocar[j][1];
        retanguloPorColocar[j][0] = -1;
        retanguloPorColocar[j][1] = -1;
        int auxRetangulo[2];
        auxRetangulo[0] = xRetanguloAColocar;
        auxRetangulo[1] = yRetanguloAColocar;
        recursiva(auxRetangulo, pontosInteresse, solucao, retanguloPorColocar, auxiliar);
        auxRetangulo[0] = yRetanguloAColocar;
        auxRetangulo[1] = xRetanguloAColocar;
        recursiva(auxRetangulo, pontosInteresse, solucao, retanguloPorColocar, auxiliar);
        retanguloPorColocar[j][0] = xRetanguloAColocar;
        retanguloPorColocar[j][1] = yRetanguloAColocar;
    }
    printf("Numero de recursivas %d\n", recursivas);
    printf("Numero de iteracoes %d\n", iteracoes);
    printf("Numero de solucoes %d\n", numeroSolucoes);
    return 0;
}

