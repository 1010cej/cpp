#include"test.hpp"
using namespace key;
void print_list(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			//(*it) *= 2;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}