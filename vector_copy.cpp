#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int main()
{
	vector<int> ivec;
	int ival;
	cout<<"Enter numbers:(-1 to end)"<<endl;
	while(ival!=-1)
	{
		ivec.push_back(ival);
		cin>>ival;
	}
	int *pia=new int [ivec.size()];
	int *tp=pia;
	for(vector<int>::iterator iter=ivec.begin();iter!=ivec.end();++iter,++tp)
		*tp=*iter;
	for(int i=1;i<=ivec.size()-1;i++)
		cout<<pia[i]<<" ";
	delete [ ] pia;
	return 0; 
}
