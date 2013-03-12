#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(void)
{
  pid_t pid;
  int i, f, status, ini=0;
  int dados[100000];
  
  for(i=0; i < 6; i++)
  {
    pid = fork();
  
    if(pid<0)
    perror("bad fork\n");
    
    if(pid == 0)
    break;
    
    ini = ini + 5;
  }
  
  if(pid == 0)
  {
    for(f=ini; f < ini +5; f++)
      printf("| %d |",f);
  }
  sleep(5);
  return 0;
}