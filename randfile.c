#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


int getrand(){
  int randata  = open("/dev/urandom", O_RDONLY );

  return randata;
}


int main() {
  char* filename = "rand.txt";

  int * randarry = malloc(10 * sizeof(int));
  int c = 0;
  for(;c < 10; c++){
    randarry[c] = getrand();
  }

  for(c = 0;c < 10;c++){
    printf("%d : %d \n",c,randarry[c]);
  }

  int file = open(filename, O_WRONLY);
  int writebytes = write(file,randarry,10 * sizeof(int));
  printf("writing\n");
  close(file);

  file = open(filename,O_RDONLY);
  int * readbytes = malloc(10 * sizeof(int));
  read(file, readbytes, 10 * sizeof(int));
  printf("reading\n");
  close(file);


  for(c = 0;c<10;c++){
    printf("%d %d \n",c,readbytes[c]);
  }

  free(randarry);
  free(readbytes);
  return 0;
}
