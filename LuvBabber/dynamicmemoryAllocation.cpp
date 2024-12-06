#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 1. Allocate int -> new humesa address return krwata hai
    // isliye hum usse ptr me store krte hai
    int *ptr = new int(5); //-> iska mtlb mujhe ik address do jo ki [5 -> datatype(yani int)] jessa value store krta hai

    // ! allocation of memory without new keyword
    // here we can use malloc instead of new to dynamically allocate memory
    // But in malloc we have to pass the size of dataType that we want to store
    // And malloc return the void type of pointer that is it says i don't know what type of pointer is address is stored
    // i.e.
    void *mptr = malloc(4);
    // and now you can implicitly type cast it into required datatype
    int *cptr = (int *)mptr;
    *cptr = 10;
    // ? Or you can simply do this like i.e. shorthand property
    int *intPtr = (int *)malloc(4);
    *intPtr = 5;
    cout << "intPrt: " << *intPtr << " " << "ptr: " << *cptr << endl;

    // new k sath delete use hota hai
    // and malloc k sath free use hota hai
    delete ptr;
    delete intPtr;
    delete cptr;
    free(mptr);

    // Dynamic allocation of array
    // 1D allocation array
    int *arrnew = new int[5];
    // without new keyword
    int *arrmalloc = (int *)malloc(5 * sizeof(int));

    // populating the array
    for (int i = 0; i < 5; i++)
    {
        cin >> arrnew[i];
        cin >> arrmalloc[i];
    }

    for (int i = 0; i < 5; i++)
    {
        cout << arrnew[i] << " " << arrmalloc[i] << endl;
    }
    delete arrnew;
    free(arrmalloc);

    // * 2d array allocation
    int rows = 5, cols = 5;
    // ye kuch aisa dikhega
    /**  arr[][]={
         i.e.
         *ptr1->{1,2,3,4,5},
         *ptr2->{1,2,3,4,5},
         *ptr3->{1,2,3,4,5},
         *ptr4->{1,2,3,4,5},
         *ptr5->{1,2,3,4,5}
     }*/
    // And we know pointers ka address double pointer store krta hai
    int **ptr2d = new int *[rows]; // rows allocated hogye hai

    // abb hume columns allocate krwane hai
    for (int i = 0; i < rows; ++i)
    {
        ptr2d[i] = new int[cols];
    }

    //* 2d array allocation without using new keyword
    int **ptr2dmalloc = (int **)malloc(sizeof(int *) * rows);
    // allocating the col to each row
    for (int i = 0; i < rows; ++i)
    {
        ptr2dmalloc[i] = (int *)malloc(sizeof(int) * cols);
    }

    // iterating the 2d array
    // 1. taking input in 2d array
    cout << "Taking input in the 2d array" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> ptr2d[i][j];
            cin >> ptr2dmalloc[i][j];
        }
    }

    // Printing 2d array
    cout << "Printing 2d array using malloc" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << ptr2d[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Printing 2d array using malloc" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << ptr2dmalloc[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocating the columns first then row
    for (int i = 0; i < rows; i++)
    {
        delete[] ptr2d[i];
    }
    delete[] ptr2d;

    for (int i = 0; i < rows; i++)
    {
        free(ptr2dmalloc[i]);
    }
    free(ptr2dmalloc);

    return 0;
}
