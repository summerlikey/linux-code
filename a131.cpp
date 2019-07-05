#include <iostream>
int main()
{
	int i=0,j;
	j=++i;
	std::cout<<j<<" "<<i<<std::endl;
	j=i++;
	std::cout<<j<<" "<<i<<std::endl;
	return 0;
}
