#include <iostream>
using namespace std;


struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int key)
{
    Node* node = new Node;
    node->data = key;
    node->left = node->right = nullptr;

    return node;
}
void count(struct Node* node, int &x){
    if (node == nullptr) 
        return; 
  
    
    count(node->left,x); 
  
    
    count(node->right,x); 
  
   
    x++;
}

void search(struct Node* node, int x){
    if (node == NULL) 
        return; 
  
    
    search(node->left,x); 
  
    
    search(node->right,x); 
  
   
    if(node->data == x){cout << "EXISTS" << endl;}
}

int maxDepth(Node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        int lDepth = maxDepth(node->left);  
        int rDepth = maxDepth(node->right);  
      
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}  

void inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root){
    if (root == nullptr) 
        return; 
  
    
    cout << root->data << " "; 
  
    
    preorder(root->left);  
  
    
    preorder(root->right); 
}

void postorder(Node *root){
    if(root == nullptr)
        return;

    postorder(root->left); 
  
    
    postorder(root->right); 
  
   
    cout << root->data << " "; 
}
Node* minimumKey(Node* curr)
{
    while (curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;
}

Node* insert(Node* root, int key)
{
    if (root == nullptr)
        return newNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);

    else
        root->right = insert(root->right, key);

    return root;
}


void searchKey(Node* &curr, int key, Node* &parent)
{
    while (curr != nullptr && curr->data != key)
    {
        parent = curr;

        if (key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void deleteNode(Node*& root, int key)
{
    Node* parent = nullptr;

    Node* curr = root;

    searchKey(curr, key, parent);

    if (curr == nullptr)
        return;

    if (curr->left == nullptr && curr->right == nullptr)
    {

        if (curr != root)
        {
            if (parent->left == curr)
                parent->left = nullptr;
            else
                parent->right = nullptr;
        }
        else
            root = nullptr;

        free(curr);  
    }

    else if (curr->left && curr->right)
    {
        Node* successor  = minimumKey(curr->right);

        int val = successor->data;

        deleteNode(root, successor->data);

        curr->data = val;
    }

    else
    {
        Node* child = (curr->left)? curr->left: curr->right;


        if (curr != root)
        {
            if (curr == parent->left)
                parent->left = child;
            else
                parent->right = child;
        }

        else
            root = child;

        free(curr);
    }
}

int main()
{
    int t,n;
    Node* root = nullptr;
    do{
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Search\n");
        printf("4.Inorder\n");
        printf("5.Preorder\n");
        printf("6.Postorder\n");
        printf("7.Height\n");
        printf("8.Count Nodes\n");
        scanf("%d",&t);
        switch(t)
        {
            case 1: printf("Enter Number to Add\n");
                    scanf("%d",&n);
                    root = insert(root, n);
                    preorder(root);
                    cout << endl;
                    break;
            case 2: printf("Enter Number to Delete\n");
                    scanf("%d",&n);
                    deleteNode(root,n);
                    preorder(root);
                    break;
            case 3: printf("Enter Number to Search\n");
                    scanf("%d",&n);
                    search(root,n);
                    break;
            case 4: printf("Inorder\n");
                    inorder(root);
                    break;
            case 5: printf("Preorder\n");
                    preorder(root);
                    
                    break;
            case 6: printf("Postorder\n");
                    postorder(root);
                    
                    break;
            case 7: printf("Max Height is\n");
                    cout << maxDepth(root) << endl;
                    
                    
                    break;
            case 8: printf("Total Nodes Present is\n");
                    int x=0;
                    count(root,x);
                    cout << x << endl;
                    break;
            //default: printf("Wrong Choice\n");
            //         break;
        }
    }while(t!=9);
    return 0;
}