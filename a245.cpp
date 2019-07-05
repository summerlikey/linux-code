#include <iostream>

class Screen{
public:
	void some_member() const;
private:
	mutable size_t access_ctr;
};
void Screen::some_member() const
{
	++access_ctr;
}

int main()
{
	Screen scr;
	scr.some_member();
	return 0;
}
