#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <clientes.c>
#include <produtos.c>

int lerFich(char * nomeFicheiro){
	FILE *in;
	int a,i=0;
    char ficheiro [100];
    char linha [100];
    char produtos[200000][100];
	in = fopen(nomeFicheiro, "r" );
      if( in == NULL )
       {
         exit(1);
       }
    int conta=0;
    while(fgets(linha,100,in)){
    	conta++;
    }
     fclose( in );
}


