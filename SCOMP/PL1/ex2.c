#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
int estado; //valor do exit do filho
int aux;
pid_t child, child2;

child = fork();
	
	if(child < 0){
		perror("BAD FORK!\n");
		exit(-1);}

	if(child > 0) //processado apenas pelo pai. Onde "child" tem o pid do processo filho
	{
		
			
			child2 = fork();
				if(child2 < 0){
			perror("SECOND BAD FORK!\n");
			exit(-1);}
	
	}

	if(child > 0 && child2 > 0) //executado pelo pai
	{
		aux = waitpid(child, &estado, 0); //o zero faz com que o pai espere
		if(aux > 0) {
			printf("%d",WEXITSTATUS(estado));
		}

		aux = waitpid(child2, &estado, 0);
		if(aux > 0) {
			printf("%d\n",WEXITSTATUS(estado));
		}
	
		printf("EU SOU PAI! \n");	
	}

	if(child == 0 )
	{
		printf("I AM THE FIRST CHILD\n");
	}
			
	if(child2 == 0 && child != 0)
	{
		printf("I AM THE SECOND CHILD\n");
	}

return 0;
}
