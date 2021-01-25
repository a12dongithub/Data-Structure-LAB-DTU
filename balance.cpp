#include <iostream>

typedef long long int ll;
#define mod 1000000007;
#define loop(x,a,n) for(ll x = a; x < n; ++x)
using namespace std;
// SAMARTH SINGHAL 2K19/CO/335
#define MAX 100007
#define MIN -1000000007

int invert(int a) {if (a == 0) {return 1;}else if(a==1){return 0;} else{return -1;}}

//////////////////////////////////////////////////////////////////////////////
/////////////////////////// S T A C K ////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
class Stack {
	int top;

public:
	int a[MAX];  

	Stack() { top = -1; }
	bool push(int x);
	int pop();
	
};

bool Stack::push(int x)
{
	if (top >= (MAX - 1)) {
		cout << "ERROR";
		return false;
	}
	else {
		a[++top] = x;
		//cout << x;
		return true;
	}
}

int Stack::pop()
{
	if (top < 0) {
		cout << "ERROR";
		return 0;
	}
	else {
		int x = a[top--];
		return x;
	}
}

void display(Stack s,int n) {
	while (n--) {
		cout << s.pop() << ' ';
	}
}

int main(){
	char c[MAX];
	int n;
	cin >> n;
	loop(i,0,n){
		cin >> c[i];
	}
	int ans=0;
	loop(i,0,n){
		if(c[i] == '('){ans++;}
		if(c[i] == ')'){ans--;}
		if(ans < 0){cout << "UNBALANCED" << endl;break;}
	}
	if(ans > 0){cout << "UNBALANCED" << endl;}
	else if(ans ==0 ){cout << "BALANCED" << endl;}

}