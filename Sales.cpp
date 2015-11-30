#include<iostream>
#include"Sales_item.hpp"
using namespace std;
int main()
{
	Sales_item item;
	cout<<"Enter some transactions(Ctrl+z to end)"<<endl;
	while(item.input(cin))
	{
		cout<<"The transaction readed is:"<<endl;
		item.output(cout);
		cout<<endl;
	}
	return 0;
}
