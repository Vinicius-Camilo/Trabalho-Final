// Trabalho final - parte 1
// Valor: 30 pontos
// Em duplas
// Data de entrega: 05/12/2022
// 01 - Você vai criar um sistema completo para tratamento de imagens, unindo todas as funcionalidades em um único sistema.
// Seu sistema deve ter um menu com as seguintes opções:
// Converter uma imagem colorida para escala de cinza. 
// Espelhar uma imagem horizontalmente
// Espelhar uma imagem verticalmente. 
// Dividir uma imagem em dois arquivos (um arquivo com a metade esquerda, e outro arquivo com a metade direita). 
// Dividir uma imagem em dois arquivos (um arquivo com a metade superior, e outro arquivo com a metade inferior). 

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
    printf ("1 - Converter uma imagem colorida para escala de cinza.\n");
    printf ("2 - Espelhar uma imagem horizontalmente.\n");
    printf ("3 - Espelhar uma imagem verticalmente.\n");
    printf ("4 - Dividir uma imagem em dois arquivos (um arquivo com a metade esquerda, e outro arquivo com a metade direita). \n");
    printf ("5 - Dividir uma imagem em dois arquivos (um arquivo com a metade superior, e outro arquivo com a metade inferior).\n");
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

do {

    switch (num)
    {
    case 1:;
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
        
        break;
    
    case 2:;
        FILE *espelhamento_horizontal = fopen("espelhamento_horizontal.ppm", "w");
        fprintf(espelhamento_horizontal, "P3\n");
        fprintf(espelhamento_horizontal, "# Criado por Roberto\n");
        fprintf(espelhamento_horizontal, "%d %d\n",col,lin);
        fprintf(espelhamento_horizontal, "%d\n",vmax);
        for(i=0;i<lin;i++){
            for(j=col;j>0;j--){
                for(k=0;k<3;k++){
                    media = matriz[i][j][k];
                    fprintf(espelhamento_horizontal, "%d ", media);              
                }
                
            }
        }
        fclose(espelhamento_horizontal);

        break;

    case 3:;
        FILE *espelhamento_vertical = fopen("espelhamento_vertical.ppm", "w");
        fprintf(espelhamento_vertical, "P3\n");
        fprintf(espelhamento_vertical, "# Criado por Roberto\n");
        fprintf(espelhamento_vertical, "%d %d\n",col,lin);
        fprintf(espelhamento_vertical, "%d\n",vmax);
        for(i=lin;i>0;i--){
            for(j=0;j<col;j++){
                for(k=0;k<3;k++){
                    media = matriz[i][j][k];
                    fprintf(espelhamento_vertical, "%d ", media);              
                }
                
            }
        }
        fclose(espelhamento_vertical);

        break;

    case 4:;
        FILE *metade_esquerda = fopen("metade_esquerda.ppm", "w");
        fprintf(metade_esquerda, "P3\n");
        fprintf(metade_esquerda, "# Criado por Roberto\n");
        fprintf(metade_esquerda, "%d %d\n",col/2,lin);
        fprintf(metade_esquerda, "%d\n",vmax);
        for(i=0;i<lin;i++){
            for(j=0;j<col/2;j++){
                for(k=0;k<3;k++){
                    media = matriz[i][j][k];
                    fprintf(metade_esquerda, "%d ", media);              
                }
                
            }
        }
        fclose(metade_esquerda);

        FILE *metade_direita = fopen("metade_direita.ppm", "w");
        fprintf(metade_direita, "P3\n");
        fprintf(metade_direita, "# Criado por Roberto\n");
        fprintf(metade_direita, "%d %d\n",col/2,lin);
        fprintf(metade_direita, "%d\n",vmax);
        for(i=0;i<lin;i++){
            for(j=col/2;j<col;j++){
                for(k=0;k<3;k++){
                    media = matriz[i][j][k];
                    fprintf(metade_direita, "%d ", media);              
                }
                
            }
        }
        fclose(metade_direita);

        break;

    case 5:;
        FILE *metade_superior = fopen("metade_superior.ppm", "w");
        fprintf(metade_superior, "P3\n");
        fprintf(metade_superior, "# Criado por Roberto\n");
        fprintf(metade_superior, "%d %d\n",col,lin/2);  
        fprintf(metade_superior, "%d\n",vmax);
        for(i=0;i<lin/2;i++){
            for(j=0;j<col;j++){
                for(k=0;k<3;k++){
                    media = matriz[i][j][k];
                    fprintf(metade_superior, "%d ", media);              
                }
                
            }
        }
        fclose(metade_superior);

        FILE *metade_inferior = fopen("metade_inferior.ppm", "w");
        fprintf(metade_inferior, "P3\n");
        fprintf(metade_inferior, "# Criado por Roberto\n");
        fprintf(metade_inferior, "%d %d\n",col,lin/2);
        fprintf(metade_inferior, "%d\n",vmax);
        for(i=lin/2;i<lin;i++){
            for(j=0;j<col;j++){
                for(k=0;k<3;k++){
                    media = matriz[i][j][k];
                    fprintf(metade_inferior, "%d ", media);              
                }
                
            }
        }
        fclose(metade_inferior);


        break;

    default:;
        printf("Opção inválida\n");
        break;
    }

    printf ("escolha um numero para cada tipo de tratamento de imagem:\n");
    printf ("1 - Converter uma imagem colorida para escala de cinza.\n");
    printf ("2 - Espelhar uma imagem horizontalmente.\n");
    printf ("3 - Espelhar uma imagem verticalmente.\n");
    printf ("4 - Dividir uma imagem em dois arquivos (um arquivo com a metade esquerda, e outro arquivo com a metade direita). \n");
    printf ("5 - Dividir uma imagem em dois arquivos (um arquivo com a metade superior, e outro arquivo com a metade inferior).\n");
    printf ("0 - Sair.\n");
    printf ("Digite o numero da opcao desejada: ");
    scanf ("%d", &num);
}while (num !=0);

    fclose(origem);
    return 0;
}

//Obrigado pela e pelo aprendizado!