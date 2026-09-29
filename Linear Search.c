#include <stdio.h>

int heap[100];
int n = 0;

void insert(int value)
{
    int i, parent, temp;

    heap[n] = value;
    i = n;
    n++;

    while (i > 0)
    {
        parent = (i - 1) / 2;

        if (heap[parent] < heap[i])
        {
            temp = heap[parent];
            heap[parent] = heap[i];
            heap[i] = temp;

            i = parent;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    int a[] = {78, 92, 65, 88, 95, 72, 84, 90};
    int i;
    int max;
    int linearMax;
    int comparisons = 0;

    /* Creating Max Heap */
    for (i = 0; i < 8; i++)
    {
        insert(a[i]);
    }

    /* Maximum using Max Heap */
    max = heap[0];

    printf("Maximum using Max Heap = %d\n", max);
    printf("Operations = 1\n");

    /* Maximum using Linear Search */
    linearMax = a[0];

    for (i = 1; i < 8; i++)
    {
        comparisons++;

        if (a[i] > linearMax)
        {
            linearMax = a[i];
        }
    }

    printf("Maximum using Linear Search = %d\n", linearMax);
    printf("Comparisons = %d\n", comparisons);

    return 0;
}
