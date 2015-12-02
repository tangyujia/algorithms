#include<iostream>
#include<fstream>
#include<string>
#include<vector>
/* 读入一组文件存入vector，
 * 对每一个文件进行处理：
 * 若文件无法读取，则输出警告信息，
 * 否则调用process对文件进行处理*/
using namespace std;
void process(string);
int main()
{
	vector<string> files;
	string filename,s;
	cout<<"Enter filenames :(Ctrl+z to end)"<<endl;
	while(cin>>filename)
		files.push_back(filename);
	ifstream input;
	vector<string>::const_iterator it=files.begin();
	while(it!=files.end()){
		input.open(it->c_str());

		if(!input){
			cerr<<"error:can not open file:"<<*it<<endl;
			input.clear();
			++it;
		}
		else{
			while(input>>s) //读入文件的每一个单词
				process(s);
			input.close();
			input.clear();
			++it;
		}
	}
	return 0;

}
void process(string s)
{
	cout<<s<<endl;
}
