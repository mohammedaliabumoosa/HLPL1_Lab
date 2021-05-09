#include "Header.h"

ostream& print_array(ostream& os, int* a, int n)
{
    for (int i = 0; i < n; ++i)
        os << a[i] << "  ";
    os << endl;
    return os;
}

ostream& print_vector(ostream& os, vector<int>& v)
{
    for (auto e : v)
        os << e << "  ";
    os << endl;
    return os;
}

int main()
try {
    //1. Allocate an int, initialize it to 7, and assign its address to a variable p1.
    int x = 7;
    int* p1 = &x;

    //2. Print out the value of p1 and of the int it points to.
    cout << p1 << "  " << *p1 << endl;

    //3. Allocate an array of seven ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p2.
    int* array = new int[7];
    x = 1;
    for (int i = 0; i < 7; ++i)
    {
        array[i] = x;
        x *= 2;
    }
    int* p2 = array;

    //4. Print out the value of p2 and of the array it points to.
    cout << p2 << endl;
    print_array(cout, array, 7);

    //5. Declare an int* called p3 and initialize it with p2.
    int* p3 = p2;

    //6. Assign p1 to p2.
    p2 = p1;

    //7. Assign p3 to p2.
    p2 = p3;

    //8. Print out the values of p1 and p2 and of what they point to.
    cout << p1 <<  *p1 << endl;
    cout << p2 <<  *p2 << endl;
    
    //9. Deallocate all the memory you allocated from the free store.
    delete[] array;
    
    //10. Allocate an array of ten ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p1.
    p1 = new int[10]{ 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
    
    //11. Allocate an array of ten ints, and assign its address to a variable p2.
    p2 = new int[10];

    //12. Copy the values from the array pointed to by p1 into the array pointed to by p2.
    for (int i = 0; i < 10; ++i)
        p2[i] = p1[i];
    print_array(cout, p2, 10);
    
    delete p1;
    delete p2;

    //13. Repeat 10¨C12 using a vector rather than an array.
    //13.10. Allocate a vector of ten ints, and assign its address to a variable p2.
    vector<int> v10 = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
    p1 = &v10[0];

    //13.11. Allocate a vector of ten ints, and assign its address to a variable p2.
    vector<int> v11(10);
    p2 = &v11[0];

    //13.12. Copy the values from the vector pointed to by p1 into the vector pointed to by p2.
    v11 = v10;
    print_vector(cout, v11);
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
