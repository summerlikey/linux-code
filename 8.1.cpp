#include<iostream>
#include<string>
#include<vector>
using namespace std;
istream &readPrint(istream &is);
istream & readPrint(istream & is)
{
	auto old_state = cin.rdstate();
	string i;
	while(!is.eof())
	{
		is>>i;
		cout<<i<<" ";
	}
	cin.setstate(old_state);
	return is;
}
int main()
{
	readPrint(cin);
	system("pause");
	return 0;
}
