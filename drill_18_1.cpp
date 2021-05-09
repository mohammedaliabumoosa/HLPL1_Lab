#include "Header.h"

//1. Define a global int array ga of ten ints initialized to 1, 2, 4, 8, 16, etc.
int ga[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

//2. Define a function f() taking an int array argument and an int argument indicating the number of elements in the array.
void f(int a[], int n)
{
    //3.a. Define a local int array la of ten ints.
    int la[10];

    //3.b. Copy the values from ga into la.
    for (int i = 0; i < n; ++i)
        la[i] = a[i];

    //3.c. Print out the elements of la.
    for (int i = 0; i < n; ++i)
        cout << la[i] << "  ";
    cout << endl;

    //3.d. Define a pointer p to int and initialize it with an array allocated on the free store with the same number of elements as the argument array.
    int* p = new int[n];

    //3.e. Copy the values from the argument array into the free-store array.
    for (int i = 0; i < n; ++i)
        p[i] = a[i];

    //3.f. Print out the elements of the free-store array.
    for (int i = 0; i < n; ++i)
        cout << p[i] << "  ";
    cout << endl;

    //3.g. Deallocate the free-store array.
    delete[] p;
}

int main()
try {
    //4.a. Call f() with ga as its argument.
    f(ga, 10);

    //5.b. Define an array aa with ten elements, and initialize it with the first ten factorial values (1, 2 * 1, 3 * 2 * 1, 4 * 3 * 2 * 1, etc.).
    int aa[10];
    int temp = 1;
    for (int i = 0; i < 10; ++i)
    {
        temp *= (i + 1);
        aa[i] = temp;
    }

    //4.c. Call f() with aa as its argument.
    f(aa, 10);
    return 0;
}
catch (exception& e)
{
    cerr << "Exception! " << e.what() << endl;
    return 1;
}
catch (...)
{
    cerr << "Some exceptions! " << endl;
    return 2;
}
