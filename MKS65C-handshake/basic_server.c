#include "pipe_networking.h"
#include <signal.h>

static void sighandler(int signo){
  if(signo == SIGINT){
    printf("Removing pipe \n");
    remove("Mario");
    printf("exit server \n");
    exit(0);
  }
}


int main() {
  signal(SIGINT,sighandler);

  int to_client;
  int from_client;
  char fromc[BUFFER_SIZE];


  while(1){
    from_client = server_handshake( &to_client );

    if(from_client){
      while(read(from_client,fromc,BUFFER_SIZE)){
        printf("getting from cient \n");
        printf("received: %s \n",fromc);

        int c = 0;
        for(;c<strlen(fromc);c++){
          fromc[c]++;
        }

        if(write(to_client,fromc,BUFFER_SIZE) == -1){
          perror("write error");
        }
        else{
          printf("send back: %s \n",fromc);
        }

      }
      printf("handshake complete \n");
    }
  }

}
