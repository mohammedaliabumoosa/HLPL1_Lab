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
	int x = 10;
	int y = 11;
	swap_r(x, y);
	swap_r(10, 11);
	const int cx = 10;
	const int cy =11;
	//swap_cr (cx, cy);
	//swap_cr (10,11); 
	double dx = 10.0;
	double dy = 11.11;
	//swap_cr (dx, dy);
	
  //swap_cr (10.0, 11.11);
	cout << "x= " << x << endl
		<< "y= " << y << endl
		<< "cx= " << cx << endl
		<< "cy= " << cy << endl;
	return 0;
}
