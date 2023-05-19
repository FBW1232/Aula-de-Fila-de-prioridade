 Fila de prioridade(Priority queue)
 TAD com operações
.push: insere
.pop: remove MAIOR inserido
 OBS: se tiver 2 iguais ele remove o primeiro dos maiores {34,61,12,61} -> {34,12,61}

 tem a fila de prioridade maxima que o pop remove o maior
 e a fila de prioridade minima que o pop remove o menor

 ex de maxima:
    - push 34  {34}
    - push 61  {34,61}
    - push 12  {34,61,12}

    - pop      {34,12}
    - pop      {12}
    - pop      {}

#include <stdio.h>
#include <stdlib.h>

#define MAX = 1024

typedef struct Fila{
  int v[MAX];
  int N;
}Fila;

void push(Fila *f, int x){
  f->N++;
  int i = f->N-2;
  while(i >= 0 && x < f->v[i]){
      f->v[i+1] = f->v[i];
      i--;
  }
  f->v[i+1] = x;
}

int pop(Fila *f){
  int x = f->v[f->N-1];
  f->N--;
  return x;
}

(max-) Heap: "Árvore" binária completa onde todo pai é maior que os filhos.

  esq[i] = 2i
  dir[i] = 2i+1
  pai(i) = i/2(divisão de inteiro)

Inserção:

  v[++N] = x;
  siftUp(N);

  siftUp(k)
   enquanto(k>1 && v[k]>v[pai(k)]):
     troca v[k] com v[pai(k)]
     k = pai(k)

Remoção:

  int x = v[1];
  v[1] = v[N--];
  siftDown(1);
  return x;

siftDown(k):

  enquanto k tem filhos e v[k] não é maior que ambos:
    l = maior que filho de k
    troca v[k] com v[l]
    k = l
