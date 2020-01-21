#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "linkedlist.h"

int main(){
  struct node *test = NULL;

  printf("-----------------------------------------------------------\n");
  printf("Test insert_front\n");
  test = insert_front(test,1);
  print_list(test);
  printf("\n");
  test = insert_front(test,2);
  print_list(test);
  printf("\n");
  test = insert_front(test,3);
  print_list(test);
  printf("\n");

  printf("-----------------------------------------------------------\n");

  test = free_list(test);
  print_list(test);
  printf("freed list %p\n",test);

  printf("-----------------------------------------------------------\n");

  return 0;
}
