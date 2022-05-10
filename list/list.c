#include <stdlib.h>
#include "list.h"

dyn_arr create()
{
    dyn_arr arr;
    arr.elements = malloc(sizeof(*arr.elements));
    arr.size = 1;
    arr.capacity = 1;
    return arr;
}

void add(dyn_arr *arr, float element)
{
    insert(arr, element, lenght(arr));
    return;
}

void remove2(dyn_arr *arr, float element)
{
    remove_at(arr, find(arr, element));
    return;
}

void remove_at(dyn_arr *arr, int pos)
{
    for (int i = pos; i < lenght(arr); i++)
    {
        set(arr, *(arr->elements + i + 1), i);
    }
    arr->capacity++;
    trim(arr);
    return;
}

void insert(dyn_arr *arr, float element, int pos)
{
    const int increase = 1;       // if you want to increase more than one element at time
    if (lenght(arr) == arr->size)
    {
        set_capacity(arr, arr->size + increase);
    }
    for (int i = lenght(arr); i > pos; i--)
    {
        set(arr, *(arr->elements + i - 1), i);
    }
    set(arr, element, pos);
    arr->capacity--;
    return;
}

void clear(dyn_arr *arr)
{
    set_capacity(arr, 1);
    arr->size = 1;
    arr->capacity = 1;
    return;
}

void trim(dyn_arr *arr)
{
    set_capacity(arr, arr->size - arr->capacity);
    return;
}

void set_capacity(dyn_arr *arr, int capacity)
{
    arr->elements = realloc(arr->elements, sizeof(*arr->elements) * capacity);
    arr->capacity = capacity - lenght(arr);
    arr->size = capacity;
    
}

int lenght(dyn_arr *arr)
{
    return arr->size - arr->capacity;
}

void set(dyn_arr *arr, float element, int pos)
{
    *(arr->elements + pos) = element;
    return;
}

float get(dyn_arr *arr, int pos)
{
    return *(arr->elements + pos);
}

/*
bugs: if nothing is found it returns 0, if function like detete use this function and the element is not in the array it will delete the first value 0
*/
int find(dyn_arr *arr, float element)
{
    for (int i = 0; i < lenght(arr); i++)
    {
        if (*(arr->elements + i) == element)
        {
            return i;
        }
    }
    return 0;
}