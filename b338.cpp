#include <iostream>
#include <numeric>
#include <vector>
#include <string>
using namespace std;
int main()
{
	vector<string> vec;
	string str;
	while(cin>>str)
		vec.push_back(str);
	string sum = accumulate(vec.cbegin(),vec.cend(),string(""));
	//将空串串当做一个字符串传递给第三个值不可以会有错误，原因是如果字面值则保存的类型是const char× 
	//该类型没有+运算符
	//string sum = accumulate(vec.cbegin(),vec.cend(),"");
	cout<<sum<<endl;
	return 0;
}
