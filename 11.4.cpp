#include<iostream>
#include<map>

using namespace std;

string makelower(const string &s)
{
	string temp(s);
	for(int i =0 ;i<s.size();++i)
		temp[i] = tolower(s[i]);
	return temp;
}
//去除标点符号


string removePunct(const string &s)
{
	string temp;
	for(string::size_type i = 0;i<s.size();++i)
		if(!ispunct(s[i]))
			temp += s[i];
	return temp;

}
int main()
{
	map<string,size_t> word_count;
	string word,word_low,word_nopunct;
	while(cin>>word)
	{
		word_nopunct = removePunct(word);
		word_low = makelower(word_nopunct);
		++word_count[word_low];
	}
	for(const auto &w:word_count)
		cout<<"\""<<w.first<<"\"occurs: "<<w.second<<((w.second>1)?"times":" time")<<endl;
	return 0;
}
