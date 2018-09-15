#include <stdio.h>

int main(){

  unsigned int Foreword = 2200000001;
  char *skel = &Foreword;

  printf("%x \n", Foreword);
  for(int c = 0; c < sizeof(Foreword); ++c){
    printf("%d: %hhx \n",c, *(skel + c));
  }
  

}
