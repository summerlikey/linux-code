#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int main()
{
	map<string,vector<string>> family{{"joyce",{"haha","hehe"}},{"james",{"heihei","tom","jerry"}}};
	for(auto c: family)
	{
		cout<<"member is : "<<endl;
		for(auto it = c.second.begin();it!=c.second.end();++it)
			cout<<*it<<"."<<c.first<<endl;
		cout<<endl;
	}
	string firstname;
	string personname;
	
	while(cin>>firstname>>personname)
	{
		family[firstname].push_back(personname);
	}

	for(auto c: family)
	{
		cout<<"member is: "<<endl;
		for(auto it = c.second.begin();it != c.second.end();++it)
			cout<<*it<<"."<<c.first<<endl;
		cout<<endl;
	}
	return 0;
}
