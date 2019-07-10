#include<string>
#include<map>
#include<iostream>
#include<set>
#include<fstream>
using namespace std;

int main()
{
	ifstream in("title.txt");
	string str;
	map<string,size_t> word_count;
	set<string>exclude{"a","an"};
	while(in>>str)
	{
		if(exclude.find(str) == exclude.end())
			++word_count[str];
	}
	for(const auto &w: word_count)
	{
		cout<<w.first<<" occurs "<<w.second<<((w.second > 1) ? "times" : "time") <<endl;
	}
	return 0;
}
