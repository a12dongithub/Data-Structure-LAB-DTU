#include<stdio.h>
#define size 3
struct Queue
{
    int A[size];
    int front;
    int rear;
};
typedef struct Queue myQueue;

int isEmpty(myQueue *q)
{
    if(q->front==q->rear)
    {
        return(1);
    }
    return(0);
}

int isFull(myQueue *q)
{
    if((q->rear+1)%size==q->front)
    {
        return(1);
    }
    return(0);
}
void insert(myQueue *q,int x)
{

    if(isFull(q))
    {
        printf("Queue is Full.\n");
        return;
    }
    q->rear=(q->rear+1)%size;
    q->A[q->rear]=x;
    return;
}

int delet(myQueue *q)
{
    int x;
    if(isEmpty(q))
    {
        printf("Queue is Empty.\n");
        return(-1);
    }
    q->front=(q->front+1)%size;
    x=q->A[q->front];
    return(x);
}
void display(myQueue Q)
{
    if(Q.front==Q.rear)
    {
        printf("Queue is Empty.\n");
        //return(-1);
    } 
    
    int i;
    i=Q.rear;
    printf("\nQueue contents are as follows.\n");
    while(i>Q.front)
    {
        printf("%d ",Q.A[i]);
        i--;   
    }
    printf("\n");
}
int main()
{
    myQueue Q;
    int x,choice;
    Q.rear=-1;
    Q.front=-1;
    while(1)
    {
        printf("1. Insert.\n");
        printf("2. Delete.\n");
        printf("3. Display queue.\n");
        printf("4. Exit.\n");
        printf("\n Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter a number:");
            scanf("%d",&x);
            insert(&Q,x);
            display(Q);
            break;
            case 2:x=delet(&Q);
            printf("deleted number is :%d\n",x);
            display(Q);
            break;
            case 3:display(Q);
            break;
            case 4:return(0);
        }
    }//end of while
}//end of main