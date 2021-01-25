#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_map> 
#include <map>
#include <set>
typedef long long int ll;
#define mod 1000000007;
#define loop(x,a,n) for(ll x = a; x < n; ++x)
using namespace std;
// SAMARTH SINGHAL 2K19/CO/335
#define MAX 100007
#define MIN -1000000007



class node {
public:
	int data;
	node* next;
	node* prev;
	node(int data) {
		this->data = data;
		next = NULL;
		prev = NULL;
	}
};

void insertAtHead(node * &head, int data) {

	node* n = new node(data);
	n->next = head;
	if ((head) != NULL) {
		(head)->prev = n;
	}
	head = n;
	// cout<<n->data<<endl;
}
void insertSorted(node * &head, int data) {
	node* n = new node(data);
	
	if (head == NULL)
		insertAtHead(head,data);
	else if (data <= (head)->data) {
		insertAtHead(head, data);
	}
	
	else{
		node* temp = head;
		while (temp != NULL) {
			int a = temp->data;
			if (a >= data) {
				n->next = temp;
				n->prev = temp->prev;
				temp->prev = n;
				n->prev->next = n;
				//cout << "asd";
				break;
			}
			else if (a <= data && temp->next == NULL) {
				n->prev = temp;
				temp->next = n;
				//cout << "asd";
				break;
			}
			else {
				temp = temp->next;
			}

		}
	}
}


void display(node * head) {

	node* temp = head;
	int ii =0;
	while (temp != NULL) {
		
		cout << temp->data << "->";
		temp = temp->next;
		ii++;
	}

	cout << "count = " << ii << endl;
}
void deleteAtHead(node*& head) {
	node* temp = head;
	head = head->next;
	delete temp;
}

bool searchData(node* head, int data) {

	if (head == NULL) {
		return false;
	}

	if (head->data == data) {
		return true;
	}
	return searchData(head->next, data);
}

int findMax(node* head) {
	if (head == NULL) {
		return 0;
	}
	else {
		node* temp = head;
		int a = temp->data;
		while (temp->next != NULL) {
			
			if (temp->next->data > a) { a = temp->next->data; temp = temp->next; }
			else { temp = temp->next; }
		}
		return a;
	}
}

int findMin(node* head) {
	if (head == NULL) {
		return 0;
	}
	else {
		node* temp = head;
		int a = temp->data;
		while (temp->next != NULL) {

			if (temp->next->data < a) { a = temp->next->data; temp = temp->next; }
			else { temp = temp->next; }
		}
		return a;
	}
}

int main(){
	int c;
	node* head = NULL;
	
	printf("Enter your choice :\n");
		while(1){
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display\n");
		printf("4. Search\n");
		printf("5. Insert Sorted\n");
		printf("6. Max\n");
		printf("7. Min\n");
		printf("0. Quit\n");

		printf("Enter choice : ");

		scanf("%d", &c);
		printf("\n");

		switch(c){
			case 0:
			return 0;
			break;
			case 1:
			int x;
			scanf("%d",&x);
			insertAtHead(head,x);
			display(head);
			break;
			case 2:
			deleteAtHead(head);
			display(head);
			break;
			case 3:
			display(head);
			break;
			case 4:
			int s;
			scanf("%d",&s);
			if(searchData(head,s)){printf("Does Exist\n");}
			else{printf("Does not exist\n");}
			break;
			case 5:
			int is;
			scanf("%d",&is);
			insertSorted(head,is);
			display(head);
			break;
			case 6:
			cout << findMax(head) << endl;
			break;
			case 7:
			cout << findMin(head)<<endl;
			break;

			
			
			default:
			printf("INVALID INPUT\n");
			break;
		}
	}
	return 0;
}