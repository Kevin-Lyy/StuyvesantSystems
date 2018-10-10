#include <stdio.h>
#include <string.h>

struct node {int lemon; struct node *next; };


void print_list(struct node *demon){
  printf("My demon has %d many lemons\n", demon->lemon);

  int c = 0;
  while(demon){
    printf("My %d demon has: %d lemons\n",c,demon->lemon);
    demon = demon-> next;
    c++;
  }
}

struct node * insert_front(struct node * demon, int newlemon){
  struct node newnode;

  newnode.lemon = newlemon;

  newnode.next = demon;
  
  demon = &newnode;
  return demon;
}
  //newnode->lemon = newlemon;

struct node * free_list(struct node * next);

int main(){
  struct node test1;
  struct node test2;
  struct node test3;

  struct node *linked = &test1;
  test1.next = &test2;
  test1.lemon = 122;
  test2.next = &test3;
  test2.lemon = 14122;
  test3.next = NULL;
  test3.lemon = 121422;
  print_list(linked);
  printf("--------------------------------------------------\n");
  insert_front(linked ,12);
  print_list(linked);
  return 0;
}
