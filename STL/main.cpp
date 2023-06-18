#include "test.hpp"
using namespace key; 
int main()
{
    // 测试 1
   list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
        list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			(*it) *= 2;
			cout << *it << " ";
			++it;
		}
		cout << endl;

        cout<<endl;
        // 测试2
        list<int> wt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		for (auto e : wt)
		{
			cout << e << " ";
		}
		cout << endl;

		auto pos = wt.begin();
		++pos;
		lt.insert(pos, 20);

		for (auto e : wt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.push_back(100);
		lt.push_front(1000);

		for (auto e : wt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.pop_back();
		lt.pop_front();

		for (auto e : wt)
		{
			cout << e << " ";
		}
		cout << endl;
        
        cout<<endl;
        
		
}