#include "stdio.h"
#include "string.h"

struct elem
{
    int value;
    int index;
};
 
int cmp(const void *vp1, const void *vp2)
{
    return (*(struct elem*)vp1).value - (*(struct elem*)vp2).value;
}

int* twoSum(int* nums, int numsSize, int target) {
    struct elem *list = (struct elem*)malloc(numsSize * sizeof(struct elem));
    memset(list, '\0', numsSize * sizeof(struct elem));
    int *result = (int*)malloc(sizeof(int)*2);
    int i=0;
    for(; i<numsSize; i++)
    {
        list[i].value = nums[i];
        list[i].index = i + 1;
    }
    
    qsort(list, numsSize, sizeof(struct elem), cmp);
    
    struct elem *first = list, *last = list+numsSize-1;
    while(first < last)
    {
        if(first->value + last->value > target)
            --last;
        else if(first->value + last->value < target)
            ++first;
        else
        {
            result[0] = first->index < last->index ? first->index:last->index ;
            result[1] = first->index > last->index ? first->index:last->index ;
            free(list);
            return result;
        }
    }
    
    free(list);
    return NULL;
}

int main()
{
    int a[100] = {100};
    int len = 0;
    while(scanf("%d", &a[len]))
    {
        if(a[len] == -999)
            break;
        len++;
    }

    int *result = twoSum(a, len, 10);
    if(result != NULL)
        printf("%d %d\n", result[0], result[1]);
    else
        printf("no found!!\n");

    return 0;
}

