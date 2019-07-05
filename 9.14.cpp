#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

int main()
{
	    vector<char *> li{ "132", "34", "asd", "da" };
	        vector<string> str;
		    str.assign(li.begin(), li.end());
		        for (auto c : str)
				        cout << c << endl;
			    system("pause");
			        return 0;
}
