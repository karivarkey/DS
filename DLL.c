#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head, *p, *ptr;

void insertAtBeginning()
{
    p = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d", &p->data);
    if (head == NULL)
    {
        head = p;
        p->next = NULL;
        p->prev = NULL;
    }
    else
    {
        head->prev = p;
        p->next = head;
        p->prev = NULL;
        head = p;
    }
}

void insertAtEnd()
{
    p = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    printf("Enter the data : ");
    scanf("%d", &p->data);
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = p;
    p->prev = ptr;
    p->next = NULL;
}

void display()
{
    if (head == NULL)
    {
        printf("EMPTY LIST\n");
    }
    else
    {
        printf("The data inside the list are :");
        ptr = head;
        printf("\n");
        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void insertAfter()
{
    p = (struct node *)malloc(sizeof(struct node));
    int flag = 0, key;
    printf("Enter the value to insert : ");
    scanf("%d", &p->data);
    printf("Value after which %d is to be inserted : ", p->data);
    scanf("%d", &key);
    printf("If multiple values exists , will insert after first value!!");
    ptr = head;
    while (ptr->next != NULL)
    {
        if (ptr->data == key)
        {
            flag = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (flag == 0)
    {
        printf("Element not found!");
    }
    else
    {
        p->next = ptr->next;
        ptr->next->prev = p;
        ptr->next = p;
        p->prev = ptr;
    }
}

void deleteBeginning()
{
    if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        ptr = head;
        head = ptr->next;
        head->prev = NULL;
        free(ptr);
    }
}
void deleteEnd()
{
    if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        ptr = head;
        while (ptr != NULL)
        {
            ptr = ptr->next;
        }
        ptr = ptr->prev;
        ptr;
    }
}
void deleteMiddle()
{
    int key;
    ptr = head;
    printf("Enter the value of element to delete : ");
    scanf("%d", &key);
    int flag = 0;
    ptr = head;
    while (ptr->next != NULL)
    {
        if (ptr->data == key)
        {
            flag = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (flag == 0)
    {
        printf("Element not found!");
    }
    else
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
    }
}
int main()
{
    head = NULL;
    int ch = 1;
    while (ch != 0)
    {
        printf("1.INSERT [BEGINNING]\t2.INSERT [END]\t3.INSERT [MIDDLE]\t\n4.DELETE [BEGINNING]\t5.DELETE [END]\t6.DELETE [MIDDLE]\n7.DISPLAY");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            insertAtBeginning();
        }
        if (ch == 2)
        {
            insertAtEnd();
        }
        if (ch == 3)
        {
            insertAfter();
        }
        if (ch == 4)
        {
            deleteBeginning();
        }
        if (ch == 5)
        {
            deleteEnd();
        }
        if (ch == 6)
        {
            deleteMiddle();
        }
        if (ch == 7)
        {
            display();
        }
    }
}