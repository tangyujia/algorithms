#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
/*
 * 定义一个vector容器。存储在未来六个月里要读的书籍
 * 定义一个set用来记录已经看过的书籍
 * 本程序支持从vector中选择一本没有读过而现在要读的书
 * 并将书名放入已读数目的set中并删除该书记录
 * 虚拟6个月后输出已读的和没有读的书目
 */
int main()
{
	vector<string> books;
	set<string> readedBooks;
	string name;
	cout<<"Enter names for books you'd like to read （Ctrl+z to end)"<<endl;
	while(cin>>name)
		books.push_back(name);
	cin.clear();
	bool timeOver=false;
	string answer,bookName;
	srand((unsigned)time(NULL));
	while(!timeOver&&!books.empty()){
		cout<<"Would you like to read a book?(yes/no)"<<endl;
		cin>>answer;
		if(answer[0]=='y'||answer[0]=='y'){
			int i=rand()%books.size();
			bookName=books[i];
			cout<<"you can read this book:"<<bookName<<endl;
			readedBooks.insert(bookName);
			books.erase(books.begin()+i);
			cout<<"Did you read it?(yes/no)"<<endl;
			cin>>answer;
			if(answer[0]=='n'||answer[0]=='N' ){
				readedBooks.erase(bookName);
				books.push_back(bookName);
			}
		}
		cout<<"Time over?(yes/no)"<<endl;
		cin>>answer;
		if(answer[0]=='y'||answer[0]=='Y')
			timeOver=true;
	}
	if(timeOver){
		cout<<"books read:"<<endl;
		for(set<string>::iterator sit=readedBooks.begin();sit!=readedBooks.end();++sit)
			cout<<*sit<<endl;
		cout<<"books not read:"<<endl;
		for(vector<string>::iterator vit=books.begin();vit!=books.end();++vit)
			cout<<*vit<<endl;
	}
	else
		cout<<"Congratulations !You have read all these books."<<endl;
	return 0;
}
