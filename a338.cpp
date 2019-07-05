#include<iostream>
#include <vector>
#include<numeric>
using namespace std;
int main()
{
	vector<int> vec;
	int x;
	while(cin>>x)
		vec.push_back(x);
	int sum = accumulate(vec.cbegin(),vec.cend(),0);
	cout<<sum<<endl;
	return 0;
}
