#include <stdlib.h>
#include <stdio.h>

// non l'ho commentato e domani mattina so già che l'avro dimenticato
// è una cazzata ma sono riuscito a scrivere un array dinamico con resize

typedef struct
{
    int *value;
    int size;
    int cap;
} dyn_arr;

void dyn_arr_inc (dyn_arr *arr)
{
    arr->cap += 5;
    arr->value = realloc(arr->value,(arr->cap)* sizeof(int));
    return;
}

void dyn_arr_asg(dyn_arr *arr, int asg)
{
    if (arr->cap < arr->size)
    {
        dyn_arr_inc(arr);
    }
    *(arr->value + arr->size) = asg;
    arr->size++;
    return;
}

int main()
{
    const int start_alloc = 5;
    dyn_arr arr1;
    arr1.value = calloc(start_alloc, sizeof(*arr1.value));
    arr1.size = 0;
    arr1.cap = start_alloc;

    for(int i = 0; i < 13; i++)
    {
        dyn_arr_asg(&arr1, i);
    }
    printf("Size:%d\nCapacity:%d\n",arr1.size,arr1.cap);
    for(int i = 0; i < arr1.size; i++)
    {
        printf("%d\n",*(arr1.value + i));
    }


    return 0;
}