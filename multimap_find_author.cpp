#include<iostream>
#include<string>
#include<map>
using namespace std;
/*
 * 建立作者及其作品的multimap容器
 * 以下面的格式按姓名首字母的顺序输出作者及其作品
 * Auther Names Begining with 'A';
 * Auther, book, book,..
 */

int main()
{
	multimap<string,string> authors;
	string author,work,searthItem;
	do{
		cout<<"Enter author name(Ctrl+z to end):"<<endl;
		cin>>author;
		if(!cin)break;
		cout<<"Enter anthor's works(Ctrl+z to end):"<<endl;
		while(cin>>work)
			authors.insert(make_pair(author,work));
		cin.clear();
	}while(cin);

	typedef multimap<string,string>::iterator itType;	
	itType iter=authors.begin();
	if(iter==authors.end()){
		cout<<"empty multimap!"<<endl;
		return 0;
	}
	string currAuthor,preAuthor;
	do{
		currAuthor=iter->first;
		if(preAuthor.empty()||currAuthor[0]!=preAuthor[0])
			cout<<"Author Names Beginning with '"<<iter->first[0]<<" ':"<<endl;
		cout<<currAuthor;
		pair<itType,itType> pos=authors.equal_range(iter->first);
		while(pos.first!=pos.second){
			cout<<", "<<pos.first->second;
			++pos.first;
		}
		cout<<endl;
		iter=pos.second;
		preAuthor=currAuthor;
	}while(iter!=authors.end());
	return 0;

}
