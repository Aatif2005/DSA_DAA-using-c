#include <stdio.h>

int heap[100];
int size = 0;

// swap function
void swap(int *a, int *b)
{
    int ptr = *a;
    *a = *b;
    *b = ptr;
}

// insert function
void insert(int value)
{
    int i = size;
    heap[i] = value;
    size++;

    // move up
    while (i > 0 && heap[(i - 1) / 2] < heap[i])
    {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// delete root (max element)
void deleteRoot()
{
    if (size == 0)
    {
        printf("Heap is empty\n");
        return;
    }

    heap[0] = heap[size - 1];
    size--;

    int i = 0;

    while (1)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest == i)
            break;

        swap(&heap[i], &heap[largest]);
        i = largest;
    }
}

// display heap
void display()
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// main function
int main()
{
    insert(10);
    insert(20);
    insert(5);
    insert(30);
    insert(15);

    printf("Heap: ");
    display();

    deleteRoot();

    printf("After deletion: ");
    display();

    return 0;
}