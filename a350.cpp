#include<iostream>
using namespace std;
void fcn1()
{
	size_t v1 = 42;
	auto f = [v1] {return v1; };
	v1 = 0;
	auto j = f();
	cout << j;
}
void fcn2()
{
	size_t v1 = 42;
	auto f2 = [&v1] {return v1;};
	v1 = 0;
	auto j = f2();
	cout<<j;
}

int main()
{
	fcn1();
	cout<<endl;
	fcn2();
	cout<<endl;
	return 0;
}

