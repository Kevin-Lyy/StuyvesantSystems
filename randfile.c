#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int genrand(){
  int randmata = open("/dev/urandom", O_RDONLY );
  return randmata;
}


int main(void) {
  char* filename = "rand.txt";

  int file = open(filename, O_WRONLY);
  int * to_write = malloc();
  int writebytes = write(file,to_write,strlen(to_write));
  free(to_write);
  close(file);


  return 0;
}
