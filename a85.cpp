#include <iostream>

int main()
{
	const std::string hexdigits = "0123456789ABCDEF";
	std::cout<<"Enter a series of numbers between 0 and 15"<<" separated by spaces.Hit ENTER when finished: "<< std::endl;
	std::string result;//用于保存十六进制的字符串
	std::string::size_type n;//用于保存从输入流读取的数

	while(std::cin>>n)
		if(n<hexdigits.size())//忽略无效输入
			result += hexdigits[n];//对应的十六制数字
	std::cout<<"Your hex number is : "<< result <<std::endl;
	return 0;
}

