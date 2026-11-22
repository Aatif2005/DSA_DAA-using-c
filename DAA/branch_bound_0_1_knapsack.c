#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int weight, profit;
    double ratio;
} Item;

typedef struct
{
    int level, weight, profit;
    double bound;
} Node;

Item items[MAX];
Node heap[100000];
int heapSize = 0;

void swap(Node *a, Node *b)
{
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void push(Node x)
{
    int i = ++heapSize;
    heap[i] = x;

    while (i > 1 && heap[i].bound > heap[i / 2].bound)
    {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}

Node pop()
{
    Node top = heap[1];
    heap[1] = heap[heapSize--];

    int i = 1;

    while (1)
    {
        int l = 2 * i;
        int r = 2 * i + 1;
        int largest = i;

        if (l <= heapSize &&
            heap[l].bound > heap[largest].bound)
            largest = l;

        if (r <= heapSize &&
            heap[r].bound > heap[largest].bound)
            largest = r;

        if (largest == i)
            break;

        swap(&heap[i], &heap[largest]);
        i = largest;
    }

    return top;
}

double bound(Node u, int n, int W)
{
    if (u.weight >= W)
        return u.profit;

    double result = u.profit;
    int j = u.level + 1;
    int totalWeight = u.weight;

    while (j < n && totalWeight + items[j].weight <= W)
    {
        totalWeight += items[j].weight;
        result += items[j].profit;
        j++;
    }

    if (j < n)
    {
        result += (W - totalWeight) * items[j].ratio;
    }

    return result;
}

int compare(const void *a, const void *b)
{
    Item *x = (Item *)a;
    Item *y = (Item *)b;

    if (x->ratio < y->ratio)
        return 1;

    if (x->ratio > y->ratio)
        return -1;

    return 0;
}

int knapsack(int n, int W)
{
    qsort(items, n, sizeof(Item), compare);

    heapSize = 0;

    Node u, v;

    u.level = -1;
    u.weight = 0;
    u.profit = 0;
    u.bound = bound(u, n, W);

    push(u);

    int maxProfit = 0;

    while (heapSize > 0)
    {
        u = pop();

        if (u.bound <= maxProfit)
            continue;

        if (u.level == n - 1)
            continue;

        v.level = u.level + 1;

        // Include current item
        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].profit;

        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = bound(v, n, W);

        if (v.bound > maxProfit)
            push(v);

        // Exclude current item
        v.weight = u.weight;
        v.profit = u.profit;

        v.bound = bound(v, n, W);

        if (v.bound > maxProfit)
            push(v);
    }

    return maxProfit;
}

int main()
{
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of items.\n");
        return 1;
    }

    printf("Enter weight and profit of each item:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &items[i].weight, &items[i].profit);

        if (items[i].weight <= 0 || items[i].profit < 0)
        {
            printf("Invalid item data.\n");
            return 1;
        }

        items[i].ratio =
            (double)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    if (W < 0)
    {
        printf("Invalid capacity.\n");
        return 1;
    }

    printf("Maximum Profit = %d\n", knapsack(n, W));

    return 0;
}