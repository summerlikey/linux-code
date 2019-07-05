#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	string s = "asdfaewf2sdf" ;
	char val = '2';
	auto result = find( s.cbegin(), s.cend() , val);
	cout<< "the value "<<val <<(result == s.cend() ? "is not present" : " is present ")<<endl;
	return 0;
}
