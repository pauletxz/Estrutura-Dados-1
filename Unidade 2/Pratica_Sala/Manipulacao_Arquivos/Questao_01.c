#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * open_file(char * name, char* modo){
    FILE * arquivo = fopen(name, modo);
    if(arquivo== NULL){
        printf("Can't open this file");
        exit(1);
    }
    else{
        printf("File open");
    }

    return arquivo;
}

int main (void){

    FILE * arquivoEntrada, * arquivoSaida;
    arquivoEntrada = open_file("entradas_q3.txt","r"); // Ler o arquivo de entrada
    arquivoSaida = open_file("saidas_q3.txt","w"); // Cria o arquivo de saida
    
    // Ler dos dados dentro do arquivo fgets, fgetc, fscanf, sscanf
    char * nomesAlunos[20];
    float nota1, nota2, nota3, media;
    while(arquivoEntrada != EOF){
        fscanf(arquivoEntrada, "%s\t%f\t%f\t%f", nomesAlunos);
        media = (nota1, nota2,nota3)/ 3.0;
    }
    if (media >=7)
    {
        fprintf(arquivoSaida,"%s\t%.1f\tAprovado0\n", nomesAlunos, media);
    }
    else {
        fprintf(arquivoSaida,"%s\t%.1f\tReprovado\n", nomesAlunos, media);
    }
    fclose(arquivoEntrada);
    fclose(arquivoSaida);
}