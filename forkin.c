#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int getrand(){
  int randata  = open("/dev/urandom", O_RDONLY );
  int rand;
  int buffboi = read(randata,&rand,sizeof(rand));
  close(randata);
  if(rand < 0){
    rand = getrand();
  }
  return rand;
}


int main(){
  int rand = getrand()%20;
  if(rand < 5){rand+=5;}
  int status = 0;

  printf("some initial message \n");
  int f = fork();
  if(f==-1) {
    printf("error\n");
  }
 if(f){
  if(f) {
   // waitpid(-1,&status,0);
    printf("Parent %i \n",getpid());

    printf("that the parent is done \n");
  }
  else {
    printf("pid child 1: %i \n", getpid());
    sleep(rand);
    printf("a message that it is finished\n");
  }
}
else{
    printf("pid child 2: %i \n",getpid());
sleep(rand);
printf("another message that is finished \n");
}

return 0;
}


/*
Forks off 2 child processes
Child process instructions:
At the start print its pid
Sleep for a random number of seconds in the range [5, 20]
Each child should sleep for a (potentially) different amount of seconds
At the end print a message that it is finished

Parent process instructions
Before forking, print out some initial message
After the fork, wait for any child to finish
Once a child has finished, print out the pid of the completed child as well as how many seconds it was asleep for.
Do not run any kind of timer, think about how the child could send this information back to the parent.
Print a message that the parent is done and then end the program
The other child might still be running, that's ok.
*/
