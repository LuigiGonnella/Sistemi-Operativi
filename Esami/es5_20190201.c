#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define x 5
#define r 4
#define c 4

typedef struct args_t {
 int **A;
 int **B;
 int ***C;
 int rA;
 int cB;
} arg_t;



void stampa_mat(int **C, int r, int c) {
 int i,j;
 for(i=0;i<r;i++)
  for(j=0,J<c;j++)
   printf("%d ", C[i][j]);
  printf("\n");
}



void *tf(void* par) {
 int i, j, tot=0;
 arg_t *ST;

 ST=(arg_t*) par;
 
 for(i=0;i<x;i++)
   tot+=ST->A[ST->rA][i]*ST->B[i][ST->cB];

 (*(ST->C))[ST->rA][ST->cB]=tot;

}
 





void mat_mul(int **A, int **B, int r, int x, int c, int **C) {
 int i,j,k=0;
 pthread_t tid[r*c];
 arg_t S[r*c];
 void *status;

 for(i=0;i<r;i++)
  for(j=0;j<c;j++)
   S[k].A=A;
   S[k].B=B;
   S[k].C=&C;
   S[k].rA=i;
   S[k].cB=j;
   pthread_create(&tid[k], NULL, tf, (void*) &S[k++]);


 for(i=0;i<r*c;i++)
  pthread_join(tid[i],&status);


 stampa_mat(C,r,c);

}






int main() {
 int **C, **A, **B,i,j,k=0;
 
 C=(int**)malloc(r*sizeof(int*));
 for(i=0;i<r;i++){
  C[i]=(int)malloc(c*sizeof(int));
 }

 A=(int**)malloc(r*sizeof(int*));
 for(i=0;i<r;i++){
  A[i]=(int)malloc(x*sizeof(int));
 }

 for(i=0;i<r;i++)
  for(j=0;j<x;j++)
   A[i][j]=k++;

 k=0;

 B=(int**)malloc(x*sizeof(int*));
 for(i=0;i<r;i++){
  B[i]=(int)malloc(c*sizeof(int));
 }

 for(i=0;i<x;i++)
  for(j=0;j<c;j++)
   B[i][j]=k++;

 mat_mul(A,B,r,x,c,C);
 return 0;
}