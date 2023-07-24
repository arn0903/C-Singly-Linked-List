#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
node structure
*/
typedef struct node
{
    char elem[5];
    struct node *next;
}t_node;

t_node *create();
t_node *InsertEnd(t_node *List, t_node *nouveau);

t_node *first(t_node *M);
t_node *last(t_node *M);

t_node *deleteHead(t_node *List);
t_node *Delete(t_node* l, char value[5], int *flag);

void print(t_node * List_print);
void freeList(t_node* List);

#endif // SLL_H_INCLUDED
