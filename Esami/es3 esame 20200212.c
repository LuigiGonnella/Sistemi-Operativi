#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#define r 5
#define c 5

struct args {
 int **mat_in;
 int ***mat_dest;
 int i;
 int j;
} args_t;

struct args1 {
 int ***mat_in;
 int ***mat_dest;
} args_t1;


void average(int i, int j, int** mat_in, int*** mat_dest) {
  
 if(i!=0 && i!=r-1 && j!=0 && j!=c-1)
	*mat_dest[i][j]=(mat_in[i-1][j]+mat_in[i-1][j-1]+mat_in[i-1][j+	1]+mat_in[i][j-1]+mat_in[i][j+1]+mat_in[i+1][j]+mat_in[i+1]	[j-1]+mat_in[i+1][j+1])/8;
 else if(i==0 && j!=0 && j!=c-1)
	*mat_dest[i][j]=(mat_in[i][j-1]+mat_in[i][j+1]+mat_in[i+1]	[j]+mat_in[i+1][j-1]+mat_in[i+1][j+1])/5;
 else if(i==r-1 && j!=0 && j!=c-1)
	*mat_dest[i][j]=(mat_in[i][j-1]+mat_in[i][j+1]+mat_in[i-1]	[j]+mat_in[i-1][j-1]+mat_in[i-1][j+1])/5;
 else if(j==0 && i!=0 && i!=r-1)
	*mat_dest[i][j]=(mat_in[i-1][j]+mat_in[i+1][j]+mat_in[i][j+	1]+mat_in[i-1][j+1]+mat_in[i+1][j+1])/5;
 else if(j==c-1 && i!=0 && i!=r-1)
	*mat_dest[i][j]=(mat_in[i][j-1]+mat_in[i+1][j]+mat_in[i-1]	[j]+mat_in[i-1][j-1]+mat_in[i+1][j-1])/5;
 else if(j==c-1 && i==0)
	*mat_dest[i][j]=(mat_in[i][j-1]+mat_in[i+1][j]+mat_in[i+1][j-1])/3;
 else if(j==c-1 && i==r-1)
	*mat_dest[i][j]=(mat_in[i][j-1]+mat_in[i-1][j]+mat_in[i-1][j-1])/3;
 else if(i==0 && j==0)
	*mat_dest[i][j]=(mat_in[i][j+1]+mat_in[i+1][j]+mat_in[i+1][j+1])/3;
 else if(i==0 && j==c-1)
	*mat_dest[i][j]=(mat_in[i][j+1]+mat_in[i-1][j]+mat_in[i-1][j+1])/3;
}
 
 
	


void *tf(void* par) {
 int i,j, avg;
 args_t *S;

 S=(args_t*) par;
 average(S->i, S->j, S->mat_in, S_mat_dest);
 pthread_exit();
}


 void *copy(void* par) {
  int i, j;
  args_t1 *S;
  S=(args_t1*) par;
  for(i=0;i<r;i++)
   for(j=0;j<c;j++)
    *(S->mat_in)[i][j]=*(S->mat_dest)[i][j];
  pthread_exit();
}
  











int main() {
 int **mat_in, i, j, n=0, k=0, **mat_dest;
 pthread_t tid[r*c+1];
 args_t A[r*c];
 args_t1 A1;
 void *status;

 ma_int=(int**)malloc(r*sizeof(int*));
 for(i=0;i<r;i++) {
  mat_in[i]=int(*)malloc(c*sizeof(int));
 }
 
 for(i=0;i<r;i++)
  for(j=0;j<c;j++)
    mat_in[i][j]=n++;

 mat_dest=(int**)malloc(r*sizeof(int*));
 for(i=0;i<r;i++) {
  mat_dest[i]=int(*)malloc(c*sizeof(int));
 }


 
for(i=0;i<r;i++)
 for(j=0;j<c;j++)
  A[k].mat_in=mat_in;
  A[k].i=i;
  A[k].j=j;
  A[k].mat_dest=&mat_dest;
  pthread_create(&tid[k], NULL, tf, (void*) &A[k]);
  k++;

for(i=0;i<r*c;i++)
 pthread_join(tid[i], &status);

A1.mat_in=&mat_in;
A1.mat_dest=&mat_dest;
pthread_create(&tid[r*c], NULL, copy, (void*) &A1); 

for(i=0;i<r;i++)
 for(j=0;j<c;j++)
  printf("%d ", mat_in[i][j]);
 printf("\n");

}



