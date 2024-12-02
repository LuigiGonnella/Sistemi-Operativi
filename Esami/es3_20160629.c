#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
 int fd1[2],i;
 
 pipe(fd)
 pid1=fork();
 if (pid1==0)
  char *str;
  str=(char*) malloc(10*sizeof(char));
  close(fd[0]);
  printf("inserisci stringa di 10 caratteri:");
  scanf("%s", str);
  write(fd1[1], str, 10*sizeof(char));
  exit(0);
  
  

 else
   int fd2[2];
   char str1[10];
   close(fd[]);
   read(fd[0], str1, 10*sizeof(char));
   pipe(fd2);
   pid2=fork();
   close(fd2[0]);
   for(i=9;i>=0;i--)
     write(fd2[1],str1[i], sizeof(char);
   if (pid2==0)
     int str2[10];
     close(fd2[1]);
     read(fd2[0], str2, 10*sizeof(char));
     fprintf("%s", str2);
     exit(0);
   
    
     
     
