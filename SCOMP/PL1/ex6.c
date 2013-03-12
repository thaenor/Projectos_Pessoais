#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

int main(void)
{
srand (time(NULL));
  pid_t pid;
  int i, f, status;
  int resultado[100000];
  int dados[100000];

  for(i=0; i < 100000; i++)
  {
	dados[i] = rand() % 100; //range 0 to 99
  }
 
 for(i=0; i < 10; i++)
  {
    printf("%d ",dados[i]);
  }
	printf("\n");
  pid = fork();
  
  if(pid == 0)
  {
    for(i=0; i < 50000; i++)
    {
      resultado[i]=dados[i]*4+20;
    }
    
    for(i=0; i < 5; i++)
    {
      printf("%d ",resultado[i]);
    }
  }
  
  printf("\n");
  
  
  if(pid > 0)
  {
    for(f = 50001; f < 100000; f++)
    {
      resultado[f]=dados[f]*4+20;
    }
    
    waitpid(pid,&status,0);
    
    for(f=50001; f < 50006; f++)
    {
      printf("%d ",resultado[f]);
    }
  }
  
  return 0;
}
