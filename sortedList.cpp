#include <stdio.h>
#include <stdlib.h>
#define size 20

void display(int a[],int *place)
{
    if((*place)==0)
        printf("List is empty.\n");
        int i;
    for(i=0;i<(*place);i++)
    {
        printf("%d ",a[i]);
    }

    printf("\n");
}

void insert(int a[],int *place)
{
    int x;

    if((*place)==size)
    {
        printf("List is full.\n");
        return;
    }
    else
    {
        printf("Enter the value to be inserted : ");
        scanf("%d",&x);
        int j,k;
         for( j=0;j<=*place;j++)
        { 
        if(a[j]>x)
        {
            break;
        }
        }
        for( k=*place;k>=j;k--)
       {
        a[k+1]=a[k];
        }
        a[j]=x;
        (*place)++;
    }

}

    
void delet(int a[],int *place)
{
    if((*place)==0)
    {
        printf("List is empty\n\n");
        return;
    }

    else
    {
        int pos;
        printf("Enter the position(1 to %d) of the element to be deleted : ",(*place));
        scanf("%d",&pos);
        if(pos>(*place) || pos<1)
        {
            printf("Enter a valid position!\n");
            return;
        }
        int i;
        for(i=0;i<(*place);i++)
        {
            a[pos-1]=a[pos];
        }

        (*place)--;
    }


}

void search(int a[], int *place)
{
    int k;
    printf("Enter the element to be searched : ");
    scanf("%d",&k);
    int aa=0,h=*place,mid=0;
  while(aa<h)
  {
      mid=(aa+h)/2;
      if(a[mid]>k)
      {
          h=mid-1;
      }
      else if(a[mid]<k)
      {
          aa=mid+1;
      }
      else if(a[mid]==k)
      {
          printf("Element found at index %d\n",mid+1);
          return;
      }

}
}
int findMax(int a[], int *place){
    int n = *place;
    
}

  

int main()
{

	int ar[size];
	int place = 0;

	while(1)
        {
		
		int c;

		printf("Enter your choice :\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display\n");
		printf("4. Search\n");
		printf("0. Quit\n");
		printf("Enter choice : ");

		scanf("%d", &c);
		printf("\n");

		switch(c)
		{
			case 0:
				return 0;
				break;

			case 1:
				insert(ar, &place);
				display(ar,&place);
				break;

			case 2:
				delet(ar, &place);
				display(ar,&place);
				break;

			case 3:
				display(ar, &place);
				break;

			case 4:
				search(ar, &place);
				break;

			default:
				printf("Invalid input !\n\n");
				break;

            }
        }
    return 0;
}