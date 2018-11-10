#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
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
  
  if(put == SIGUAR1){
    printf("parent pid %d\n",getppid());
  }

  if(put == SIGINT){
    int textboi = open(filename, O_WRONLY | O_APPEND);
    write(textboi, "end cause SIGINT",strlen("end cause SIGINT"));
    close(textboi);
    printf("check file for end, SIGINT");
    exit(0);
  }


}


int main (){
  signal(SIGINT,intoreceive);
  signal(SIGUSR1,intoreceive);

  whileverboi();

  return 0;
}
