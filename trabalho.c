#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
	FILE *in;
	int a,i=0;
    char ficheiro [100];
    char linha [100];
    char produtos[200000][100];
    int conta=0;
	printf("Introduza o ficheiro: ");
	scanf("%s",ficheiro);
	in = fopen(ficheiro, "r" );
      if( in == NULL )
       {
         printf("ERRO: não consigo abrir o ficheiro: %s\n",ficheiro);
         exit(1);
       }
  
    while(fgets(linha,100,in)){
    	produtos[][i]=linha;
    	printf("%s",produtos[i]);
    	conta++;
        i++;
    }
     
        
     printf("Ficheiro %s lido com sucesso, linhas: %d \n",ficheiro,conta);
     fclose( in );



}

