#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <unordered_map> 
#include <map>
#include <set>
#include <stdio.h> 
#include <stdlib.h> 
typedef long long int ll;
#define mod 1000000007;
#define loop(x,a,n) for(ll x = a; x < n; ++x)
using namespace std;
// SAMARTH SINGHAL 2K19/CO/335
#define MAX 1000000007
#define MIN -1000000007

void swapping(int& a, int& b) {     
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void display(int* array, int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
void merge(int* array, int l, int m, int r) {
    int i, j, k, nl, nr;
    nl = m - l + 1; nr = r - m;
    int larr[nl], rarr[nr];
    for (i = 0; i < nl; i++)
        larr[i] = array[l + i];
    for (j = 0; j < nr; j++)
        rarr[j] = array[m + 1 + j];
    i = 0; j = 0; k = l;
    while (i < nl && j < nr) {
        if (larr[i] <= rarr[j]) {
            array[k] = larr[i];
            i++;
        }
        else {
            array[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < nl) {      
        array[k] = larr[i];
        i++; k++;
    }
    while (j < nr) {   
        array[k] = rarr[j];
        j++; k++;
    }
}
void mergeSort(int* array, int l, int r) {
    int m;
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}
void IterativeMergeSort(int arr[], int n)
{
    for (int i = 1; i <= n - 1; i = 2 * i)
    {
        for (int l = 0; l < n - 1; l += 2 * i)
        {
            int m = min(l + i - 1, n - 1);
            int r = min(l + 2 * i - 1, n - 1);         
            merge(arr, l, m, r);
        }
    }
}
int main() {

    int n;
    cin >> n;
    int arr[n];    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);  
    display(arr, n);
}