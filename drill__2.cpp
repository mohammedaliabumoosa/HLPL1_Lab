#include "std_lib_facilities.h"

void swap_v(int a, int b)
{
	
  int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap_r(int& a, int& b)

{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

/*
void swap_cr(const int& a, const int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}


int main()
{
	int x = 7;
	int y = 9;
	swap_r(x, y);
	swap_r(7, 9);
	const int cx = 7;
	const int cy = 9;
	//swap_cr (cx, cy);
	//swap_cr (7, 9); 
	double dx = 7.7;
	double dy = 9.9;
	//swap_cr (dx, dy);
	
  //swap_cr (7.7, 9.9);
	cout << "x= " << x << endl
		<< "y= " << y << endl
		<< "cx= " << cx << endl
		<< "cy= " << cy << endl;
	return 0;
}
