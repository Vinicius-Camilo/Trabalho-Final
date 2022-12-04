// 01- Você vai adicionar ao seu sistema para tratamento de imagens, unindo todas as funcionalidades em um único sistema.
// Seu sistema deve ter um menu com as seguintes opções adicionais:
// Colorir uma imagem artificialmente. Recebe uma imagem colorida original, converte para escala de cinza, e colore novamente com seis cores aleatórias. (6 pontos)
// Rotacionar uma imagem 90 graus para a direita. (6 pontos) 
// Rotacionar uma imagem 90 graus para a esquerda. (6 pontos)
// Gerar uma imagem cópia da original, porém com uma parte da imagem em escala de cinza (conforme listas 12.1, e 10b.1) (6 pontos).
// Gerar três arquivos de saída. Um para cada camada (R, G e B) (6 pontos).

// // Trabalho final - parte 2
// // Valor: 30 pontos
// // Em duplas
// // Data de entrega: 05/12/2022

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv){
    FILE *origem = fopen(argv[1], "r");
    //FILE *coloridoaleatorio = fopen(argv[3], "w");
    //FILE *origem = fopen("dinossaurinho.ppm", "r");
    //FILE *pretoebranco = fopen("qlqcoisa.ppm", "w");
    int i,j,k,col,lin,vmax,media,val1,val2,val3,num;
    char buffer [250];
    char buffer2[250];
    
    if (origem == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 0;
    }
    printf ("escolha um numero para cada tipo de tratamento de imagem:\n");
    printf ("1 - Colorir uma imagem artificialmente. Recebe uma imagem colorida original, converte para escala de cinza, e colore novamente com seis cores aleatórias.\n");
    printf ("2 - Rotacionar uma imagem 90 graus para a direita.\n");
    printf ("3 - Rotacionar uma imagem 90 graus para a esquerda.\n");
    printf ("4 - Gerar uma imagem copia da original, porem com uma parte da imagem em escala de cinza.\n");
    printf ("5 - Gerar tres arquivos de saida. Um para cada camada (R, G e B).\n");
    printf ("0 - Sair.\n");
    printf ("Digite o numero da opcao desejada: ");
    scanf ("%d", &num);
    
    fgets(buffer,250,origem);
    fgets(buffer,250,origem);
    fscanf(origem, "%d %d", &col,&lin);
    fscanf(origem, "%d", &vmax);
    int matriz[lin][col][3];
    

    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            for(k=0;k<3;k++){
                fscanf(origem, "%d", &matriz[i][j][k]);
            }
        }
    }

