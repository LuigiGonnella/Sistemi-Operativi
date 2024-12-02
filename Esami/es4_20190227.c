#include <stdio.h>
#include <unistd.>
#include <stdlib.h>
#include <pthread.h>

#define F0 1
#define F1 1

typedef struct args_t {
  int F_1;
  int F_2;
  int res;
} arg_t;



void *tf0((void*) par) {
 arg_t *S;
 
 S=(arg_t*) par;
 S->res=1;
}


void *tf((void*) par) {
 arg_t *S;
 
 S=(arg_t*) par;
 S->res=S->F_1+S->F_2;
 printf("%d ", S->res);
}



int main(int argc, char **argv) {
 int n=atoi(argv[1]), i;
 pthread_t tid[n];
 arg_t S[n];
 void *status;

 
 pthread_create(&tid[0], NULL, tf0, (void*) &S[0]);
 pthread_create(&tid[1], NULL, tf0, (void*) &S[1]);

 for(i=0;i<2;i++) {
  pthread_join(tid[i], &status);
 }

 for(i=2;i<n;i++) {
  S[i].F_1=S[i-1].res;
  S[i].F_2=S[i-2].res;
  pthread_create(&tid[i], NULL, tf, (void*) &S[i]);
  pthread_join(tid[i], &status);
  }
 
 return 0;
}

 
 