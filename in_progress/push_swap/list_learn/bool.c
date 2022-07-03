#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

node *head = NULL;
node *curr = NULL;

node* create_list(int number)
{
    printf("\n creating list with headnode as [%d]\n",number);
    node *ptr = (node*)malloc(sizeof(node));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->number = number;
    ptr->next = NULL;

    head = curr = ptr;
    return ptr;
}

node* add_to_list(int number, bool add_to_end)
{
    if(NULL == head)
    {
        return (create_list(number));
    }

    if(add_to_end)
        printf("\n Adding node to end of list with numberue [%d]\n",number);
    else
        printf("\n Adding node to beginning of list with number he[%d]\n",number);

    node *ptr = (node*)malloc(sizeof(node));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->number = number;
    ptr->next = NULL;

    if(add_to_end)
    {
        curr->next = ptr;
        curr = ptr;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }
    return ptr;
}

node* search_in_list(int number, node **prev)
{
    node *ptr = head;
    node *tmp = NULL;
    bool found = false;

    printf("\n Searching the list for numberue [%d] \n",number);

    while(ptr != NULL)
    {
        if(ptr->number == number)
        {
            found = true;
            break;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }
    }

    if(true == found)
    {
        if(prev)
            *prev = tmp;
        return ptr;
    }
    else
    {
        return NULL;
    }
}

int delete_from_list(int number)
{
    node *prev = NULL;
    node *del = NULL;

    printf("\n Deleting numberue [%d] from list\n",number);

    del = search_in_list(number,&prev);
    if(del == NULL)
    {
        return -1;
    }
    else
    {
        if(prev != NULL)
            prev->next = del->next;

        if(del == curr)
        {
            curr = prev;
        }
        else if(del == head)
        {
            head = del->next;
        }
    }

    free(del);
    del = NULL;

    return 0;
}

void print_list(void)
{
    node *ptr = head;

    printf("\n -------Printing list Start------- \n");
    while(ptr != NULL)
    {
        printf("\n [%d] \n",ptr->number);
        ptr = ptr->next;
    }
    printf("\n -------Printing list End------- \n");

    return;
}

int main(void)
{
    int i = 0, ret = 0;
    node *ptr = NULL;

    print_list();

    for(i = 5; i<10; i++)
        add_to_list(i,true);

    print_list();

    for(i = 4; i>0; i--)
        add_to_list(i,false);

    print_list();

    for(i = 1; i<10; i += 4)
    {
        ptr = search_in_list(i, NULL);
        if(NULL == ptr)
        {
            printf("\n Search [number = %d] failed, no such element found\n",i);
        }
        else
        {
            printf("\n Search passed [number = %d]\n",ptr->number);
        }

        print_list();

        ret = delete_from_list(i);
        if(ret != 0)
        {
            printf("\n delete [number = %d] failed, no such element found\n",i);
        }
        else
        {
            printf("\n delete [number = %d]  passed \n",i);
        }

        print_list();
    }

    return 0;
}
