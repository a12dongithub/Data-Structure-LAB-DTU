#include <stdio.h>
int size = 0;
void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}


void heapify(int array[], int size, int i) {
  if (size == 1) {
    printf("Single element in the heap");
  } else {

    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;


    if (largest != i) {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}


void insert(int array[], int newNum) {
  if (size == 0) {
    array[0] = newNum;
    size += 1;
  } else {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--) {
      heapify(array, size, i);
    }
  }
}


void deleteRoot(int array[], int num) {
  int i;
  for (i = 0; i < size; i++) {
    if (num == array[i])
      break;
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(array, size, i);
  }
}


void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}

void heapSort(int array[]){
    for(int i =0; i < size; i++){
        printf("%d ",array[0]);
        deleteRoot(array,array[0]);
    }
}

int main() {
  int array[10];
  int t,n;
                                                                                                                                                                           
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
                    insert(array,n);
                    break;
            case 2: printf("Ender Number to Delete\n");
                    scanf("%d",&n);
                    deleteRoot(array,n);
                    break;
            case 3: printArray(array,size);
                    break; 
            case 4: heapSort(array);
                    printArray(array,size);
                    break;

                    
        }
    }while(t!=5);
    return 0;
}