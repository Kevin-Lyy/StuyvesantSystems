
#include <stdio.h>

int main(){
  //1
  unsigned int Foreword = 2200000001;
  char *skel = &Foreword;
  //2
  printf("\nHex \n");
  printf("%x \n", Foreword);

  //3
  printf("\nBytes \n");
  for(int c = 0; c < sizeof(Foreword); ++c){
    printf("%d: %hhx \n",c, *(skel + c));
  }

  //4a
  printf("\nIncrements \n");
  for(int c = 0; c < sizeof(Foreword); ++c){
    ++*(skel + c);
  }
  printf("%x \n",Foreword);
  printf("%d \n", Foreword);
  
  //4b
  for(int c = 0; c < sizeof(Foreword); ++c){
    *(skel + c)+=16 ;
  }
  printf("%x \n",Foreword);
  printf("%d \n", Foreword);

}
