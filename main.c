#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura.c"

int main(){
    char nome [100];
    printf("Introduza o ficheiro a ler: ");
    scanf("%s",nome);
    printf("Conta: %d",lerFich(nome));
}

