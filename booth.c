#include <stdio.h>
#include <math.h>

void binary(int a[], int num)
{
    int i, temp, size = (int)log2(num);
    for (i = 0; num > 0; i++)
    {
        a[i] = num % 2;
        num = num / 2;
    }
    for (int i = 0; i < size / 2; i++)
    {
        temp = a[i];
        a[i] = a[(size - 1) - i];
        a[(size - 1) - i] = temp;
    }
}

int main()
{
    int a = 0, q1 , md, mr, s1, s2, size;
    int m[100], q[100];
    printf("Enter the Multiplicand: \n");
    scanf("%d", &md);
    s1 = (int)log2(md) + 1;
    printf("Enter the Multiplier: \n");
    scanf("%d", &mr);
    s2 = (int)log2(mr) + 1;
    printf("%d\n", s1);
    printf("%d\n", s2);
    if (s1 >= s2)
    {
        size = s1;
    }
    else
    {
        size = s2;
    }
    binary(m, md);
    binary(q, mr);
    // for (int i = 0; i < s1; i++)
    // {
    //     printf("%d", m[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < s2; i++)
    // {
    //     printf("%d", q[i]);
    // }
    while (size != 0)
    {
        if (q[s1 - 1] == 1 && q1 == 0)
        {
        }
        else if (q[s1 - 1] == 0 && q1 == 1)
        {
        }
        else
        {
        }
    }
    return 0;
}
