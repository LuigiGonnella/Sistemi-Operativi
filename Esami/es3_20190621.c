
void handler(int sig)
  int ans;
  if(sig==SIG_CHLD)
	printf("Vuoi terminare l'esecuzione(1) o continuarla(0)?\n");
	scanf("%d", &ans);
	if(ans==1)
		exit(-1);


  else
   printf("Error");


 return




int main
 signal(SIG_CHLD, handler);

 if(!fork())
  sleep(1);
  kill(getppid(), SIG_CHLD);
  sleep(5);
  kill(getppid(), SIG_CHLD);
  sleep(10);
  kill(getppid(), SIG_CHLD);
 else
  function();



