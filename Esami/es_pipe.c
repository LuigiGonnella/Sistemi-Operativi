#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
 int fd1[2], fd2[2], fd3[2];
 pid_t pid1;

 pipe(fd1); //P1-P2
 pipe(fd2); //P2-P3
 pipe(fd3); //P3-P1

 pid=fork();
 if(pid==0) {
  char n1;
  read(fd1[0], &n1, sizeof(int));
  close(fd1[0]);
  sleep(n1);
  scanf("%d", &n1, sizeof(int));
  write(fd2[1], &n1, sizeof(int));
  close(fd2[1]);
 }

 else {
  
   pid=fork();
   if(pid==0) {
    char n2;
    read(fd3[0], &n2, sizeof(int));
    close(fd3[0]);
    sleep(n2);
    scanf("%d", &n2, sizeof(int));
    write(fd3[1], &n2, sizeof(int));
    close(fd3[1]);


   }
   
   else {
      int n;
      read(fd3[1], &n, sizeof(int));
      close(f3[1]);
      sleep(n);
      scanf("%d", &n);
      write(fd1[1], &n, sizeof(int));
      close(fd[1]);
   }


 } 
 

return 0;
}