/* prdemo06.c */
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
  pid_t pid;
  int f, status;
					/* Altere o programa de modo a que todas as possíveis situações de erro sejam tratadas.*/
    for (f = 0; f < 2; f++)
    {
      pid = fork(); /* Cria um PROCESSO */
	if(pid<0)
	  {  perror("BAD FORK"); exit(-1);}

	if (pid > 0) /* Código do PAI */
	{
	    printf("Pai: Eu sou o PAI\n");
/****************************************************************************************************/	
	aux = waitpid(pid,&status,WNOHANG);
	   if(aux == -1)
	   {
	      perror("erro waitpid");
	      exit(-1);
	   }

	    if(WIFEXITED(status))
	      printf("filho pid %d, retornou %d\n",p1,WEXITSTATUS(status));
	    else
	      printf("não terminou normalmente");
/****************************************************************************************************/	
	}
	
	else /* Código do FILHO */
	{
		sleep(1);
	}
    }
 
return 0;
} /* fim main */