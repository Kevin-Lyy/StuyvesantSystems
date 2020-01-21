#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void whileverboi(){
  while(666){
    printf("Pid %d\n",getpid());
    sleep(1);
  }
}

static void signalhandler(int put){

  if(put == SIGUSR1){
    printf("Parent pid %d\n",getppid());
  }

  if(put == SIGINT){
    int textboi = open("recieve.txt", O_WRONLY | O_APPEND);
    write(textboi, "Ended cause of SIGINT", strlen("Ended cause of SIGINT"));
    close(textboi);
    printf("Check file for end, SIGINT \n");
    exit(0);
  }

}

int main (){
  signal(SIGINT,signalhandler);
  signal(SIGUSR1,signalhandler);

  whileverboi();

  return 0;
}
