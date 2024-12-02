#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

void read_file(char *fname) {
 char str[100];
 FILE *fin=fopen(fname, "w");
 while(fscanf(fin, "%s", str)!=EOF) {
  if (!feof(fin))
   fprintf("%s\n", str);
 }
 close(fin);
}


int write_file(char *fname) {
 char str[100];
 fprintf("inserisci una stringa alla volta:\n");
 scanf("%s", str);
 while(strcmp(str,"end")!=0 && strcmp(str,"END")!=0) {
  fprintf(fin, "%s", str);
  scanf("%s", str);
 }

 if (strcmp(str,"end")==0)
   return 1;

 else 
   return 0;
}
   








int main(int argc, char **argv) {
 int fd[2], c=0, s, status, child_pid;

 signal(SIGUSR1, SIG_DFL);

 pipe(fd);
 write(fd[1], &c, sizeof(int));
 child_pid=fork();
 if(!child_pid) {
  int f=0, r;
  while(1) {
   read(fd[0], &f, sizeof(int)); //leggo e blocco l'altro processo
   read_file(argv[1]);
   r=write_file(argv[1]);
   if(r==0)
    kill(getppid(), SIGUSR1);
    close(fd[0]);
    close(fd[1]);
    exit(0);
   write(fd[1], &f, sizeof(int)); //scrivo e sblocco l'altro processo
   sleep(2); //evito due letture consecutive
  }
 else {
  while(1) {
   read(fd[0], &c, sizeof(int)); //leggo e blocco l'altro processo
   read_file(argv[1]);
   s=write_file(argv[1]);
   if(s==0)
    kill(child_pid, SIGUSR1);
    wait(&status);
    close(fd[0]);
    close(fd[1]);
    exit(0);
   write(fd[1], &c, sizeof(int)); //scrivo e sblocco l'altro processo
   sleep(2); //evito due letture consecutive
  }
 return 0;
}





  