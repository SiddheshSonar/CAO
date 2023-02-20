#include <stdio.h>
#include <stdlib.h>

int fifo(int s[], int size, int n)
{
    int arr[size], flag = 0, front = 0, hit = 0;
    for (int i = 0; i < size; i++)
    {
        arr[i] = s[i];
    }
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
    // printf("| F = %d ",front);
    printf("| HITS = %d", hit);
    printf("\n");
    for (int i = size; i < n; i++)
    {
        flag = 0;
        for (int j = 0; j < size; j++)
        {
            if (s[i] == arr[j])
            {
                hit++;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            arr[front] = s[i];
            front++;
            if (front >= size)
            {
                front = 0;
            }
        }
        for (int i = 0; i < size; i++)
        {
            printf(" %d ", arr[i]);
        }
        // printf("| F = %d ",front);
        printf("| HITS = %d", hit);
        printf("\n");
    }
    printf("\n");
    printf("End result: \n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
    return hit;
}

int lru(int s[], int size, int n)
{
    int arr[size], a[size], flag = 1, least = 0, hit = 0;
    for (int i = 0; i < size; i++)
    {
        arr[i] = s[i];
    }
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
    // printf("| LEAST = %d ", least);
    printf("| HITS = %d", hit);
    printf("\n");
    for (int i = size; i < n; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (s[i] == arr[j])
            {
                hit++;
                flag = 0;
                break;
            }
        }
       if (flag)
        {
            int min = a[0];
            for(int j = 0; j < size; j++) {
                if(a[j] < min) {
                    min = a[j];
                    least = j;//stores min index
                }
            }
            arr[least] = a[i];
            a[least] = 0;
        }
        flag = 1;
        for (int i = 0; i < size; i++)
        {
            printf(" %d ", arr[i]);
        }
        //printf("| LEAST = %d ", least);
        printf("| HITS = %d", hit);
        printf("\n");
    }
    printf("\n");
    printf("End result: \n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
    return hit;
}

float ratio(int hit, int n)
{
    float r;
    r = hit / (float)n;
    return r;
}

int main()
{
    int n, h, size, choice;
    int s[100];
    // int s[] = {6, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3};
    // int s[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    float hitr;
    while (1)
    {
        printf("\n1- FIFO\n2- RLU\n3- Exit\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the page size: ");
            scanf("%d", &size);
            printf("\nEnter the number of elements in the sequence: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("\nEnter the %d element: ", i + 1);
                scanf("%d", &s[i]);
            }
            h = fifo(s, size, n);
            hitr = ratio(h, n);
            printf("\nNumber of hits = %d\n", h);
            printf("\nPage hit ratio = %.3f\n", hitr);
            break;
        case 2:
            printf("\nEnter the page size: ");
            scanf("%d", &size);
            printf("\nEnter the number of elements in the sequence: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("\nEnter the %d element: ", i + 1);
                scanf("%d", &s[i]);
            }
            h = lru(s, size, n);
            hitr = ratio(h, n);
            printf("\nNumber of hits = %d\n", h);
            printf("\nPage hit ratio = %.3f\n", hitr);
            break;
        case 3:
            return 0;
        default:
            printf("\nInvalid Operation!");
            break;
        }
    }
    return 0;
}