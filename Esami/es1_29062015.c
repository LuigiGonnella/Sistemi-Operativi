int main() {
 int f1[2], n2;
 pipe(f1);
 if (!fork()) {
  int fd2[2], n1;
  pipe(fd2);
  if (!fork()) {
   int n;
   scanf("%d", &n);
   write(fd2[1], &n, sizeof(int));
   exit(0);
  }
  else {
    wait(NULL);
    read(fd2[0], &n1, sizeof(int));
    n1=n1-(2*n1);
    write(fd1[1], &n1, sizeof(int));
    exit(0);
  }
 }
 wait(NULL);
 read(fd1[0], &n2, sizeof(int));
 printf("%d", n2);
 exit(0);
}
    