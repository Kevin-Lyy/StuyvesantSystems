#include <stdio.h>
#include "sieve.h"

int sieve(int nth){
  if(nth<0)return 0;
  if(nth == 1)return 2;

  int nth2;
  if(nth <5000){nth2 = 1.15 * nth * log(nth)+20;}
  else{nth2 = 1.3 * nth * log(nth)+10;}

  char * bigboi = calloc(sizeof(bigboi),nth2);

  //0 = prime
  //1 = not prime
  bigboi[0] = 1;
  bigboi[1] = 1;

  int c = 2;
  for(;c<=nth2;c++){
    if(bigboi[c] == 0){
      int c2 = c+c;
      for(;c2<=nth2;c2+=c){
        bigboi[c2]=1;
      }
    }
  }
/*
  c = 0;
  for(;c <= nth2;c++){
    printf("%d : %d\n",c,bigboi[c]);
  }
  printf("stop\n");
*/
  int count = 0;
  for(c = 1;c <= nth2;c++){
    if(bigboi[c]==0){
      count++;
      if(count == nth){
        return c;
      }
    }
  }
}


int main(){

  printf("test 40\n");
  printf("%d\n",sieve(40));
  printf("test 100\n");
  printf("%d\n",sieve(100));
  printf("test 200\n");
  printf("%d\n",sieve(200));
  printf("test 5001\n");
  printf("%d\n",sieve(5001));
  printf("test 20000\n");
  printf("%d\n",sieve(20000));


  return 0;
}
