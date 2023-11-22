#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    int priority;
    struct node *next;
};

struct node *head, *p, *ptr, *prev;
void delete()
{
    int key, flag = 0;
    printf("Enter the element to delete : ");
    scanf("%d", &key);
    ptr = head;
    prev = NULL;
    if (ptr != NULL && ptr->data == key)
    {
        head = ptr->next;
        free(ptr);
        printf("Element deleted successfully\n");
        return;
    }
    while (ptr != NULL)
    {
        if (ptr->data == key)
        {
            flag = 1;
            break;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    if (flag == 1)
    {
        prev->next = ptr->next;
        free(ptr);
    }
    else
    {
        printf("Element not found\n");
    }
}
void input()
{
    p = (struct node *)malloc(sizeof(struct node));
    int flag = 0;
    printf("Enter the data : ");
    scanf("%d", &p->data);
    printf("Enter the priority (0-100) : ");
    scanf("%d", &p->priority);
    if (head == NULL)
    {
        head = p;
        p->next = NULL;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            if (ptr->next->priority > p->priority)
            {
                flag = 1;
                break;
            }
            ptr = ptr->next;
        }
        if (flag = 1)
        {
            p->next = ptr->next;
            ptr->next = p;
        }
    }
}

void display()
{
    ptr = head;
    printf("\n");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void main()
{
    head = NULL;
    int ch = 1;
    while (ch != 0)
    {
        printf("1.Enter \t\t2.Delete \t\t3.Display\n");
        printf("Enter the option : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            input();
        }
        if (ch == 2)
        {
            delete ();
        }
        if (ch == 3)
        {
            display();
        }
    }
}