/*
* Created by soren5 on 2/23/18.
*/
#include <stdio.h>

#define NUM_RETANGULOS 8 /*Numero de retangulos a colocar (no maximo sao 8)*/
#define MAX_POI 9
#define DEBUG 1
#define MAX_SOLUTIONS 10000

int solucoes[MAX_SOLUTIONS][NUM_RETANGULOS][4];
int iteracoes = 0;
int numeroSolucoes = 0;
int recursivas = 0;
int proximaSolucao = 0;
int numeroRetangulos;
int area = 0;


/*Espaco de solucoes, cada solucao individual e descrita por dois pontos que descrevem a posicao de cada retangulo
solucoes[i][j][0] = coordenada x do canto inferior esquerdo
solucoes[i][j][1] = coordenada y do canto inferior esquerdo
solucoes[i][j][2] = coordenada x do canto superior direito
solucoes[i][j][3] = coordenada y do canto superior direito
*/

int verificarSolucao(int solucao[NUM_RETANGULOS][4], int xMaximo, int yMaximo){
    /*Para verificar a solucao vamos encontrar o ponto mais alto no eixo do X e do Y, se o ultimo canto colocado
     * estiver alinhado com estes valores, a solucao e valida*/
    iteracoes += 1;
    int i,j;

    for(i = 0; i < numeroRetangulos; i++){
        if(solucao[i][2] == xMaximo && solucao[i][3] == yMaximo && xMaximo*yMaximo==area){
            if(DEBUG) printf("X = %d , Y = %d\n", xMaximo, yMaximo);
            for(j = 0; j < numeroRetangulos; j++){
                if(DEBUG) printf("%d, %d, %d, %d\n", solucao[j][0], solucao[j][1], solucao[j][2], solucao[j][3]);
                solucoes[proximaSolucao][j][0] = solucao[j][0];
                solucoes[proximaSolucao][j][1] = solucao[j][1];
                solucoes[proximaSolucao][j][2] = solucao[j][2];
                solucoes[proximaSolucao][j][3] = solucao[j][3];
                proximaSolucao++;
            }
            if(DEBUG) printf("----------------------------\n");
            numeroSolucoes += 1;
            return 1;
        }
    }
    return 0;
}

int verifica_X_maximo(int poiY, int retanguloX, int xMaximo){
    if (poiY == 0 && retanguloX > xMaximo)
        return retanguloX;
    return xMaximo;
}
int verifica_Y_maximo(int poiX, int retanguloY, int yMaximo){
    if (poiX == 0 && retanguloY > yMaximo)
        return retanguloY;
    return yMaximo;
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
   // if(DEBUG) printf("COLOCANDO: Retangulo %d, %d em %d, %d\n", retanguloAColocar[0], retanguloAColocar[1], pontoOndeColocar[0], pontoOndeColocar[1]);
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
    //if(DEBUG) printf("REMOVENDO: Retangulo em %d, %d\n", solucao[indiceParaColocar][0], solucao[indiceParaColocar][1]);
    solucao[indiceParaColocar][0] = -1;
    solucao[indiceParaColocar][1] = -1;
    solucao[indiceParaColocar][2] = -1;
    solucao[indiceParaColocar][3] = -1;
    pontosInteresse[indicesDosPontos[0]][0] = pontoUsado[0];
    pontosInteresse[indicesDosPontos[0]][1] = pontoUsado[1];
    pontosInteresse[indicesDosPontos[1]][0] = -1;
    pontosInteresse[indicesDosPontos[1]][1] = -1;
}

