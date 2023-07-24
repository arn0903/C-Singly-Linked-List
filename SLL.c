#include "SLL.h"


/*
function to create a node
*/
t_node *create()
{
    t_node *head;

    head = (t_node*)malloc(sizeof(t_node)); //memory allocation
    if (head == NULL)
    {
        printf("memory access problem\n");
        return NULL;
    }

    else
    {
        printf("Select a node value\n");
        fflush(stdin);
        gets(head->elem);

        head->next = NULL;
        return head;
    }

}

/*
function to insert a node at the end
*/
t_node *InsertEnd(t_node *List, t_node *nouveau)
{
    t_node *current;
    if (List == NULL)
        return nouveau;

    else
    {
        //if list isn't empty
        current = List;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = nouveau;
        return List;
    }
}


/*
function that returns the head of the list
*/
t_node *first(t_node *M)
{
    return M;
}

/*
recursive function that returns the tail of the list
*/
t_node *last(t_node *M)
{
    //base case 1: list is empty
    if (M == NULL)
    {
        return NULL;
    }

    //base case 2: there is only 1 element in the list
    else if (M->next == NULL)
    {
        return M;
    }

    //recursion
    else
    {
        return last(M->next);
    }
}


/*
function to print all nodes of the list
*/
void print(t_node *List_print)
{
    printf("\n--------\n");
    t_node *current = List_print; //current pointer that first points to head

    if(current==NULL)
    {
        printf("The list is empty\n");
    }
    while (current!=NULL) //while the list is not empty
    {
        printf("Val  : %s\n", current->elem); //print the value and go to the next node
        current=current->next;
    }
    printf("--------\n");
}


/*
function to delete the head
*/
t_node *deleteHead(t_node *List)
{
    List = List->next;  //replace head value by next
}

/*
function to delete a node
*/
t_node *Delete(t_node* l, char value[5], int *flag)
{
    //declare current and previous pointers, both pointing to head
    t_node *curr = l;
    t_node*prev = l;

    //first check if the list is empty
    if(curr==NULL)
    {
        printf("the list is empty\n");
    }

    //traversal
    while(curr!=NULL)
    {
        //compare using a string method (0: same string)
        if((strcmp(value, curr->elem))==0)//si on a reperé la lre
        {
            (*flag)=1; //flag for existence

            //beginning of the list
            if(curr==l)
            {
                curr=curr->next;
                free(prev);

                return curr;
            }
            else
            {
                //end of list
                if(curr->next==NULL)
                {
                    free(curr);
                    prev->next=NULL;
                }
                //middle of list
                else
                {

                    prev->next=curr->next;
                    free(curr);
                }
                return l;
            }
        }

        //update pointers
        prev=curr;
        curr=curr->next;

    }

}



/*
recursive function to free allocated memory
*/
void freeList(t_node* List)
{
    //base case
    if(List == NULL)
    {
        //nothing to do
    }
    else
    {
        freeList(List->next);
        free(List);
    }
}






