#include <stdio.h>

void displayArr(int arr[], int n) {
    // Traversal yahi hota hai
    for (int i = 0; i < n; i++)
    {
       printf("%d\n", arr[i]);
    }
    
}

void indDeleation(int arr[], int size,int index) {
    for (int i = 0; i < size - 1; i++)
    {
       arr[i] = arr[i+1];
    }

}

int main() {
    int arr[100] = {7,8,12,27,88};
    int size = 5, /*element = 45,*/ index = 3;
    //displayArr(arr,4);
    indDeleation(arr,size,index);
    size -= 1;
    displayArr(arr,size);
    return 0;
}