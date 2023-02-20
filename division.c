#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int size;

int number(int num)
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

void bin(int num, int *arr)
{
   int i = 0;
   int flag = 0;
   if (num < 0)
   {
       num = num * -1;
       flag = 1;
   }
   while (num > 0)
   {
       arr[size - i - 1] = num % 2;
       num = num / 2;
       i++;
   }
   if (flag)
   {
       comp(arr);
   }
}

void display(int *arr, int num)
{
   printf("\n");
   for (int i = 0; i < num; i++)
   {
       printf("%d", arr[i]);
   }
   printf("\n");
}

void add(int *a, int *b)
{
   int c = 0;
   for (int j = size - 1; j >= 0; j--)
   {
       a[j] = a[j] + b[j] + c;
       if (a[j] > 1)
       {
           a[j] = a[j] % 2;
           c = 1;
       }
       else
       {
           c = 0;
       }
   }
}

void division(int *q, int *m)
{
   int *a = (int *)malloc(size * sizeof(int));   
   int *M2 = (int *)malloc(size * sizeof(int)); 
   memcpy(M2, m, size * sizeof(int));
   comp(M2);
   printf("\nM:");
   display(m, size);
   printf("\nM2s: ");
   display(M2, size);

   printf("\nInitialization: \nA: ");
   display(a, size);
   printf("Q: ");
   display(q, size);
   int *temp = (int *)malloc(size * sizeof(int));
   memcpy(temp, a, size * sizeof(int));
   for (int i = 0; i < size - 1; i++)
   {

       printf("\nProcess %d starts\n", i + 1);
       for (int j = 0; j < size - 1; j++)
       {
           a[j] = a[j + 1];
       }
       a[size - 1] = q[1];
       for (int j = 1; j < size - 1; j++)
       {
           q[j] = q[j + 1];
       }
       printf("After Shift: \nA: ");
       display(a, size);
       printf("Q: ");
       display(q, size);
       memcpy(temp, a, size * sizeof(int));
       add(a, M2);
       printf("After A-M: \nA: ");
       display(a, size);
       if (a[0] == 0)
           q[size - 1] = 1;

       else if (a[0] == 1)
       {
           q[size - 1] = 0;
           memcpy(a, temp, size * sizeof(int));
       }
       printf("\nProcess %d completed: \nA: ", i + 1);
       display(a, size);
       printf("\nQ:");
       display(q, size);
   }
}

int main()
{
   printf("Dividend: ");
   int dividend;
   scanf("%d", &dividend);
   printf("Divisor: ");
   int divisor;
   scanf("%d", &divisor);
   int s1 = number(dividend);
   int s2 = number(divisor);
   if(s1>s2)
   {
    size = s1;
   }
   else
   {
    size = s2;
   }
   int *a = (int *)malloc(size * sizeof(int));
   int *b = (int *)malloc(size * sizeof(int));
   bin(dividend, a);
   bin(divisor, b);
   printf("\nDividend: ");
   display(a, size);
   printf("\nDivisor: ");
   display(b, size);
   division(a, b);
   return 0;
}