#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
bool isShorter(const string &s1,const string &s2)
{
	return s1.size()<s2.size();
}
int main()
{
	vector<string> vec;
	string str;
	while(cin>>str)
		vec.push_back(str);
	sort(vec.begin(),vec.end(),isShorter);
	for(auto it = vec.begin();it!=vec.end();it++)
	{
		cout<<*it<<endl;
	}
	return 0;
}

