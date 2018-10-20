#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sieve(int nth){

  if(nth <5000){nth = 1.15 * nth * log(nth);}
  else{nth = 1.3 * nth * log(nth);}
  char * bigboi = calloc(sizeof(*bigboi),nth);

  //0 = prime
  //1 = not prime
  bigboi[0] = 1;
  bigboi[1] = 1;

  int c = 2;
  for(;c<nth;c++){
    if(bigboi[c] == 0){
      int c2 = c+c;
      for(;c2<nth;c2+c){
        bigboi[c2] = 1;
      }
    }
  }

  int count = 0;
  for(c = 0;c < nth;c++){
    if(bigboi[c] == 0){
      count++;
    }
  }
  return count;
}
