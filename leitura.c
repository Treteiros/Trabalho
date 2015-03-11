#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura.h"

int lerFich(char * nomeFicheiro){
	FILE *in;
	int i=0;
    char ficheiro [100];
    char linha [100];
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
     return conta;
}


