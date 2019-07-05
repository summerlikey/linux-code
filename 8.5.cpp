#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

void read(string s)
{
	string line;
	vector<string> text;
	ifstream in(s);
	while(!in.eof())
	{
		in>>line;
		text.push_back(line);
	}
	for(auto c:text)
	{
		cout<<c<<endl;
	}
}
int main()
{
	read("title8.5.txt");
	system("pause");
	return 0;
} 
