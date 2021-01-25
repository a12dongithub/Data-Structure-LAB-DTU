#include <iostream>                             
                                                                                                                                                                                            #include <queue>
                                                                                                                                                                                            #include <vector>                                                                                                                                     
using namespace std;
void heapify(int arr[], int n, int i) 
{ 
    int largest = i;  
    int l = 2*i + 1; 
    int r = 2*i + 2; 
  
    
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
         
        heapify(arr, n, largest); 
    } 
} 
void DisplayHeap(priority_queue<int> gq)
{
    priority_queue<int> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}
 
int main()
{
    int t,n;
    priority_queue<int> pq;                                                                                                                                                                         vector<int> a;
    do{
        printf("1. Insert in Queue\n");
        printf("2. Delete in Queue\n");
        printf("3. Display Queue\n");
        printf("4. Heap Sort\n");
        printf("5. Exit\n");
        scanf("%d",&t);
        switch(t){
            case 1: printf("Enter Number to Add to Queue\n");
                    scanf("%d",&n);
                    pq.push(n);a.push_back(n);
                    break;
            case 2: printf("Ender Number to Delete\n");
                    scanf("%d",&n);
                    break;
            case 3:
                    break; 
            case 4:
                    break;

                    
        }
    }while(t!=5);
    return 0;
    
}