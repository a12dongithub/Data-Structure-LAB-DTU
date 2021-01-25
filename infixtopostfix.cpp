#include <bits/stdc++.h>  
using namespace std;  
  

int isOperator(char input)  
{  
    switch (input) {  
    case '+':  
        return 1;  
    case '-':  
        return 1;  
    case '*':  
        return 1;  
    case '%':  
        return 1;  
    case '/':  
        return 1;  
    case '(':  
        return 1;  
    }  
    return 0;  
}  
  

int isOperand(char input)  
{  
    if (input >= 65 && input <= 90  
        || input >= 97 && input <= 122)  
        return 1;  
    return 0;  
}  
  
int inPrec(char input)  
{  
    switch (input) {  
    case '+':  
    case '-':  
        return 2;  
    case '*':  
    case '%':  
    case '/':  
        return 4;  
    case '(':  
        return 0;  
    }  
}  
  

int outPrec(char input)  
{  
    switch (input) {  
    case '+':  
    case '-':  
        return 1;  
    case '*':  
    case '%':  
    case '/':  
        return 3;  
    case '(':  
        return 100;  
    }  
}  
  

void inToPost(char* input)  
{  
    stack<char> s;  
  
   
    int i = 0;  
    while (input[i] != '\0') {  
  
        
        if (isOperand(input[i])) {  
            printf("%c", input[i]);  
        }  
  
       
        else if (isOperator(input[i])) {  
            if (s.empty()  
                || outPrec(input[i]) > inPrec(s.top()))  
                s.push(input[i]);  
            else {  
                while (!s.empty()  
                    && outPrec(input[i]) < inPrec(s.top())) {  
                    printf("%c", s.top());  
                    s.pop();  
                }  
                s.push(input[i]);  
            }  
        }  
  
      
        else if (input[i] == ')') {  
            while (s.top() != '(') {  
                printf("%c", s.top());  
                s.pop();  
  
                
                if (s.empty()) {  
                    printf("Wrong input\n");  
                    exit(1);  
                }  
            }  
  
            
            s.pop();  
        }  
        i++;  
    }  
  
  
    while (!s.empty()) {  
        if (s.top() == '(') {  
            printf("\n Wrong input\n");  
            exit(1);  
        }  
        printf("%c", s.top());  
        s.pop();  
    }  
}  
  

int main()  
{  
    string s;
    cin >> s;
      
    inToPost(input);  
    return 0;  
}  