#include <stdio.h>
#include <windows.h>

void push(int a[10], int *top, int size);
void display(int a[10], int *top, int size);
void pop(int a[10], int *top, int size);

void push(int a[10], int *top, int size)
{
    printf("\e[1;1H\e[2J");
    int i;
    int element;
    if (*top == (size - 1))
    {
        printf("STACK OVERFLOW!\n");
        scanf("%d", &i);
    }
    else
    {
        printf("Enter the element to input : ");
        scanf("%d", &element);
        (*top)++;
        a[(*top)] = element;
        printf("\e[1;1H\e[2J");
        printf("The element %d was pushed into the stack.\n", element);
        scanf("%d", &element);
    }
}
void pop(int a[10], int *top, int size)
{
    int i;
    if ((*top) == -1)
    {
        printf("STACK UNDERFLOW!!\n");
        printf("Enter a number to return to main menu : ");
        scanf("%d", &i);
    }
    else
    {
        a[(*top)] = 0;
        (*top)--;
    }
}
void display(int a[10], int *top, int size)
{
    printf("\e[1;1H\e[2J");

    int i;
    if ((*top) == -1)
    {
        printf("EMPTY STACK!!\n");
        printf("Enter a number to return to main menu : ");
        scanf("%d", &i);
    }
    else
    {
        for (i = 0; i < size; i++)
        {
            printf("|%d", a[i]);
        }
        printf("\nEnter a number to return to main menu : ");
        scanf("%d", &i);
    }
}
void peek(int a[10], int *top, int size)
{
    printf("\e[1;1H\e[2J");

    int i;
    if ((*top) == -1)
    {
        printf("THE STACK IS EMPTY!\n");
        scanf("%d", &i);
    }
    else
    {
        printf("%d\n", a[*top]);
        scanf("%d", &i);
    }
}
void main()
{
    int stack[5];

    int ch = 1;

    // TOP VARIABLE SET TO -1
    int top = -1, size;
    printf("Enter the size of stack to be used : ");
    scanf("%d", &size);
    while (ch != 0)
    {
        printf("\e[1;1H\e[2J");
        printf("STACK OPERATIONS IN C\n");
        printf("\n");
        printf("MENU\n   1.View Current Stack\n   2.Push element into Stack\n   3.Pop Element from Stack\n   4.Peek the first element in stack\n     0.Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            display(stack, &top, size);
        }
        else if (ch == 2)
        {
            push(stack, &top, size);
        }
        else if (ch == 3)
        {
            pop(stack, &top, size);
        }
        else if (ch == 4)
        {
            peek(stack, &top, size);
        }
    }
}
