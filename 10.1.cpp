#include<iostream>
#include<string>
#include<vector>
#include <stack>
#include <algorithm>

using namespace std;


int main()
{
	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10,1,2,3,5,6,7,89,6,4,2,3,15,5,6,45 };
	int val = 1;
	auto a_num = count(vec.begin(), vec.end(), val);
	cout << a_num << endl;
	system("pause");
	return 0;
}
