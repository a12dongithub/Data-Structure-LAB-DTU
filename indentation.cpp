#include <stdio.h>
#define MAX_SIZE 20
#define MAX_LINE_LENGTH 100
struct Stack
{
    int stack[MAX_SIZE];
    int top;
};

void push(struct Stack *st, int num)
{
    if (st->top < MAX_SIZE - 1)
    {
        st->stack[++(st->top)] = num;
    }
    // else
    // {
    //     printf("Stack overflow");
    // }
}

int getLastElement(struct Stack *st)
{
    if (st->top > -1)
    {
        return st->stack[(st->top)];
    }
    else
    {
        return -1;
    }
}

int pop(struct Stack *st)
{
    if (st->top > -1)
    {
        return st->stack[(st->top)--];
    }
    else
    {
        //        printf("Stack underflow\n");
        return -1;
    }
}

void displayStack(struct Stack *st)
{
    if (st->top > -1)
    {
        int m = st->top;
        while (m > -1)
        {
            printf("%d ", st->stack[m]);
            m--;
        }
    }
    else
    {
        //      printf("Stack underflow\n");
    }
}

int getNumberOfSpaces(char a[])
{
    int spaces = 0;
    int i = 0;
    while (a[i] == '\t' || a[i] == ' ')
    {
        if (a[i] == '\t')
            spaces = spaces + 4;
        else
            spaces = spaces + 1;
        i++;
    }
    return spaces;
}

int checkIndentation(FILE *file)
{
    char a[MAX_LINE_LENGTH];
    struct Stack s;
    s.top = -1;
    int lineNumber = 1;
    fgets(a, MAX_LINE_LENGTH, file);
    int currentSpaces = getNumberOfSpaces(a);
    push(&s, currentSpaces);
    while (fgets(a, MAX_LINE_LENGTH, file))
    {
        lineNumber++;
        // displayStack(&s);
        // printf("\n");
        int count = getNumberOfSpaces(a);
        if (count > currentSpaces)
        {
            push(&s, count);
            currentSpaces = count;
            //printf("Current Spaces: %d \n", currentSpaces);
        }
        else if (count < currentSpaces)
        {
            //pop current spaces
            pop(&s);
            //get the previous spaces
            int prev = getLastElement(&s);
            if (prev != -1 && prev != count)
            {
                //  printf("Prev: %d Current: %d", prev, count);
                return lineNumber;
            }
            currentSpaces = prev;
            //printf("Current Spaces: %d \n", currentSpaces);
        }
    }
    return -1;
}

int main()
{
    FILE *filepointer;
    char file_name[25];
    printf("Enter the name of the file you want to check.\n");
    gets(file_name);
    filepointer = fopen(file_name, "r");
    if (filepointer == NULL)
    {
        printf("Error opening file");
    }
    else
    {
        int result = checkIndentation(filepointer);
        if (result == -1)
        {
            printf("File is OK");
        }
        else
            printf("Error at line %d, line is not indented", result);
    }
}