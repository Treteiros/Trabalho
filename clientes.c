#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include "clientes.h"

/*
 * 
 *
 *  Fator de balanceamento = Altura esq - Altura dir.
 *
 */


int altura(Clientes* cli) {
  if (cli == NULL)
    return 0;
  int alturaEsq = altura(cli->esq);  
  int alturaDir = altura(cli->dir);
  if (alturaEsq >= alturaDir) return alturaEsq +1;
  else return alturaDir+1;
}

Clientes* init(Clientes cli, char* cod) {
	if (cli == NULL) {
  cli = (Clientes*) malloc (sizeof(Clientes));
  cli->codigo = cod;
  cli->bal = altura(dir) - altura(esq);
  c->dir = NULL;
  c->esq = NULL;
}

/* VersÃ£o ineficiente! VocÃª sabe implementar outra? */
/* NÃ£o verifica se Ã© uma Ã¡rvore de busca. */
int verifica_AVL(Clientes* cli) {
  if (cli == NULL)
    return 1;
  return abs(altura(cli->dir) - altura(cli->esq)) <= 1;
}

void escreve(Clientes* cli) {
  if (cli != NULL) {
    escreve(cli->esq);
    printf("%d(%d)", cli->cod, cli->bal);
    escreve(cli->dir);
  }
}

void escreve_verifica(Clientes* cli) { 
  if (!verifica_AVL(cli)) 
    printf("NAO AVL!\n");
  escreve(cli); 
  printf("\n");
}

//rotações
void LL(No** r) {
  No* b = *r;
  No* a = b->esq;
  b->esq = a->dir;
  a->dir = b;
  a->bal = 0;
  b->bal = 0;
  *r = a;
}

void RR(No** r) {
  No* a = *r;
  No* b = a->dir;
  a->dir = b->esq;
  b->esq = a;
  a->bal = 0;
  b->bal = 0;
  *r = b;
}

void LR(No** r) {
  No *c = *r;
  No *a = c->esq;
  No *b = a->dir;
  c->esq = b->dir;
  a->dir = b->esq;
  b->esq = a;
  b->dir = c;
  switch(b->bal) {
  case -1:
    a->bal = 0;
    c->bal = 1;
    break;
  case 0:
    a->bal = 0;
    c->bal = 0;
    break;
  case +1:
    a->bal = -1;
    c->bal = 0;
    break;
  }
  b->bal = 0;
  *r = b;
}

void RL(No** r) {
  No *a = *r;
  No *c = a->dir;
  No *b = c->esq;
  c->esq = b->dir;
  a->dir = b->esq;
  b->esq = a;
  b->dir = c;
  switch(b->bal) {
  case -1:
    a->bal = 0;
    c->bal = 1;
    break;
  case 0:
    a->bal = 0;
    c->bal = 0;
    break;
  case +1:
    a->bal = -1;
    c->bal = 0;
    break;
  }
  b->bal = 0;
  *r = b;  
}


/* *cresceu indica se a Ã¡rvore cresceu 
   apÃ³s a inserÃ§Ã£o */
int aux_insere(No** t, int v, int *cresceu) {
  if (*t == NULL) {
    *t = cria(v, NULL, NULL);
    *cresceu = 1;
    return 1;
  }
    
  if (v == (*t)->v) 
    return 0;

  if (v < (*t)->v) {
    if (aux_insere(&(*t)->esq, v, cresceu)) {
      if (*cresceu) {
	switch ((*t)->bal) {
	case -1:
	  if ((*t)->esq->bal == -1)
	    LL(t);
	  else
	    LR(t);
	  *cresceu = 0;
	  break;
	case 0:
	  (*t)->bal = -1;
	  *cresceu = 1;
	  break;
	case +1:
	  (*t)->bal = 0;
	  *cresceu = 0;
	  break;
	}
      }
      return 1;
    }
    else
      return 0;
  }
  
  if (aux_insere(&(*t)->dir, v, cresceu)) {
      if (*cresceu) {
	switch ((*t)->bal) {
	case -1:
	  (*t)->bal = 0;
	  *cresceu = 0;
	  break;
	case 0:
	  (*t)->bal = +1;
	  *cresceu = 1;
	  break;
	case +1:
	  if ((*t)->dir->bal == +1)
	    RR(t);
	  else
	    RL(t);
	  *cresceu = 0;
	  break;
	}
      }
      return 1;
    }
    else
      return 0;

 
}

/* Retorna 1 se inseriu ou 0 se 
   o elemento áº½ repetido. */
int insere(No **t, int v) {
  int cresceu;
  return aux_insere(t, v, &cresceu);
}

int main() {
  No* t = cria(15,
	 cria(10, NULL, cria(12, NULL, NULL)), 
	 cria (20, cria(18, NULL, cria(19, NULL, NULL)),
	 cria(25, NULL, NULL))); 
  insere(&t, 11);
  escreve_verifica(t);
  return 0;
}
