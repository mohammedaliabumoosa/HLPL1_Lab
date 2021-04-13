#include "Header.h"

namespace X
{
	int var {0};
	void print()
	{
		cout << "X's var = " << var << endl;
	}
}

namespace Y
{
	int var {0};
	void print()
	{
		cout << "Y's var = " << var << endl;
	}
}

namespace Z
{
	int var {0};
	void print()
	{
		cout << "Z's var = " << var << endl;
	}
  {

int main()
{
	X::var = 10;
	X::print();
	using namespace Y;
	var = 11;
	print();
	{
		using Z::var;
		using Z::print;
		var = 11;
		print();
	}
	print();
	X::print();
}
