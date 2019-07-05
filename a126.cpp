#include <iostream>

int main()
{
	std::cout<<12/3*4+5*15+24%4/2<<std::endl;
	std::cout<<"give a int number";
	int n=0;
	std::cin>>n;
	if(n%2==0)
	{
		std::cout<<"even"<<std::endl;
	}
	else
		std::cout<<"odd"<<std::endl;
	return 0;
}
