#include <stdio.h>

int p1(void) {
  int total = 0;
  for(int start = 0; start < 1000; start++){
    if (start % 3 == 0 || start % 5 == 0){
      total += start;
    }
  }
  return total;
}

int p5(void) {
  int i = 1;

while (i %  2 != 0 || i %  3 != 0 || i %  4 != 0 || i %  5 != 0 ||
         i %  6 != 0 || i %  7 != 0 || i %  8 != 0 || i %  9 != 0 ||
         i % 10 != 0 || i % 11 != 0 || i % 12 != 0 || i % 13 != 0 ||
         i % 14 != 0 || i % 15 != 0 || i % 16 != 0 || i % 17 != 0 ||
         i % 18 != 0 || i % 19 != 0 || i % 20 != 0 ){
    i++;
}
  return i;
}

int p6(void) {
  int Sq = 0;
  int Su = 0;

  for(int bleh = 1;bleh <= 100; bleh++){
    Su += bleh*bleh;
  }
  for(int bleh2 = 1;bleh2 <= 100; bleh2++){
    Sq += bleh2;
  }
  Sq *= Sq;
  int diff = Sq - Su;

  return diff;
}
int main() {
  printf("p1: %d \n", p1());
  printf("p5: %d \n", p5());
  printf("p6: %d", p6());
}
