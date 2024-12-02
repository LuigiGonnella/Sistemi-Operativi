#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>



void parent(int r, int fd[2])
 int n;
 char a='F', b='X', str[20];
 if(r==1)
  scanf("%d, %s", &n, str);
  write(fd[1], a, sizeof(char));
  write(fd[1], n, sizeof(int));
  write(fd[1], str, 20*sizeof(char));
  return;
 else if(r==2)
  write(fd[1], b, sizeof(char));
  return;
 else if(r==3)
  exit(0);


void child(int fd[2], int *nf)
 char c, str[20];
 int n, i, status;
 read(fd[0], c, sizeof(char));
 if(c=='F')
  read(fd[0], n, sizeof(int));
  read(fd[0], str, 20*sizeof(char));
  if(!fork())
   (*nf)++;
   for(i=0;i<n;i++)
    sleep(1);
    printf("%s", str);
   exit(n);
  return;
 else if(c=='X')
  for(i=0;i<*nf;i++)
   wait(&status);
   printf("%d\n", WEXITSTATUS(status));
  exit(0);
  
  




int main()
 int r, fd[2], nf=0;
 pipe(fd);
 while(1)
  r=(rand()%3)+1;
  if(fork())
   parent(r,fd);
  else
   while(1)
    child(fd, &nf);