#include <Stdio.h>

void enqueue(int queue[10], int *front, int *rear, int size);
void dequeue(int queue[10], int *front, int *rear, int size);
void display(int queue[10], int *front, int *rear, int size);

void enqueue(int queue[10], int *front, int *rear, int size)
{
    int junk;
    if ((*front) == (*rear) && ((*front) != -1))
    {
        printf("THE QUEUE IS FULL!");
        printf("\nEnter a number to exit:");
        scanf("%d", &junk);
    }
    else
    {
        printf("\e[1;1H\e[2J");
        printf("Enter the element to be inserted : ");
        (*rear)++;
        scanf("%d", &queue[(*rear)]);
        printf("%d is inserted at %d", queue[(*rear)], *rear);

        printf("\n  Enter a number to exit:");
        scanf("%d", &junk);
    }
}
void dequeue(int queue[10], int *front, int *rear, int size)
{
    int junk;
    printf("\e[1;1H\e[2J");
    (*front)++;
    printf("%d from location %d was removed.", queue[(*front)], (*front));
    queue[(*front)] = 0;
    printf("\nEnter a number to exit");
    scanf("%d", &junk);
}
void display(int queue[10], int *front, int *rear, int size)
{
    int i, junk;
    printf("\e[1;1H\e[2J");
    for (i = 0; i != ((*rear) + 1); i++)
    {
        printf("|%d|", queue[i]);
    }
    printf("\nEnter a number to exit");
    scanf("%d", &junk);
}

void main()
{
    int front, rear, queue[10], ch = 1, size;
    front = rear = -1;
    printf("Enter the size of the queue to be used : ");
    scanf("%d", &size);
    while (ch != 0)
    {
        printf("\e[1;1H\e[2J");
        printf("WELCOME TO QUEUE IN C\n");
        printf("\n   1.Enqueue\n   2.Dequeue\n   3.Display\n\n   0.Exit\n\nEnter your choice : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            enqueue(queue, &front, &rear, size);
        }
        else if (ch == 2)
        {
            dequeue(queue, &front, &rear, size);
        }
        else if (ch == 3)
        {
            printf("%d", queue[0]);
            scanf("%d", &ch);
            display(queue, &front, &rear, size);
        }
    }
}