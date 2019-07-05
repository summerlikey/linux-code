#include <iostream>

int fact(int val)
{
	int ret = 1;
	while(val>1)
		ret *= val--;
	return ret;

}
int main()
{
	int x=0;
	std::cout<<"give a number: ";

	std::cin>>x;
	int j = fact(x);
	std::cout<<x<<"! = "<< j<<std::endl;
	return 0;
}
