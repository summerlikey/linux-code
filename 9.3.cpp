#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

bool checkValue(vector<int>::iterator it, vector<int>::iterator it1, int a);

int main()
{
	    vector<int> num{ 1,2,3,4,5,6 };
	        cout << checkValue(num.begin(), num.end(), 7) << endl;
		    system("pause");
		        return 0;
}

bool checkValue(vector<int>::iterator it, vector<int>::iterator it1, int a)
{
	    while (it != it1)
		        {
				        if (*it == a)
						            return true;
					        else
							            ++(it);
						    }
	        return false;
}
