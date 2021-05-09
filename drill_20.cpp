#include <iostream>
#include <stdexcept>
#include <array>
#include <vector>
#include <list>
#include <algorithm>

template<typename T>
void print(T& t)
{
    for (auto& e : t)
        std::cout << e << "  ";
    std::cout << std::endl;
}

template<typename T>
void increasing(T& t, int n)
{
    for (auto& e : t)
        e += n;
}

//6. Write a simple copy() operation to further process the data.
template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    for (Iter1 p = f1; p != e1; ++p)
    {
        *f2 = *p;
        f2++;
    }
    return f2;
}

int main()
try {
    //1. Define an array of ints with the ten elements { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }.
    std::array<int, 10> array = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    print(array);

    //2. Define a vector<int> with those ten elements.
    std::vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    print(v);

    //3. Define a list<int> with those ten elements.
    std::list<int> l = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    print(l);
    std::cout << std::endl;

    //4. Define a second array, vector, and list, each initialized as a copy of the first array, vector, and list, respectively.
    std::array<int, 10> array2;
    for (int i = 0; i < 10; ++i)
        array2[i] = array[i];
    std::vector<int> v2 = v;
    std::list<int> l2 = l;
    print(array2);
    print(v2);
    print(l2);
    std::cout << std::endl;

    //5. Increase the value of each element in the array by 2; increase the value of each element in the vector by 3; increase the value of each element in the list by 5.
    increasing(array2, 2);
    increasing(v2, 3);
    increasing(l2, 5);
    print(array2);
    print(v2);
    print(l2);
    std::cout << std::endl;
    
    //7. Use your copy() to copy the array into the vector and to copy the list into the array.
    std::copy(array2.begin(), array2.end(), v2.begin());
    std::copy(l2.begin(), l2.end(), array2.begin());
    print(array2);
    print(v2);
    print(l2);
    std::cout << std::endl;

    //8. Use the standard library find() to perform the required operations.
    std::vector<int>::iterator pvec;
    pvec = std::find(v2.begin(), v2.end(), 3);
    if (pvec != v2.end())
        std::cout << "The value 3 is found in the vector at the position: " << std::distance(v2.begin(), pvec) << std::endl;
    else
        std::cout << "The value 3 is not found in the vector!" << std::endl;

    std::list<int>::iterator lvec;
    lvec = std::find(l2.begin(), l2.end(), 27);
    if (lvec != l2.end())
        std::cout << "The value 27 is found in the list at the position: " << std::distance(l2.begin(), lvec) << std::endl;
    else
        std::cout << "The value 27 is not found in the list!" << std::endl;
    return 0;
}
catch (std::exception& e)
{
    std::cerr << "Exception! " << e.what() << std::endl;
    return 1;
}
catch (...)
{
    std::cerr << "Some exceptions! " << std::endl;
    return 2;
}
