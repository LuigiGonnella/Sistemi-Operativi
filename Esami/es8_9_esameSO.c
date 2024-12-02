#include <stdio.h>
#include <stlib.h>
#include <unistd.h>
#include <pthread.>
#include <string.h>
#define N 10

typdef struct {
 char str[15];
 int x;
 int fin;
} args_t;

void *tf((void*) par) {
  args_t *S;
  S=(args_t*) par;
  
  while(1) {
   if(S->fin==0) {
     sleep(S->x);
   }
   else {
     pthread_exit(NULL);
   }
  }
}


int main() {
 args_t S[N];
 pthread_t tid[N];
 int i;
 
 for (i=0;i<N;i++) {
  if(i==0) {
   S[i].x=((int)rand())%10+1;
   S[i].fin=1;
  }
  else {
    S[i].x=((int)rand())%10+1;
    S[i].fin=0;
  }
  pthread_create(&tid[i], NULL, tf, (void*) &S[i]);
 }
 
for (i=0; i<N; i++) {
 pthread_join(tid[i],NULL);
 S[i+1].fin=1;
}

return 0;

}



void *handler1(int signo) {
 if (signo==SIGUSR1) {
   return; 
 }
 else {
  printf("Error");
 }

}

void *handler2(int signo) {
 if (signo==SIGUSR2) {
   return; 
 }
 else {
  printf("Error");
 }

}


int main() {
 pid_t pid;
 signal(SIGUSR1, handler1);
 signal(SIGUSR2, handler2);
 signal(SIGKILL, SIG_DFL);

 pid=fork(); 
 if (pid>0) {
  while(1) {
   sleep(3);
   kill(pid, SIGUSR1);
   pause();
  }
 else {
  char c;
  scanf("%c", &c);
  if(c=='t' || c=='T') {
    kill(getppid(), SIGKILL);
    exit(0);
   }
  else {
   kill(getppid(), SIGUSR2);

  }

  }
 }

}















