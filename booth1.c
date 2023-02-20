#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int size;

int binsize(int num)
{
    if (ceil(log2(num)) == floor(log2(num)))
        return (int)log2(num) + 1;
    return (int)log2(num) + 2;
}

void comp(int *arr)
{
    int i;
    for (i = 0; i < size; i++)
    {
        arr[i] = !arr[i];
    }
    int carry = 1;
    for (i = size - 1; i >= 0; i--)
    {
        if (arr[i] == 1 && carry == 1)
        {
            arr[i] = 0;
            carry = 1;
        }
        else if (arr[i] == 0 && carry == 1)
        {
            arr[i] = 1;
            carry = 0;
        }
    }
}

void bin(int number, int *arr)
{
    int i = 0;
    int flag = 0;
    if (number < 0)
    {
        number = number * -1;
        flag = 1;
    }
    while (number > 0)
    {
        arr[size - i - 1] = number % 2;
        number = number / 2;
        i++;
    }
    if (flag)
    {
        comp(arr);
    }
}

void display(int *arr, int number)
{
    printf("\n");
    for (int i = 0; i < number; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int dec(int *a1, int *a2)
{
    int val = 0;
    int k = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        val += a2[i] * pow(2, k++);
    }
    for (int i = size - 1; i >= 0; i--)
    {
        val += a1[i] * pow(2, k++);
    }
    return val;
}

void booths(int *arr1, int *arr2)
{
    int *A = (int *)malloc(size * sizeof(int));
    int *M2s = (int *)malloc(size * sizeof(int));
    memcpy(M2s, arr1, size * sizeof(int));
    comp(M2s);
    int q1 = 0;
    printf("\nA: ");
    display(A, size);
    printf("\nM: ");
    display(arr1, size);
    printf("\nM2s: ");
    display(M2s, size);
    printf("\nQ: ");
    display(arr2, size);
    printf("Q0: %d Q-1: %d\n", arr2[size - 1], q1);
    int k = 1;
    for (int i = 0; i < size; i++)
    {
        printf("\nStep: %d\n", k++);
        if (arr2[size - 1] == 1 && q1 == 0)
        {
            int c = 0;
            for (int j = size - 1; j >= 0; j--)
            {
                A[j] = A[j] + M2s[j] + c;
                if (A[j] > 1)
                {
                    A[j] = A[j] % 2;
                    c = 1;
                }
                else
                {
                    c = 0;
                }
            }
        }
        else if (arr2[size - 1] == 0 && q1 == 1)
        {
            display(A, size);
            display(arr1, size);
            int c = 0;
            for (int j = size - 1; j >= 0; j--)
            {
                A[j] = A[j] + arr1[j] + c;
                if (A[j] > 1)
                {
                    A[j] = A[j] % 2;
                    c = 1;
                }
                else
                {
                    c = 0;
                }
            }
            display(A, size);
        }
        q1 = arr2[size - 1];
        for (int j = size - 1; j > 0; j--)
        {
            arr2[j] = arr2[j - 1];
        }
        arr2[0] = A[size - 1];
        for (int j = size - 1; j > 0; j--)
        {
            A[j] = A[j - 1];
        }
        printf("\nA: ");
        display(A, size);
        printf("\nQ: ");
        display(arr2, size);
        printf("\nM: ");
        display(arr1, size);
        printf("\nM2s: ");
        display(M2s, size);
        printf("Q0: %d Q-1: %d\n", arr2[size - 1], q1);
    }
    printf("\nFinal\nA: ");
    display(A, size);
    printf("\nQ: ");
    display(arr2, size);
    printf("Q0: %d Q-1: %d\n", arr2[size - 1], q1);
    printf("\nFinal result in decimal: %d\n", dec(A, arr2));
}

int main()
{
    int m, q, s1, s2;
    printf("Enter The Multiplicand: ");
    scanf("%d", &m);
    printf("Enter The Multiplier: ");
    scanf("%d", &q);
    s1 = binsize(m);
    s2 = binsize(q);
    if (s1 > s2)
    {
        size = s1;
    }
    else
    {
        size = s2;
    }
    int *arr1 = malloc(size * sizeof(int));
    int *arr2 = malloc(size * sizeof(int));
    bin(m, arr1);
    bin(q, arr2);
    booths(arr1, arr2);
}