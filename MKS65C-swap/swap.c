#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int Lemon[10];
  int Demon[10];

  Lemon[9] = 0;
  srand(time(0));


  for(int c = 0;c < 9;++c){
    Lemon[c] = rand();
  }
  printf("\nFirst Array \n");
  for(int c = 0;c < 10;++c){
    printf("%d \n",Lemon[c]);
  }

  for(int d = 0;d < 10;++d){
    *(Demon + d) = *(Lemon + (9-d));
  }
  printf("\nReverse Array \n");
  for(int d = 0;d < 10;++d){
    printf("%d \n",*(Demon + d));
  }
  return 0;
}
