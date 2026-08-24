#include <stdio.h>

void displayArr(int arr[], int n ) {
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}

/*int indinsertion(int arr[], int size, int element, int capacity, int index) {
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = size -1; i >= index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
    
    
}*/

int indinsertion(int arr[], int size, int newElement, int capacity, int index) {
    if (size >= capacity)
    {
        return -1;
    }
    for (int i = 0; i < size-1; i++)
    {
       arr[i] = arr[i+1];
    }
    arr[size -1] = newElement;
}

int main() {
    int arr[50] = {1,22,55,66,77};
    int newElement = 0, index = 0;
    int size = 5;
    int capacity = 50;
    indinsertion(arr, size, newElement, capacity,index);
   // displayArr(arr, size);
    size += 1;
    displayArr(arr, size);
    return 0;
}