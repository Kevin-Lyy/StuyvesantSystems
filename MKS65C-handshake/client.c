#include "pipe_networking.h"
#include <signal.h>


static void sighandler(int signo){
  if(signo == SIGINT){
    printf("client exit \n");
    exit(0);
  }
}

int main() {
  signal(SIGINT,sighandler);

  int to_server;
  int from_server;
  char toser[BUFFER_SIZE];

  from_server = client_handshake( &to_server );

  while(1){

    printf("prompt for user: ");
    if(fgets(toser,BUFFER_SIZE,stdin) == NULL){
      perror("fgets");
    }
    else{
      toser[strlen(toser)-1] = '\0';
    }
    printf("Send to server: %s \n",toser);

    write(to_server,toser,BUFFER_SIZE);
    read(from_server,toser,BUFFER_SIZE);

    printf("For you: %s \n",toser);
  }
  return 0;
}
