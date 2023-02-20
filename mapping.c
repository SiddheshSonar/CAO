#include <stdio.h>
#include <math.h>

void Display (int page, int line, int word)
{
    printf("\nPage Size = %d", page);
    printf("\nLine Size = %d", line);
    printf("\nWord Size = %d", word);
    printf("\nTotal = %d\n", page+line+word);
}

void Direct (int mem, int cache, int block)
{
    int page, line, word;
    page = (int) log2((pow(2,30)*mem)/(pow(2,10)*cache));
    line = (int) log2((pow(2,10)*cache)/block);
    word = (int) log2(block);
    Display(page, line, word);
}

void Nway (int mem, int cache, int block, int n)
{
    int page, line, word;
    cache = cache/n;
    page = (int) log2((pow(2,30)*mem)/(pow(2,10)*cache));
    line = (int) log2((pow(2,10)*cache)/block);
    word = (int) log2(block);
    Display(page, line, word);
}

int main()
{
    int mem, cache, block, n, op;
    while(1)
    {
        printf("\n1: Direct Mapping\n2: n-way Mapping\n3: Exit\nEnter the operation you want to perform = ");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            printf("\nEnter the memory size in GB: ");
            scanf("%d",&mem);
            printf("\nEnter the cache size in KB: ");
            scanf("%d",&cache);
            printf("\nEnter the block size: ");
            scanf("%d",&block);
            Direct(mem, cache, block);           
            break;
        case 2:
            printf("\nEnter the memory size in GB: ");
            scanf("%d",&mem);
            printf("\nEnter the cache size in KB: ");
            scanf("%d",&cache);
            printf("\nEnter the block size: ");
            scanf("%d",&block);
            printf("\nEnter the value of n: ");
            scanf("%d",&n);
            Nway(mem, cache, block, n);
            break;
        case 3:
            return 0;
        default:
            printf("\nInvalid Operation!\n");
            break;
        }
    }
    return 0;
}