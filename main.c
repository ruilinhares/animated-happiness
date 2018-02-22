#include <stdio.h>

int solucoes[1000][3][4];
int iteracao = 0;

int verificaSolucao(int colocados[3][4]){
    int pontoX0 = -1;
    int pontoY0 = -1;
    int i;
    for(i = 0; i < 3; i++){
        if(colocados[i][1] == 0 && colocados[i][2] > pontoX0)
            pontoX0 = colocados[i][0] + colocados[i][2];
        if(colocados[i][0] == 0 && colocados[i][3] > pontoY0)
            pontoY0 = colocados[i][1] + colocados[i][3];
    }
    printf("X = %d , Y = %d\n", pontoX0, pontoY0);
    for(i = 0; i < 3; i++){
        if(colocados[i][2] == pontoX0 && colocados[i][3] == pontoY0){
            for (int j = 0; j < 3; ++j) {
                printf("%d,%d,%d,%d\n",colocados[j][0],colocados[j][1],colocados[j][2],colocados[j][3]);
            }
            printf("---------------\n");
            return 1;
        }
    }
    return 0;
}



int recursiva(int retangulo[2], int pontos[4][2], int colocados[3][4], int restantes[3][2]){
    int i,j, k, verifica=0, contaSolucoes = 0;
    for(i = 0; i < 4; i++){
        if(pontos[i][0] != -1){
            printf("Ola, vou por o retangulo %d,%d em %d,%d\n",retangulo[0],retangulo[1],pontos[i][0],pontos[i][1]);
            int pontosBackupA[4][2];
            int colocadosBackupA[3][4];
            int restantesBackupA[3][2];
            int i1, i2;
            for(i1 = 0; i1 < 4; i1++){
                for(i2 = 0; i2 < 2; i2++){
                    pontosBackupA[i1][i2] = pontos[i1][i2];
                }
            }
            for(i1 = 0; i1 < 3; i1++){
                for(i2 = 0; i2 < 4; i2++){
                    colocadosBackupA[i1][i2] = colocados[i1][i2];
                }
            }
            for(i1 = 0; i1 < 3; i1++){
                for(i2 = 0; i2 < 2; i2++){
                    restantesBackupA[i1][i2] = restantes[i1][i2];
                }
            }
            for(j = 0; j < 3; j++){
                if(colocados[j][0] == -1){
                    colocados[j][0] = pontos[i][0];
                    colocados[j][1] = pontos[i][1];
                    colocados[j][2] = pontos[i][0] + retangulo[0];
                    colocados[j][3] = pontos[i][1] + retangulo[1];
                    int x = pontos[i][0];
                    int y = pontos[i][1];
                    pontos[i][0] = -1;
                    pontos[i][1] = -1;
                    int faltaColocar = 2;
                    int x1 = 0;
                    int x2 = 0;
                    int y1 = 0;
                    int y2 = 0;
                    for(k = 0; k < 4; k++){
                        if(faltaColocar != 0) {
                            if (pontos[k][0] == -1) {
                                if (faltaColocar == 2) {
                                    pontos[k][0] = colocados[j][2];
                                    x1 = colocados[j][2];
                                    pontos[k][1] = y;
                                    y1 = y;
                                }
                                if (faltaColocar == 1) {
                                    pontos[k][0] = x;
                                    x2 = x;
                                    pontos[k][1] = colocados[j][3];
                                    y2 = colocados[j][3];
                                }
                                faltaColocar--;
                            }
                        }
                        else{
                            printf("No processo criei os pontos %d,%d e %d,%d\n",x1,y1,x2,y2);
                            break;
                        }
                    }
                    break;
                }
            }
            int enviarRetangulo[2],auxTam; // retangulo escolhido para a recursividade
            verifica=0;
            for (i = 0; i<3;i++){ // fazer
                if (restantes[i][0]!=-1){ // retangulo escolhido
                    verifica = 1;
                    enviarRetangulo[0] = restantes[i][0];
                    enviarRetangulo[1] = restantes[i][1];
                    restantes[i][0]=-1; // -1 retirar o retangulo dos restantes
                    int pontosBackup[4][2];
                    int colocadosBackup[3][4];
                    int restantesBackup[3][2];
                    int i1, i2;
                    for(i1 = 0; i1 < 4; i1++){
                        for(i2 = 0; i2 < 2; i2++){
                            pontosBackup[i1][i2] = pontos[i1][i2];
                        }
                    }
                    for(i1 = 0; i1 < 3; i1++){
                        for(i2 = 0; i2 < 4; i2++){
                            colocadosBackup[i1][i2] = colocados[i1][i2];
                        }
                    }
                    for(i1 = 0; i1 < 3; i1++){
                        for(i2 = 0; i2 < 2; i2++){
                            restantesBackup[i1][i2] = restantes[i1][i2];
                        }
                    }

                    contaSolucoes += recursiva(enviarRetangulo, pontos, colocados, restantes); // chamada recursiva

                    for(i1 = 0; i1 < 4; i1++){
                        for(i2 = 0; i2 < 2; i2++){
                            pontos[i1][i2] = pontosBackup[i1][i2];
                        }
                    }
                    for(i1 = 0; i1 < 3; i1++){
                        for(i2 = 0; i2 < 4; i2++){
                            colocados[i1][i2] = colocadosBackup[i1][i2];
                        }
                    }
                    for(i1 = 0; i1 < 3; i1++){
                        for(i2 = 0; i2 < 2; i2++){
                            restantes[i1][i2] = restantesBackup[i1][i2];
                        }
                    }

                    if (enviarRetangulo[0]!=enviarRetangulo[1]){ // se não é quadrado
                        printf("E nao sou um quadrado!\n");
                        //TODO: FALTA RECALCULAR PONTOS E COLOCADOS AQUI
                        auxTam = enviarRetangulo[0];
                        enviarRetangulo[0] = enviarRetangulo[1];
                        enviarRetangulo[1] = auxTam;
                        contaSolucoes += recursiva(enviarRetangulo, pontos, colocados, restantes);
                        for(i1 = 0; i1 < 4; i1++){
                            for(i2 = 0; i2 < 2; i2++){
                                pontos[i1][i2] = pontosBackup[i1][i2];
                            }
                        }
                        for(i1 = 0; i1 < 3; i1++){
                            for(i2 = 0; i2 < 4; i2++){
                                colocados[i1][i2] = colocadosBackup[i1][i2];
                            }
                        }
                        for(i1 = 0; i1 < 3; i1++){
                            for(i2 = 0; i2 < 2; i2++){
                                restantes[i1][i2] = restantesBackup[i1][i2];
                            }
                        }
                    }
                }
            }
            if (verifica==0){ // verificar os colocados (possivel solucao)
                contaSolucoes += verificaSolucao(colocados);
                /*
                 * for (i=0; i<3;i++)
                    for (j=0;j<4;j++)
                        colocados[i][j]=-1;
                for (i=0; i<4;i++)
                    for (j=0;j<2;j++)
                        pontos[i][j]=-1;
                        */
            }
            for(i1 = 0; i1 < 4; i1++){
                for(i2 = 0; i2 < 2; i2++){
                    pontos[i1][i2] = pontosBackupA[i1][i2];
                }
            }
            for(i1 = 0; i1 < 3; i1++){
                for(i2 = 0; i2 < 4; i2++){
                    colocados[i1][i2] = colocadosBackupA[i1][i2];
                }
            }
            for(i1 = 0; i1 < 3; i1++){
                for(i2 = 0; i2 < 2; i2++){
                    restantes[i1][i2] = restantesBackupA[i1][i2];
                }
            }
        }
    }
    return contaSolucoes;

}