int recursiva(int retanguloEscolhido[2], int pontosInteresse[MAX_POI][2], int solucao[NUM_RETANGULOS][4], int retanguloPorColocar[NUM_RETANGULOS][2], int pontoUsado[2], int xMaximo, int yMaximo){
    int i, j = 0;
    recursivas += 1;
    int xMaximoNovo;
    int yMaximoNovo;

    for(i = 0; i < numeroRetangulos+1; i++){
        if(pontosInteresse[i][0] != -1){
            int indiceParaColocar = encontraIndice(solucao);
            int xPontoInteresse = pontosInteresse[i][0];
            int yPontoInteresse = pontosInteresse[i][1];
            //if(DEBUG) printf("X = %d , Y = %d\n", xMaximo, yMaximo);
            xMaximoNovo = verifica_X_maximo(yPontoInteresse,xPontoInteresse+retanguloEscolhido[0],xMaximo);
            yMaximoNovo = verifica_Y_maximo(xPontoInteresse,yPontoInteresse+retanguloEscolhido[1],yMaximo);
            //if(DEBUG) printf("%d,%d|%d,%d\n\n", xPontoInteresse, yPontoInteresse,retanguloEscolhido[0],retanguloEscolhido[1]);

            if (xMaximoNovo * yMaximoNovo <= area) {
                //if(DEBUG) printf("*X = %d , Y = %d\n", xMaximoNovo, yMaximoNovo);

                pontosInteresse[i][0] = -1;
                pontosInteresse[i][1] = -1;
                int indicesDosPontosUsados[2];
                int auxiliar[2];
                auxiliar[0] = xPontoInteresse;
                auxiliar[1] = yPontoInteresse;

                colocaRetangulo(retanguloEscolhido, auxiliar, indiceParaColocar, solucao, pontosInteresse, indicesDosPontosUsados);
                int check = 1;
                for(j = 0; j < numeroRetangulos; j++){
                    if(retanguloPorColocar[j][0] != -1){
                        check = 0;
                        int xRetanguloAColocar = retanguloPorColocar[j][0];
                        int yRetanguloAColocar = retanguloPorColocar[j][1];
                        retanguloPorColocar[j][0] = -1;
                        retanguloPorColocar[j][1] = -1;
                        int auxRetangulo[2];
                        auxRetangulo[0] = xRetanguloAColocar;
                        auxRetangulo[1] = yRetanguloAColocar;
                        recursiva(auxRetangulo, pontosInteresse, solucao, retanguloPorColocar, auxiliar,xMaximoNovo,yMaximoNovo);
                        auxRetangulo[0] = yRetanguloAColocar;
                        auxRetangulo[1] = xRetanguloAColocar;
                        recursiva(auxRetangulo, pontosInteresse, solucao, retanguloPorColocar, auxiliar,xMaximoNovo,yMaximoNovo);
                        retanguloPorColocar[j][0] = xRetanguloAColocar;
                        retanguloPorColocar[j][1] = yRetanguloAColocar;
                    }
                }
                if(check){
                    verificarSolucao(solucao,xMaximoNovo,yMaximoNovo);
                }
                pontosInteresse[i][0] = xPontoInteresse;
                pontosInteresse[i][1] = yPontoInteresse;
                retiraRetangulo(indicesDosPontosUsados, indiceParaColocar, solucao, pontosInteresse, auxiliar);
            }

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
    int k = 0;
    scanf("%d",&numeroRetangulos);

    for (i = 0; i < numeroRetangulos; i++) {
        scanf("%d %d",&(retanguloPorColocar[i][0]),&(retanguloPorColocar[i][1]));
        area += retanguloPorColocar[i][0] * retanguloPorColocar[i][1];
    }
    printf("Area := %d\n",area);
    for(i = 0; i < numeroRetangulos ; i++){
        //printf("*%d %d\n",retanguloPorColocar[i][0],retanguloPorColocar[i][1]);
        solucao[i][0] = -1;
        solucao[i][1] = -1;
        solucao[i][2] = -1;
        solucao[i][3] = -1;
    }
    for(i = 0; i < numeroRetangulos + 1; i++){
        pontosInteresse[i][0] = -1;
        pontosInteresse[i][1] = -1;
    }
    for(i = 0; i <MAX_SOLUTIONS; i++){
        for(j = 0; j < numeroRetangulos; j++){
            solucoes[i][j][0] = -1;
            solucoes[i][j][1] = -1;
            solucoes[i][j][2] = -1;
            solucoes[i][j][3] = -1;
        }
    }

    pontosInteresse[0][0] = 0;
    pontosInteresse[0][1] = 0;
    /*
    retanguloPorColocar[0][0] = 4;
    retanguloPorColocar[0][1] = 12;
    retanguloPorColocar[1][0] = 6;
    retanguloPorColocar[1][1] = 5;
    retanguloPorColocar[2][0] = 5;
    retanguloPorColocar[2][1] = 6;*/
    int auxiliar[2];
    auxiliar[0] = -1;
    auxiliar[1] = -1;
    for(j = 0; j < numeroRetangulos; j++){
        int xRetanguloAColocar = retanguloPorColocar[j][0];
        int yRetanguloAColocar = retanguloPorColocar[j][1];
        retanguloPorColocar[j][0] = -1;
        retanguloPorColocar[j][1] = -1;
        int auxRetangulo[2];
        auxRetangulo[0] = xRetanguloAColocar;
        auxRetangulo[1] = yRetanguloAColocar;
        recursiva(auxRetangulo, pontosInteresse, solucao, retanguloPorColocar, auxiliar,0,0);
        auxRetangulo[0] = yRetanguloAColocar;
        auxRetangulo[1] = xRetanguloAColocar;
        recursiva(auxRetangulo, pontosInteresse, solucao, retanguloPorColocar, auxiliar,0,0);
        retanguloPorColocar[j][0] = xRetanguloAColocar;
        retanguloPorColocar[j][1] = yRetanguloAColocar;
    }
    printf("Numero de recursivas %d\n", recursivas);
    printf("Numero de iteracoes %d\n", iteracoes);
    printf("Numero de solucoes %d\n", numeroSolucoes);
    int check;
    /*
    for(i = 0; i <MAX_SOLUTIONS; i++){
        for(j = i; j <MAX_SOLUTIONS; j++){
            check = 1;
            for(k = 0; k < NUM_RETANGULOS; k++){
                if(solucoes[i][k][2] != solucoes[j][k][2] || solucoes)
            }
        }
    }*/
    return 0;
}

