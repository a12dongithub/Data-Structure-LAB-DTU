#include<stdio.h>
#include <stdlib.h>
struct LL
{
	int value;
	struct LL *node;
};

struct LL *init()
{
	struct LL *p = (struct LL*)malloc(sizeof(struct LL));
	p->value = 0;
	p->node = NULL;
	return p;
}

void print(struct LL *ll)
{
	if(ll->node == NULL)
	{
		return;
	}
	printf("%d->",ll->value);
	print(ll->node);
}

LL *insertBegin(struct LL *ll, int n)
{
	if(ll->node == NULL)
	{
		ll->value = n;
		ll->node = init();
		return ll;
	} else {
		struct LL *temp = init();
		temp->value = n;
		temp->node = ll;
		return temp;
	}
}

void insertEnd(struct LL *ll, int n)
{
	if(ll->node == NULL)
	{
		ll->value = n;
		ll->node = init();
	} else {
		insertEnd(ll->node, n);
	}
}

LL *find(struct LL *ll, int n, int k)
{
	if(ll->node == NULL)
	{
		printf("Value Doesn't Exist\n");
		return ll;
	} else {
		if(ll->value == k)
		{
			struct LL *temp = init();
			temp->value = n;
			temp->node = ll->node;
			ll->node = temp;
			return ll;
		} else {
			find(ll->node, n, k);
		}
	}
}

void insertAfter(struct LL *ll, int n, int k)
{
	struct LL *temp = find(ll, n, k);
	struct LL *next;
	if(temp->node == NULL)
	{
		printf("Value Doesn't Exits\n");
	} else {
		next = ll;
		while(next != NULL)
		{
			if(ll->value == k)
			{
				ll->node = temp;
				free(temp);
				break;
			} else {
				next = next->node;
			}
		}	
	}
	
}

void search(struct LL *ll, int n)
{
	if(ll->node == NULL)
	{
		printf("Value Doesn't Exists\n");
		return;
	}
	if(ll->value == n)
	{	
		printf("Value Exists\n");
	} else {
		search(ll->node,n);
	}
}

void ddelete(struct LL *ll, int n)
{
	if(ll->node == NULL){
		printf("Value Doesn't Exists\n");
		return;
	}
	else {
		if(ll->node->value == n){
			ll->node = ll->node->node;
			return;
		} else {
			ddelete(ll->node, n);
		}
	}
}

int total_nodes(struct LL *ll)
{
	if(ll->node == NULL)
		return 0;
	return 1 + total_nodes(ll->node);
}



int main(int argc, char const *argv[])
{
	int t,n,k;
	struct LL *ll = init();
	do{
		printf("1.Insert back\n");
		printf("2.Insert After\n");
		printf("3.Insert Start\n");
		printf("4.Delete\n");
		printf("5.Total Nodes\n");
		printf("6.Search\n");
		printf("7.Print\n");
		printf("8.Exit\n");
		scanf("%d",&t);
		switch(t)
		{
			case 1: printf("Enter Number to Add\n");
					scanf("%d",&n);
					insertEnd(ll, n);
					break;
			case 2: printf("Enter Number to Add\n");
					scanf("%d",&n);
					printf("Enter Number to Add After\n");
					scanf("%d",&k);
					insertAfter(ll, n, k);
					break;
			case 3: printf("Enter Number to Add\n");
					scanf("%d",&n);
					ll = insertBegin(ll, n);
					break;
			case 4: printf("Enter Number to Delete\n");
					scanf("%d",&n);
					ddelete(ll, n);
					break;
			case 7: printf("Linked List\n");
					print(ll);
					printf("\n");
					break;
			case 6: printf("Enter Number to Search\n");
					scanf("%d",&n);
					search(ll, n);
					break;
			case 5: printf("Total Nodes Present in Linked List is %d\n", total_nodes(ll));
					break;
			case 8: printf("Exiting..........\n");
					break;
			default: printf("Wrong Choice\n");
					 break;
		}
	}while(t!=8);
	return 0;
}