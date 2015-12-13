#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<string>
/*
 * 根据形参所指定文件建立单词排除集
 * 将被排除的单词存储在vector对象中，
 * 并从标准输入设备读入文件，对不在排除集的单词进行出现次数统计
 */

using namespace std;
void restricted_wc(ifstream &removeFile,map<string,int>&wordCount)
{
	vector<string> excluded;
	string removeWord;
	while(removeFile >> removeWord)
		excluded.push_back(removeWord);

	cout<<"Enter text(Ctrl+z to end):"<<endl;
	string word;
	while(cin>>word){
		bool find=false;
		vector<string>::iterator iter=excluded.begin();
		while(iter!=excluded.end()){
			if(*iter==word)	{
				find=true;
				break;
			}
			++iter;
		}
		if(!find)
			++wordCount[word];
	}
}

int main()
{
	map<string,int> wordCount;
	string fileName;
	cout<<"Enter fileName :"<<endl;
	cin>>fileName;
	ifstream exFile(fileName.c_str());
	if(!exFile){
		cout<<"error :can not open file:"<<fileName<<endl;
		return -1;
	}
	restricted_wc(exFile,wordCount);
	cout<< "word\t\t"<<"times"<<endl;
	map<string,int>::iterator iter=wordCount.begin();
	while(iter!=wordCount.end()){
		cout<<iter->first<<"\t\t"<<iter->second<<endl;
		iter++;
	}
	return 0;

}

