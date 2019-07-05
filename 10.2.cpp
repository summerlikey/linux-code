#include <iostream>
#include <algorithm>
#include <list>
#include <string>
using namespace std;

int main()
{
	list<string> vec;
	string word;
	while(cin>>word)
		vec.push_back(word);
	string val = "123";
	auto a_num = count(vec.begin(),vec.end(),val);
	cout<< a_num<<endl;
	return 0;
}
