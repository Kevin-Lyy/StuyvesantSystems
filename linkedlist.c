#include <stdio.h>
struct node {int lemon; struct node *next; };


void print_list(struct node *demon){
  printf("My demons have %d many lemons\n", demon->lemon);

}



struct node * insert_front(struct node *, int);

struct node * free_list(struct node *);

int main(){
  struct node *test1;
  struct node *test2;
  struct node *test3;

  test1->lemon = 2;
  test1->next = test2;
  test2->lemon = 3;
  test2->next = test3;
  test3->lemon = 7;
  test3->next = NULL;

  print_list(test1);
  print_list(test2);
  print_list(test3);

}