int main() {
    int i,j,k;
    int aux[2],aux2[2];
    int retangulos[3][2] = {{50,60},{60,50},{40,120}};
    int colocados[3][4];
    int pontosinteresse[4][2];

    for (i=0; i<3;i++)
        for (j=0;j<4;j++)
            colocados[i][j]=-1;
    for (i=0; i<4;i++)
        for (j=0;j<2;j++)
            pontosinteresse[i][j]=-1;
    for (i=0; i<1000;i++)
        for (j=0;j<3;j++)
            for (k=0;k<4;k++)
                solucoes[i][j][k] = -1;

    pontosinteresse[0][0]=0;
    pontosinteresse[0][1]=0;

    int pontosBackup[4][2];
    int colocadosBackup[3][4];
    int restantesBackup[3][2];
    int i1, i2;
    for(i1 = 0; i1 < 4; i1++){
        for(i2 = 0; i2 < 2; i2++){
            pontosBackup[i1][i2] = pontosinteresse[i1][i2];
        }
    }
    for(i1 = 0; i1 < 3; i1++){
        for(i2 = 0; i2 < 4; i2++){
            colocadosBackup[i1][i2] = colocados[i1][i2];
        }
    }

    int count = 0;
    for (i=0; i<3;i++) {
        aux[0]=retangulos[i][0];
        aux2[0]=retangulos[i][1];
        aux[1]=retangulos[i][1];
        aux2[1]=retangulos[i][0];
        retangulos[i][0]=-1;
        for(i1 = 0; i1 < 3; i1++){
            for(i2 = 0; i2 < 2; i2++){
                restantesBackup[i1][i2] = retangulos[i1][i2];
            }
        }
        count += recursiva(aux, pontosinteresse, colocados, retangulos);
        for(i1 = 0; i1 < 4; i1++){
            for(i2 = 0; i2 < 2; i2++){
                pontosinteresse[i1][i2] = pontosBackup[i1][i2];
            }
        }
        for(i1 = 0; i1 < 3; i1++){
            for(i2 = 0; i2 < 4; i2++){
                colocados[i1][i2] = colocadosBackup[i1][i2];
            }
        }
        for(i1 = 0; i1 < 3; i1++){
            for(i2 = 0; i2 < 2; i2++){
                retangulos[i1][i2] = restantesBackup[i1][i2];
            }
        }
        count += recursiva(aux2, pontosinteresse, colocados, retangulos);
        for(i1 = 0; i1 < 4; i1++){
            for(i2 = 0; i2 < 2; i2++){
                pontosinteresse[i1][i2] = pontosBackup[i1][i2];
            }
        }
        for(i1 = 0; i1 < 3; i1++){
            for(i2 = 0; i2 < 4; i2++){
                colocados[i1][i2] = colocadosBackup[i1][i2];
            }
        }
        for(i1 = 0; i1 < 3; i1++){
            for(i2 = 0; i2 < 2; i2++){
                retangulos[i1][i2] = restantesBackup[i1][i2];
            }
        }
        retangulos[i][0]=aux[0];

    }

    printf("%d\n", count);

    return 0;
}