#include "Header.h"


//Question 4:
//function to print array of size 10
 print_array10(ostream& os, int* a) {
   for(int i=0; i<10; ++i)
     os << a[i] << ' ';
    os << endl;
 }

//Question 7:
//function to print array of size = n
print_array(ostream& os, int* a, int n) {
  for (int i = 0; i<n; ++i)
    os << a[i] << ' ';
  os << endl;
}

//Question 10: Use vectors instead of arrays
void print_vector(ostream& os, vector<int> v) {
  for(int i = 0; i<v.size(); ++i)
    os << v[i] << ' ';
}


int main()
try {
//Question 1: allocate array of 10 ints

  int* a = new int[10];
  for(int i = 0; i<10; ++i)
    a[i]=i;


//Question 2: print 10 ints of array

cout << "Question - 2" << endl;
  for(int i=0; i<10; ++i)
    cout << a[i] << ' ';

//  print_array10(cout, a); (question 4!)

    cout << endl;

//question 3: deallocate array

  delete[] a;

// Question 5: initialize 100..101..102
cout << "\nQuestion - 5" << endl;
  int* b = new int[10];
  for(int i = 0; i<10; ++i)
    b[i] = 100 + i;
  print_array10(cout, b); // question 4
  delete[] b;

//Question 6: allocate 11 ints!

cout << "\nQuestion - 6" << endl;
  int* c = new int[11];
  for(int i = 0; i<11; ++i)
    c[i]=100+i;
  print_array(cout, c, 11); //Question 7
  delete[] c;

//Question 8 : allocate array of 20 ints!
cout << "\nQuestion - 8" <<endl;
  int* d = new int[20];
  for(int i = 0; i<20; ++i)
    d[i] = 100 + i;
  print_array(cout, d, 20);

  delete[] d;

//Question 10: use vectors instead of arrays!

cout << "\nQuestion - 10" << endl;
vector<int> v5;
for(int i = 0; i<10; ++i) {
  v5.push_back(100+i);
};
print_vector(cout, v5);
cout << endl;

vector<int> v6;
for(int i = 0; i<11; ++i) {
  v6.push_back(100+i);
};
print_vector(cout, v6);
cout << endl;

vector<int> v8;
for(int i = 0; i<20; ++i) {
  v8.push_back(100+i);
};
print_vector(cout, v8);
cout << endl;

//PART 2 OF DRILL 17 !!

cout << "\n---PART 2 ! ---" << endl;

//Question 1: assign int to 7

int x1 = 7;
int* p1 = &x1;


//Question 2: print p1

cout << "\nQuestion - 2" << endl;
cout << "p1: " << p1 << endl;
cout << "*p1: " << *p1 << endl;

//Question 3: allocate 7 ints like 1,2,4,8

int* p2 = new int[7];
for(int i = 0; i<7; ++i)
  p2[i] = pow(2,i);


//Question 4: print array and what it points to

cout << "\nQuestion - 4" << endl;
print_array(cout, p2, 7);

//Question 5: delete p3 and initialize p2

int* p3 = p2;

//Question 6 assign p1 to p2

  p2 = p1;
//Question 7 : assign p3 to p2

  p2 = p3;

//Question 8: print p1,p2 and what they point to


cout << "\nQuestion - 8" << endl;
cout << "p1: " << p1 << endl;
cout << "*p1: " << *p1 << endl;
cout << "p2: " << p2 << endl;
cout << "*p2:" << *p2 << endl;


//Question 9 : deallocate all memory

delete[] p2;


//Question 10: allocate array of 10 ints like 2,4,8 then assign address to p1


p1 = new int[10];
for(int i = 0; i<10; ++i) {
  p1[i] = pow(2,i);
};


//Question 11: allo 10 ints then assign adress to p2


p2 = new int[10];
//Question 12: copy array p1 into p2

cout << "\nQuestion - 12" << endl;
for(int i = 0; i<10; ++i)
  p2[i] = p1[i];
print_array(cout, p2, 10);


//Question 13:
cout << "\nQuestion - 13" << endl;
vector<int> vec1;
for(int i = 0; i<10; ++i)
  vec1.push_back(pow(2,i));
vector<int> vec2;
for(int i = 0; i<vec1.size(); ++i)
  vec2.push_back(vec1[i]);
print_vector(cout,vec2);

  return 0;
}
catch (exception& e) {
  cerr << e.what() << endl;
}
