#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait-h>


void h(int sig)
  return;



int main(int argc, char **argv) {
 int n, i, j;
 n=atoi(argv[1]);

 pid_t pid[n];
 
 for (i=0;i<n;i++)
  pid[i]=fork();
  if (pid[i]==0)
   if(i%2==0)
    signal(SIGUSR1, h);
    printf("%d\n", getpid());
    pause();
    exit(0);
   else
    printf("%d\n", getpid());
    exit(0);


 for(j=0;j<n;j++)
  sleep(1);
  if(j%2==0)
   kill(pid[j], SIGUSR1);
  else
   waitpid(pid[j], NULL, 0);

