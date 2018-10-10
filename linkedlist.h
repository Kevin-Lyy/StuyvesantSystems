#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {int lemon; struct node *next; };


void print_list(struct node *demon){

  int c = 0;
  while(demon){
    printf("My %d demon has: %d lemons\n",c,demon->lemon);
    demon = demon-> next;
    c++;
  }
}

struct node * insert_front(struct node * demon, int newlemon){
  struct node newnode;
  struct node *newlinked = malloc(sizeof(newnode));

  newlinked -> lemon = newlemon;
  newlinked -> next = demon;

  return newlinked;
}

struct node * free_list(struct node * next);
