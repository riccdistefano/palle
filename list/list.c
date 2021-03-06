#include <stdlib.h>
#include "list.h"

dyn_arr create()
{
    const int base_capacity = 8;
    dyn_arr arr;
    arr.length = 0;
    arr.capacity = base_capacity;
    arr.elements = malloc(sizeof(*arr.elements) * base_capacity);
    return arr;
}

void add(dyn_arr *arr, float element)
{
    insert(arr, element, arr->length);
}

void remove2(dyn_arr *arr, float element)
{
    remove_at(arr, find(arr, element));
}

void remove_at(dyn_arr *arr, int pos)
{
    if (pos < 0 || pos > arr->length)
        return;

    for (int i = pos; i < arr->length - 1; i++)
    {
        set(arr, arr->elements[i + 1], i);
    }
    arr->length--;
}

void insert(dyn_arr *arr, float element, int pos)
{
    if (arr->length == arr->capacity)
    {
        // Round to the next power of 2
        int new_capacity = arr->capacity;
        new_capacity |= new_capacity >> 1;
        new_capacity |= new_capacity >> 2;
        new_capacity |= new_capacity >> 4;
        new_capacity |= new_capacity >> 8;
        new_capacity |= new_capacity >> 16;
        new_capacity++;

        set_capacity(arr, new_capacity);
    }
    for (int i = arr->length; i > pos; i--) // go get some bitches
    {
        set(arr, arr->elements[i - 1], i);
    }
    set(arr, element, pos);
    arr->length++;
}

void clear(dyn_arr *arr)
{
    set_capacity(arr, 8);
    arr->length = 0;
}

void trim(dyn_arr *arr)
{
    set_capacity(arr, arr->length);
}

void set_capacity(dyn_arr *arr, int capacity)
{
    arr->elements = realloc(arr->elements, sizeof(float) * capacity);
    arr->capacity = capacity;
    if (arr->length > capacity)
    {
        arr->length = capacity;
    }
}

void set(dyn_arr *arr, float element, int pos)
{
    if (pos < 0 || pos > arr->length)
        return;

    arr->elements[pos] = element;
}

float get(dyn_arr *arr, int pos)
{
    if(pos < 0 || pos > arr->length)
        return 0;
        
    return arr->elements[pos];
}

int find(dyn_arr *arr, float element)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->elements[i] == element)
        {
            return i;
        }
    }
    return -1;
}