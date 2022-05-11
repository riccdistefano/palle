#include <stdio.h>
#include "list.h"

// gcc -c *.c && gcc *.o -o test && ./test

/*
Implement a dynamic list with the following functions:

Add             //Adds an element
Remove          //Removes the first occurrence of an element from the list
RemoveAt        //Removes the element at that index
Insert          //Adds an element at that index
Clear           //Removes all elements
Trim            //The capacity of the array is the array's length
SetCapacity     //Sets the capacity to the specified value
Length          //Returns the number of elements in the list
Set             //Sets an element
Get             //Gets an element
Find            //Returns the index of the specific element
*/

void print(dyn_arr *arr)
{
    printf("Lenght: %d Capacity: %d\n", arr->length, arr->capacity);
    for (int i = 0; i < arr->length; i++)
    {
        printf("Pos: %d Value: %f\n", i, arr->elements[i]);
    }
}

int main()
{
    dyn_arr arr = create();

    add(&arr, 4.3f);
    add(&arr, 12.5f);
    add(&arr, 9.1f);
    print(&arr);

    remove2(&arr, 12.5f);
    print(&arr);

    trim(&arr);
    print(&arr);

    add(&arr, 7.1f);
    print(&arr);

    clear(&arr);
    trim(&arr);
    print(&arr);

    for (int i = 0; i < 10; i++)
    {
        add(&arr, (float)i);
    }
    print(&arr);

    printf("Index: %f\n", get(&arr, find(&arr, 11.0f)));

    remove_at(&arr, -23174291);
    return 0;
}