do
{
switch (num) {
    case 1:;
        // Colorir uma imagem artificialmente. Recebe uma imagem colorida original, converte para escala de cinza, e colore novamente com seis cores aleatórias. (6 pontos)
        FILE *pretoebranco = fopen("pretoebranco.ppm", "w");
        fprintf(pretoebranco, "P3\n");
        fprintf(pretoebranco, "# Criado por Roberto\n");
        fprintf(pretoebranco, "%d %d\n",col,lin);
        fprintf(pretoebranco, "%d\n",vmax);
        for(i=0;i<lin;i++){
            for(j=0;j<col;j++){
                media = (matriz[i][j][0]+matriz[i][j][1]+matriz[i][j][2])/3;
                fprintf(pretoebranco, "%d ", media);
                fprintf(pretoebranco, "%d ", media);
                fprintf(pretoebranco, "%d ", media);
            }
        }
        fclose(pretoebranco);

        pretoebranco = fopen("pretoebranco.ppm", "r");

        fgets(buffer,250,pretoebranco);
        fgets(buffer,250,pretoebranco);
        fscanf(pretoebranco, "%d %d", &col,&lin);
        fscanf(pretoebranco, "%d", &vmax);
        for(i=0;i<lin;i++){
            for(j=0;j<col;j++){
                for(k=0;k<3;k++){
                    fscanf(pretoebranco, "%d", &matriz[i][j][k]);
                }
            }
        }
        FILE *coloridoaleatorio = fopen("colorida_aleatoria.ppm", "w");
        fprintf(coloridoaleatorio, "P3\n");
        fprintf(coloridoaleatorio, "# Criado por Roberto\n");
        fprintf(coloridoaleatorio, "%d %d\n",col,lin);
        fprintf(coloridoaleatorio, "%d\n",vmax);
        
        for(i=0;i<lin;i++){//transforma de preto e branco para as cores especificas
            for(j=0;j<col;j++){
                if((matriz[i][j][0]>=0) && (matriz[i][j][0]<42)){
                    val1 = 121;
                    val2 = 232;
                    val3 = 9;
                    fprintf(coloridoaleatorio, "%d %d %d ", val1,val2,val3);
                }
                else if((matriz[i][j][0]>=42) && (matriz[i][j][0]<84)){
                    val1 = 28;
                    val2 = 49;
                    val3 = 237;
                    fprintf(coloridoaleatorio, "%d %d %d ", val1,val2,val3);
                }
                else if((matriz[i][j][0]>=84) && (matriz[i][j][0]<127)){
                    val1 = 204;
                    val2 = 12;
                    val3 = 178;
                    fprintf(coloridoaleatorio, "%d %d %d ", val1,val2,val3);
                }
                else if((matriz[i][j][0]>=127) && (matriz[i][j][0]<170)){
                    val1 = 242;
                    val2 = 227;
                    val3 = 10;
                    fprintf(coloridoaleatorio, "%d %d %d ", val1,val2,val3);
                }
                else if((matriz[i][j][0]>=170) && (matriz[i][j][0]<213)){
                    val1 = 1;
                    val2 = 97;
                    val3 = 102;
                    fprintf(coloridoaleatorio, "%d %d %d ", val1,val2,val3);
                }
                else if((matriz[i][j][0]>=213) && (matriz[i][j][0]<256)){
                    val1 = 102;
                    val2 = 2;
                    val3 = 0;
                    fprintf(coloridoaleatorio, "%d %d %d ", val1,val2,val3);
                }
            }
        }
        fclose(coloridoaleatorio);
        
        break;
    case 2:;
        // Rotacionar uma imagem 90 graus para a direita. (6 pontos) 
        FILE *rotacionar_direita = fopen("rotacionar_direita.ppm","w");
        fprintf(rotacionar_direita, "P3\n");
        fprintf(rotacionar_direita, "# Criado por Roberto\n");
        fprintf(rotacionar_direita, "%d %d\n",lin,col);
        fprintf(rotacionar_direita, "%d\n",vmax);
        for(j=0;j<col;j++){
            for(i=lin;i>0;i--){
                fprintf(rotacionar_direita, "%d ", matriz[i][j][0]);
                fprintf(rotacionar_direita, "%d ", matriz[i][j][1]);
                fprintf(rotacionar_direita, "%d ", matriz[i][j][2]);
            }
        }
        fclose(rotacionar_direita);

        break;
    case 3:;
        // Rotacionar uma imagem 90 graus para a esquerda. (6 pontos)
        FILE *rotacionar_esquerda = fopen("rotacionar_esquerda.ppm","w");
        fprintf(rotacionar_esquerda, "P3\n");
        fprintf(rotacionar_esquerda, "# Criado por Roberto\n");
        fprintf(rotacionar_esquerda, "%d %d\n",lin,col);
        fprintf(rotacionar_esquerda, "%d\n",vmax);
        for(j=lin;j>0;j--){
            for(i=0;i<col;i++){
                fprintf(rotacionar_esquerda, "%d ", matriz[i][j][0]);
                fprintf(rotacionar_esquerda, "%d ", matriz[i][j][1]);
                fprintf(rotacionar_esquerda, "%d ", matriz[i][j][2]);
            }
        }
        fclose(rotacionar_esquerda);

        break;
    case 4:;
        // Gerar uma imagem cópia da original, porém com uma parte da imagem em escala de cinza (conforme listas 12.1, e 10b.1) (6 pontos).
        fgets(buffer,250,origem);
        fgets(buffer,250,origem);
        fscanf(origem, "%d %d", &col,&lin);
        fscanf(origem, "%d", &vmax);

        for(i=0;i<lin;i++){
            for(j=0;j<col;j++){
                for(k=0;k<3;k++){
                    fscanf(origem, "%d", &matriz[i][j][k]);
                }
            }
        }
        int col2 = col/4;
        int lin2 = lin/4;
        int lin3 = 3*lin2;
        int col3 = 3*col2;
        int col4 = col;
        int lin4 = lin, count,soma;

        
        FILE *pretoebranco_meio = fopen("pretobranco_meio.ppm", "w");
        fprintf(pretoebranco_meio, "P3\n");
        fprintf(pretoebranco_meio, "# Criado por Roberto\n");
        fprintf(pretoebranco_meio, "%d %d\n",col,lin);
        fprintf(pretoebranco_meio, "%d\n",vmax);
        for(i=0;i<lin;i++){
            for(j=0;j<col;j++){
                for(k=0;k<3;k++){
                    if(i>=lin2 && i<=lin3 && j>=col2 && j<=col3){
                        media = (matriz[i][j][0]+matriz[i][j][1]+matriz[i][j][2])/3;
                        fprintf(pretoebranco_meio, "%d ", media);
                    }
                    else{
                        fprintf(pretoebranco_meio, "%d ", matriz[i][j][k]);
                    }
                }
            }
        }

        fclose(pretoebranco_meio);

        FILE *pretoebranco_meio2 = fopen("pretobranco_diagonal.ppm", "w");
        fprintf(pretoebranco_meio2, "P3\n");
        fprintf(pretoebranco_meio2, "# Criado por Roberto\n");
        fprintf(pretoebranco_meio2, "%d %d\n",col,lin);
        fprintf(pretoebranco_meio2, "%d\n",vmax);
        for(i=0;i<lin;i++){
            for(j=0;j<col;j++){
                for(k=0;k<3;k++){
                    if(j <= i){
                        media = (matriz[i][j][0]+matriz[i][j][1]+matriz[i][j][2])/3;
                        fprintf(pretoebranco_meio2, "%d ", media);
                    }
                    else{
                        fprintf(pretoebranco_meio2, "%d ", matriz[i][j][k]);
                    }
                }
            }
        }
        fclose(pretoebranco_meio2);

        break;
    case 5:;
        // Gerar três arquivos de saída. Um para cada camada (R, G e B) (6 pontos).
        FILE *r = fopen("r.ppm", "w");
        fprintf(r, "P3\n");
        fprintf(r, "# Criado por Roberto\n");
        fprintf(r, "%d %d\n",col,lin);
        fprintf(r, "%d\n",vmax);
        for(i=0;i<lin;i++){
            for(j=0;j<col;j++){
                for(k=0;k<3;k++){
                    if(k==0){
                        fprintf(r, "%d ", matriz[i][j][k]);
                    }
                    else{
                        fprintf(r, "%d ", 0);
                    }
                }
            }
        }

        fclose(r);

        FILE *g = fopen("g.ppm", "w");
        fprintf(g, "P3\n");
        fprintf(g, "# Criado por Roberto\n");
        fprintf(g, "%d %d\n",col,lin);
        fprintf(g, "%d\n",vmax);
        for(i=0;i<lin;i++){
            for(j=0;j<col;j++){
                for(k=0;k<3;k++){
                    if(k==1){
                        fprintf(g, "%d ", matriz[i][j][k]);
                    }
                    else{
                        fprintf(g, "%d ", 0);
                    }
                }
            }
        }

        fclose(g);

        FILE *b = fopen("b.ppm", "w");
        fprintf(b, "P3\n");
        fprintf(b, "# Criado por Roberto\n");
        fprintf(b, "%d %d\n",col,lin);
        fprintf(b, "%d\n",vmax);
        for(i=0;i<lin;i++){
            for(j=0;j<col;j++){
                for(k=0;k<3;k++){
                    if(k==2){
                        fprintf(b, "%d ", matriz[i][j][k]);
                    }
                    else{
                        fprintf(b, "%d ", 0);
                    }
                }
            }
        }

        fclose(b);
        break;

    default:;
        printf("Opcao invalida");
        break;

}
printf ("escolha um numero para cada tipo de tratamento de imagem:\n");
printf ("1 - Colorir uma imagem artificialmente. Recebe uma imagem colorida original, converte para escala de cinza, e colore novamente com seis cores aleatórias.\n");
printf ("2 - Rotacionar uma imagem 90 graus para a direita.\n");
printf ("3 - Rotacionar uma imagem 90 graus para a esquerda.\n");
printf ("4 - Gerar uma imagem copia da original, porem com uma parte da imagem em escala de cinza.\n");
printf ("5 - Gerar tres arquivos de saida. Um para cada camada (R, G e B).\n");
printf ("0 - Sair.\n");
printf ("Digite o numero da opcao desejada: ");
scanf ("%d", &num);
} while (num != 0);

return 0;
}

//Obrigado pela e pelo aprendizado!