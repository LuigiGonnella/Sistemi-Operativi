ES1)

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>

#define N 10
#define M 25

int R[M];
sem_t sem[M];

int request() {
 int i, stat;
 
 while(1) {
 for(i=0;i<M;i++) {
  get_value(&sem[i], &stat);
  if(stat==1) {
   sem_wait(&sem[i]);
   return i;
  }
 }
 }
}

void release(int i) {
 sem_post(&sem[i]);
}


void *tf( (void*) par) {
 int id;
 id=request();
 release(id);
 pthread_exit(NULL);
 
}

int main() {
 pthread_t tid[N];
 int i;
 
 for(i=0;i<M;i++) {
  sem_init(&sem[i], 0, 1);
 }

 for(i=0;i<N;i++) {
  pthread_create(&tid[i], NULL, tf, NULL);
 }

 for(i=0;i<N;i++) {
  pthread_join(tid[i], NULL);
 }
}


ES2)

#!/bin/bash



if [$# -ne 1]; then
 echo "Error"
 exit -1
fi

if [!-d $1 ]; then
 echo "Error"
 exit -1
fi

for file in $(find $1 -name "*.txt"); do
 new=$(basename $file);
 cp $file "$new_SistemiOperativi.mod"
done


ES3)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define M

int main() {
 int fd[2];
 pid_t pid;
 
 pipe(fd);

 pid=fork();
 if(pid==0) {
  char *str;
  str=(char*) malloc(M*sizeof(char));
  close(fd[0]);
  write(fd[1], str, M*sizeof(char));
  exit(0);
 }

 else {
  char *str1;
  str1=(char*) malloc(M*sizeof(char));
  wait(NULL);
  close(fd[1]);
  read(fd[0], str1, M*sizeof(char));
 }

 return 0;

}

ES4)

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

n1=0;
n2=0;


void *h1(int signo) {
 if (signo==SIGUSR1) {
  n1++;
  n2=0;
  printf("Segnale ricevuto da P1");
 }

 return;

}

void *h2(int signo) {
 if (signo==SIGUSR2) {
  n2++;
  n1=0;
  printf("Segnale ricevuto da P2");
 }

 return;

}


int main() {
 int i;
 pid_t pid1=2, pid2=2;
 
 signal(SIGUSR1, h1);
 signal(SIGUSR2, h2);
 signal(SIGKILL, SIG_DFL);

 for(i=0;i<2;i++) {
  if (i==0) {
   pid1=fork();
  }
  else {
   pid2=fork();
  }
  
  if(pid1==0 || pid2==0) {
    if(i==0) { //F1
     while(1) {
       sleep(rand());
       kill(getppid(), SIGUSR1);
     }
     
    }
    else { //F2
     while(1) {
       sleep(rand());
       kill(getppid(), SIGUSR1);
     }
    }
  }
  

 }
 
 while(1) {
  pause();
  if (n1==3 || n2==3) {
   kill(pid1, SIGKILL);
   kill(pid2, SIGKILL);
   exit(0);
  }

 }


}



ES5)

sem_t A,B;
nA=0;

sem_init(&A,0, 1);
sem_init(&B,0, 1);

f() {
 
 A

 wait(A);
 nA++;
 if(nA==1) {
  wait(B);
 }
 signal(A);

 wait(A);
 nA--;
 if(nA==0) {
  signal(B);
 }
 signal(A);


 wait(B)
 B
 signal(B9;



}





