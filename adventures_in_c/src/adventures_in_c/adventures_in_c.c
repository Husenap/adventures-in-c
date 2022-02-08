#include <stdio.h>
#include <stdlib.h>

struct node{
  int value;
};

typedef struct node node_t;

int main(){
  printf("Hello C!\n");

  node_t* n = malloc(sizeof(node_t));
  n->value = 42;

  printf("n = %d\n", n->value);

  free(n);

  return 0;
}