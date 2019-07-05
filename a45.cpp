#include <iostream>
int i =42;
int main()
{
	int i =100;
	int j = i;
	std::cout<<j<<std::endl;
	int k = 100,sum = 0;
	for(int k=0;k!=10;++k)
		sum +=k;
	std::cout<< i <<" " <<sum <<std::endl;
	return 0;
}

