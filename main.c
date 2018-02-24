#include <stdio.h>

int solucoes[1000][3][4];

int verificaSolucao(int colocados[3][4]){
    int pontoX0 = -1;
    int pontoY0 = -1;
    int area = 0;
    int i,j;
    for(i = 0; i < 3; i++){
        area += (colocados[i][2] - colocados[i][0])*(colocados[i][3] - colocados[i][1]);
        if(colocados[i][1] == 0 && colocados[i][2] > pontoX0)
            pontoX0 = colocados[i][2];
        if(colocados[i][0] == 0 && colocados[i][3] > pontoY0)
            pontoY0 = colocados[i][3];
    }
    for(i = 0; i < 3; i++){
        if(colocados[i][2] == pontoX0 && colocados[i][3] == pontoY0 && area == colocados[i][2]*colocados[i][3]){
            /*printf("* %d,%d,%d,%d | X%d Y%d\n",colocados[i][0],colocados[i][1],colocados[i][2],colocados[i][3],pontoX0,pontoY0);
            for (j = 0; j < 3; j++)
                printf("%d,%d,%d,%d\n",colocados[j][0],colocados[j][1],colocados[j][2],colocados[j][3]);

            printf("---------------\n");*/
            printf("\t*solucao*\n");
            return 1;
        }
    }
    printf("\t*not*\n");

    return 0;
}



int recursiva(int retanguloX, int retanguloY, int pontos[4][2], int colocados[3][4], int restantes[3][2]){
    int i,j, k, k1,k2,x,y, verifica=0, contaSolucoes = 0;
    int auxX, auxY; // retangulo escolhido para a recursividade

    for(i = 0; i < 4; i++){
        if(pontos[i][0] != -1){
            printf("------------------\n");
            printf("**%d,%d||%d,%d**\n",pontos[i][0],pontos[i][1],retanguloX,retanguloY);
            for(j = 0; j < 3; j++){
                printf("%d,%d,%d,%d\n",colocados[j][0],colocados[j][1],colocados[j][2],colocados[j][3]);
                if(colocados[j][0] == -1){
                    colocados[j][0] = pontos[i][0];
                    colocados[j][1] = pontos[i][1];
                    colocados[j][2] = pontos[i][0] + retanguloX;
                    colocados[j][3] = pontos[i][1] + retanguloY;
                    //printf("++%d,%d,%d,%d\n",colocados[j][0],colocados[j][1],colocados[j][2],colocados[j][3]);

                    x = pontos[i][0];
                    y = pontos[i][1];
                    pontos[i][0] = -1;
                    pontos[i][1] = -1;
                    k1 = -1;
                    k2 = -1;
                    int faltaColocar = 2;
                    for(k = 0; k < 4; k++){
                        if(faltaColocar != 0) {
                            if (pontos[k][0] == -1) {
                                if (faltaColocar == 2) {
                                    k1=k;
                                    pontos[k][0] = colocados[j][2];
                                    pontos[k][1] = y;
                                }
                                if (faltaColocar == 1) {
                                    k2=k;
                                    pontos[k][0] = x;
                                    pontos[k][1] = colocados[j][3];
                                }
                                faltaColocar--;
                            }
                        }
                        else{
                            break;
                        }
                    }
                    verifica = 0;
                    for (i = 0; i<3;i++){ // fazer
                        if (restantes[i][0]!=-1){ // retangulo escolhido
                            verifica = 1;
                            auxX = restantes[i][0];
                            auxY = restantes[i][1];
                            restantes[i][0]=-1; // -1 retirar o retangulo dos restantes

                            contaSolucoes += recursiva(auxX, auxY, pontos, colocados,restantes); // chamada recursiva

                            if (auxX!=auxY){ // se não é quadrado
                                contaSolucoes += recursiva(auxY, auxX, pontos, colocados,restantes);
                            }
                            restantes[i][0]=auxX; // -1 retirar o retangulo dos restantes

                        }
                    }

                    if (verifica==0){ // verificar os colocados (possivel solucao)
                        contaSolucoes += verificaSolucao(colocados);
                    }

                    pontos[i][0]= x;
                    pontos[i][1]= y;
                    if (k1!=-1) {
                        pontos[k1][0] = -1;
                        pontos[k1][1] = -1;
                    }
                    if (k2!=-1) {
                        pontos[k2][0] = -1;
                        pontos[k2][1] = -1;
                    }
                    colocados[j][0] = -1;
                    colocados[j][1] = -1;
                    colocados[j][2] = -1;
                    colocados[j][3] = -1;
                    break;
                }
            }
        }
    }
    return contaSolucoes;

}

int main() {
    int i,j,k;
    int auxX,auxY;
    int retangulos[3][2] = {{50,60},{60,50},{40,120}};
    int colocados[3][4];
    int pontosinteresse[4][2];

    for (i=0; i<3;i++)
        for (j=0;j<4;j++)
            colocados[i][j]=-1;
    for (i=0; i<4;i++)
        for (j=0;j<2;j++)
            pontosinteresse[i][j]=-1;
    /*for (i=0; i<1000;i++)
        for (j=0;j<3;j++)
            for (k=0;k<4;k++)
                solucoes[i][j][k] = -1*/

    pontosinteresse[0][0]=0;
    pontosinteresse[0][1]=0;


    int count = 0;
    for (i=0; i<3;i++) {
        auxX=retangulos[i][0];
        auxY=retangulos[i][1];
        retangulos[i][0]=-1;
        count += recursiva(auxX, auxY, pontosinteresse, colocados, retangulos);
        count += recursiva(auxY, auxX, pontosinteresse, colocados, retangulos);
        retangulos[i][0]=auxX;
    }

    printf("%d\n", count);

    return 0;
}