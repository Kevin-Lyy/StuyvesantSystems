#include "linkedlist.h"

int main(){
  struct node test1;
  struct node test2;
  struct node test3;

  struct node *linked = &test1;
  test1.next = &test2;
  test1.lemon = 1;
  test2.next = &test3;
  test2.lemon = 2;
  test3.next = NULL;
  test3.lemon = 3;
  printf("-----------------------------------------------------------\n");
  printf("Test print_list \n");
  print_list(linked);
  printf("-----------------------------------------------------------\n");
  printf("Test insert_front\n");
  struct node * newlinked;
  newlinked = insert_front(linked ,0);
  print_list(newlinked);
  printf("-----------------------------------------------------------\n");
  printf("Test free_list\n");
  print_list(linked);
  printf("\n");
  print_list(newlinked);
  printf("\n");
  linked = free_list(linked);
  print_list(linked);
  printf("-----------------------------------------------------------\n");

  return 0;
}
