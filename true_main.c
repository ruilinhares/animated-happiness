//
// Created by soren5 on 2/23/18.
//
#include <stdio.h>

#define NUM_RETANGULOS 3 /*Numero de retangulos a colocar*/
#define DEBUG 1
int solucoes[10000][NUM_RETANGULOS][4];

/*Espaco de solucoes, cada solucao individual e descrita por dois pontos que descrevem a posicao de cada retangulo
solucoes[i][j][0] = coordenada x do canto inferior esquerdo
solucoes[i][j][1] = coordenada y do canto inferior esquerdo
solucoes[i][j][2] = coordenada x do canto superior direito
solucoes[i][j][3] = coordenada y do canto superior direito
*/

int verificarSolucao(int **solucao){
    /*Para verificar a solucao vamos encontrar o ponto mais alto no eixo do X e do Y, se o ultimo canto colocado
     * estiver alinhado com estes valores, a solucao e valida*/
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
        if(solucoes[i][2] == xMaximo && solucoes[i][3] == yMaximo){
            for(j = 0; j < NUM_RETANGULOS; j++){
                if(DEBUG) printf("%d, %d, %d, %d\n", solucoes[j][0], solucoes[j][1], solucoes[j][2], solucoes[j][3]);
            }
            if(DEBUG) printf("----------------------------\n");
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

void colocaRetangulo(int retanguloAColocar, int pontoOndeColocar[2], int indiceParaColocar, int solucao[NUM_RETANGULOS][4]){
    solucoes[indiceParaColocar][0] = pontoOndeColocar[0];
    solucoes[indiceParaColocar][1] = pontoOndeColocar[1];
    solucoes[indiceParaColocar][2] = pontoOndeColocar[0] + retanguloAColocar[0];
    solucoes[indiceParaColocar][3] = pontoOndeColocar[1] + retanguloAColocar[1];
}




int recursiva(int retanguloEscolhido[2], int pontosInteresse[NUM_RETANGULOS + 1][2], int solucao[NUM_RETANGULOS][4], int retanguloPorColocar[NUM_RETANGULOS][2]){
    int i, j = 0;
    for(i = 0; i <= NUM_RETANGULOS; i++){
        if(pontosInteresse[i][0] != -1){
            if(DEBUG) printf("Ola, vou por o retangulo %d, %d em %d, %d\n");
            int indiceParaColocar = encontraIndice(solucao);
            colocaRetangulo(retanguloEscolhido, pontosInteresse[i], indiceParaColocar, solucao);
            while(retanguloPorColocar[j] != -1){
               recursiva()
            }
        }
    }
}


