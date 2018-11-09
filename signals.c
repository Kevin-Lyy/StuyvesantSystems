#include <stdio.h>
#include <stlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void checkerrno(){
  if(errno != 0){
    printf("error %d, %s\n",errno,strerror(errno));
    exit(0);
  }
}

void whileverboi(){
  while(666){
    printf("pid%d\n",getpid());
    sleep(1);
  }
}

static void intoreceive(int put){
  checkerrno();
  char * filename = "receive.txt";
  
  if(put == SIGINT){
    int textboi = open(filename, O_WRONLY | O_APPEND);
    write(textboi, “end cause SIGINT”,strlen(“end cause SIGINT”));
    close(textboi);
    printf(“check file for end, SIGINT”);
    exit(0);
  }

  if(put == SIGUAR1){
    printf(“parent pid %d\n”,getppid());

  }

}


int main (){
  signal(SIGINT,intoreceive);
  signal(SIGUSR1,intoreceive);

  whileverboi();

  return 0;
}
/*
Catch the following signals
SIGINT
Before exiting, append a message to a file noting that the program exited due to SIGINT
To make your program quit, look up the exit function.

SIGUSR1
Print out the PID of the parent process.
Should not cause the program to exit.
*/
