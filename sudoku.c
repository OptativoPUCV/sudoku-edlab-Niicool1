#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <stdbool.h>


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          fscanf (file, "%d", &n->sudo[i][j]);
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}


List* get_adj_nodes(Node* n){
    List* list=createList();
    int i,j,p;
    for (i=0;i<9;i++){
      for (j=0;j<9;j++){
        if(n->sudo[i][j]== 0){
          for (p =1;p<=9;p++){
            Node * ad= (Node*)malloc (sizeof(Node));
            ad= copy(n);
            ad->sudo[i][j]=p;
            pushBack(list,ad);
          }
        }
      }
    }
    return list;
}

int is_valid(Node* n){
  List* list = get_adj_nodes(n);
  for (int i=0;i<9; i++){
    for(int j=0; j<9;j++){
      if (n->sudo[i][j]==0){
        Node *aux = first(list);
        while(next(list)!=NULL){
          for (int k=0;k<9;k++){
          if (n->sudo[i][j]==aux->sudo[k][j]) return 0; 
          if (n->sudo[i][j]==aux->sudo[i][k]) return 0;
        aux = next(list);
        }
        }
        
      }
    }
  }
    return 1;
}


int is_final(Node* n){
  int i,j;
  for (i=0;i<9;i++){
    for (j=0;j<9;j++){
      if (n->sudo[i][j]==0){
        return 0;
      }
      
    }
  }
    return 1;
}

Node* DFS(Node* n, int* cont){
 /* Stack *S = createStack();
  bool esVerdadero=true;
   push(S,n);

   while (first(S) != NULL && last(S) !=NULL){
      
      Node * n;
      n = top(S); 
      popFront(S);
      
      if (n.finalS == esVerdadero) return n;

      List * adj = get_adj_nodes(n);
    }*/
return NULL;
}



/*int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/

