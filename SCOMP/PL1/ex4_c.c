/* prdemo06.c */
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
  pid_t pid;
  int f;
					/*Altere o programa de modo a que apenas sejam gerados 3 filhos.*/
    for (f = 0; f < 2; f++)
    {
      pid = fork(); /* Cria um PROCESSO */
	if (pid > 0) /* Código do PAI */
	{
	    printf("Pai: Eu sou o PAI\n");
	}
	
	else /* Código do FILHO */
	{
		sleep(1);
	}
    }
 
return 0;
} /* fim main */