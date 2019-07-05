#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void read(string s);

int main()
{
	    read("test.txt");
	        system("pause");
		    return 0;
}

void read(string s)
{
	    string line;
	        vector<string> text;
		    ifstream in(s);
		        while (!in.eof())
				    {
					            getline(in, line);
						            text.push_back(line);
							        }
			    for (auto c : text)
				            cout << c << endl;
}
