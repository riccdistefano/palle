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

void dobug(dyn_arr *arr)
{
    printf("Elements: %d\nSize: %d\nCapacity: %d\n", lenght(arr), arr->size, arr->capacity);
    for (int i = 0; i < lenght(arr); i++)
    {
        printf("Pos: %d Value: %f\n", i, get(arr, i));
    }
    return;
}

int main()
{
    dyn_arr arr1 = create();

    printf("add\n");
    for (int i = 0; i < 5; i++)
    {
        add(&arr1, (float)i);
    }
    dobug(&arr1);

    printf("insert\n");
    insert(&arr1, 43, 2);
    dobug(&arr1);

    printf("set\n");
    set(&arr1, 51, 1);
    dobug(&arr1);

    printf("find\n");
    printf("Pos: %d Num: 51\n", find(&arr1, 51));

    printf("removeat\n");
    remove_at(&arr1, 3);
    dobug(&arr1);

    printf("remove\n");
    remove2(&arr1, 10);
    dobug(&arr1);

    printf("clear\n");
    clear(&arr1);
    dobug(&arr1);
    return 0;
}