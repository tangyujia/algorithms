#include<iostream>
#include<vector>
#include<list>
using namespace std;
/*判断vector和list的数据是否相同
 * */
int main()
{
	vector<int> ivec;
	list<int> ilst;
	int ival;
	cout<<"Enter some integers for vector(Ctrl+z to end)"<<endl;
	while(cin>>ival)
	ivec.push_back(ival);
	cin.clear(); //使流对象重置为有效状态		
	cout<<"Enter some integers for list(Ctrl+z to end)"<<endl;
	while(cin>>ival)
	ilst.push_back(ival);
	vector<int>::iterator vit=ivec.begin();
	list<int>::iterator lit=ilst.begin();
	while(vit!=ivec.end()&&lit!=ilst.end()){
	if(*vit!=*lit)
	break;
	++vit;
	++lit;
	}
	if(vit==ivec.end()&&lit==ilst.end())
	cout<<"The vector contains the same elements as the list."<<endl;
	else
	cout<<"The vector contains the different elements."<<endl;
	return 0;
}	
