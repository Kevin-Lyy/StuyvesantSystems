#include "pipe_networking.h"


/*=========================
server_handshake
args: int * to_client

Performs the client side pipe 3 way handshake.
Sets *to_client to the file descriptor to the downstream pipe.

returns the file descriptor for the upstream pipe.
=========================*/
int server_handshake(int *to_client) {
  //remove("Mario");
  if(mkfifo("Mario",0666) == -1){
    printf("pipe error \n");
    exit(1);
  }
  else{
    printf("created Mario");
  }

  int readin = open("Mario",O_RDONLY);
  if(readin < 0){
    perror("pipe open error");
    return -1;
  }
  else{
    printf("connection");
  }

  char sendtoserver[HANDSHAKE_BUFFER_SIZE];
  read(readin,sendtoserver,sizeof(sendtoserver));
  printf("sending message to server: %s \n",sendtoserver);

  int f = fork();
  if(f == 0){
    printf("remove wkp\n");
    remove("Mario");
  }
  else{
    printf("write to client \n");
    *to_client = open(sendtoserver,O_WRONLY);

    if(*to_client != -1){
      printf("connected \n");
    }
    else{
      printf("not connected");
    }

    write(*to_client,ACK,sizeof(ACK));

    char fromclient[HANDSHAKE_BUFFER_SIZE];
    read(readin,fromclient,sizeof(fromclient));

    printf("Client response: %s \n",fromclient);
    printf("3 way handshake \n");

    return readin;
  }
  return 0;
}


/*=========================
client_handshake
args: int * to_server

Performs the client side pipe 3 way handshake.
Sets *to_server to the file descriptor for the upstream pipe.

returns the file descriptor for the downstream pipe.
=========================*/
int client_handshake(int *to_server) {
  remove("Luigi");
  if(mkfifo("Luigi",0644) == -1){
    printf("pipe error \n");
    exit(1);
  }
  else{
    printf("private pipe made \n");
  }

  *to_server = open("Mario",O_WRONLY);
  printf("connected \n");
  write(*to_server,"Luigi",sizeof("Mario"));


  int readin = open("Luigi",O_RDONLY);
  if(readin < 0){
    perror("pipe error");
    return -1;
  }
  char backtoserver[HANDSHAKE_BUFFER_SIZE];
  read(readin,backtoserver,sizeof(backtoserver));

  remove("Luigi");
  printf("server: %s",backtoserver);
  printf("I got it");
  write(*to_server,ACK,sizeof(ACK));


  printf("3 way handshake \n");

  return readin;
}
