#include <iostream>
#include<string>
using namespace std;
int main()
{
	string s = "anc555";
	int i = stoi(s,4,2);
	cout<<i<<endl;
	for(int j = 0;j<5;j++)
		cout<<++i<<endl;

	return 0;
}
