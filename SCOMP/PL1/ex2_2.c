#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main (void)
{
  pid_t p1,p2;
  int aux, status, filho=1;

  p1=fork();
    if(p1<0)
    {
      perror("erro fork!\n");
      exit(-1);
    }

  if(p1>0)
  {
    filho++;
    p2=fork();
    if(p2<0)
    {
      perror("erro fork!\n");
      exit(-1);
    }

    if(p2>0)
    {
      printf("Eu sou o pai!\n");
      
      do{
	   aux = waitpid(p1,&status,WNOHANG);
	   if(aux == -1)
	   {
	      perror("erro waitpid");
	      exit(-1);
	   }

	    if(WIFEXITED(status))
	      printf("filho pid %d, retornou %d\n",p1,WEXITSTATUS(status));
	 } while(aux == 0);
      do{
	  aux = waitpid(p2,&status,WNOHANG);
	  if(aux == -1)
	  {
	    perror("erro no waitpid");
	    exit(-1);
	  }
	  if(WIFEXITED(status))
	    	printf("filho pid %d, retornou %d\n",p2,WEXITSTATUS(status));
	  } while(aux==0);
      exit(0);
    }
  }

    printf("filho %d, pid=%d\n",filho,getpid());
    sleep(2);
    exit(filho);
}