#include "SLL.h"

int main()
{

    t_node * list = NULL;
    t_node * new_n = NULL;

    t_node * head = NULL;
    t_node * tail = NULL;
    int i, n;
    char index[5];
    int exist = 0;

    //input for size of list
    printf("How many elements do you want in this linked list?\n");
    scanf("%d", &n);

    //loop to create and insert all nodes
    for(i=0; i<n; i++)
    {
        new_n = create();
        list = InsertEnd(list, new_n);
    }

    print(list);


    //first and last elements
    head = first(list);
    printf("first : %s\n", head->elem);
    tail = last(list);
    printf("last : %s\n", tail->elem);


    print(list);


    //delete head
    list = deleteHead(list);
    printf("List after deletion of head\n");

    print(list);


    //input a node to delete
    printf("select a node to delete\n");
    fflush(stdin);
    gets(index);
    list = Delete(list, index, &exist);

    //check if it exists
    if(exist==1)
    {
        print(list);

    }
    else
    {

        printf("element to delete doesn't exist\n");
    }

    freeList(list);
    return 0;
}
