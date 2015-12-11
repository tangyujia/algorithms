#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
using namespace std;
/*
 *  定义map对象，其元素的键时家族姓氏
 *  值时vector对象，vector存储pair类型对象，其值是记录每个孩子的姓名和名字
 *  进行基于家族姓氏的查询，输出所有孩子的名字和生日
 * */
int main()
{
	map< string, vector< pair< string ,string > > >children;
	string surname,childrenName,birthday;

	do{
		cout<<"Enter surname (Ctrl+z to end):"<<endl;
		cin>>surname;
		if(!cin)
			break;

		vector<pair < string,string > > chd;
		pair< map< string,vector< pair< string,string > > >::iterator ,bool>ret=children.insert(make_pair(surname,chd));
		if(!ret.second){
			cout<<"repeated surname:"<<surname<<endl;
			continue;
		}

		cout<<"Enter children's name and birthday(Ctrl+z to end):"<<endl;
		while(cin>>childrenName>>birthday){
			ret.first->second.push_back(make_pair(childrenName,birthday));
		}
		cin.clear();
	}while(cin);
	cin.clear();

	cout<<"Enter a surname to search:"<<endl;
	cin>>surname;
	map< string ,vector< pair< string,string> > >::iterator iter;
	iter=children.find(surname);
	if(iter==children.end())
		cout<<"no this surname: "<<surname<<endl;
	else{
		cout<<"children\t\tbirthday"<<endl;
		vector< pair< string,string > >::iterator it=iter->second.begin();
		while(it!=iter->second.end()){
			cout<<it->first <<"\t\t"<<it->second<<endl;
			it++;
		}
	}
	return 0;
}

