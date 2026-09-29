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

void display()
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", heap[i]);
    }

    printf("\n");
}

int main()
{
    int a[] = {78, 92, 65, 88, 95, 72, 84, 90};
    int i;

    printf("Max Heap Insertion\n\n");

    for (i = 0; i < 8; i++)
    {
        insert(a[i]);

        printf("After inserting %d: ", a[i]);
        display();
    }

    return 0;
}
