#include<iostream>
#include<vector>
#include<string>
/*
 * 寻找句子中的最长的单词和最短的单词
 * 使用find_first_not_of find_first_of 函数
 */
using namespace std;
int main()
{
	string line1="We were her prinde of 10 she named us:";
	string line2="Benjamin,Phoenix the Prodigal";
	string line3="and perspicacious pacific Suzanne";
	string sentence=line1+' '+line2+' '+line3;
	string separators(" \t:,\v\r\n\f");
	string word;
	string::size_type maxLen,minLen,wordLen,count=0;
	vector<string> longestWords,shortestWords;
	string::size_type startPos=0,endPos=0;

	while((startPos=sentence.find_first_not_of(separators,endPos))!=string::npos){
		++count;
		endPos=sentence.find_first_of(separators,startPos);
		if(endPos==string::npos)
			wordLen=sentence.size()-startPos;
		else
			wordLen=endPos-startPos;
		word.assign(sentence.begin()+startPos,sentence.begin()+startPos+wordLen);
		startPos=sentence.find_first_not_of(separators,endPos);
		if(count==1){
			maxLen=minLen=wordLen;
			longestWords.push_back(word);
			shortestWords.push_back(word);
		}
		else{
			if(wordLen>maxLen){
				maxLen=wordLen;
				longestWords.clear();
				longestWords.push_back(word);
			}
			else if(wordLen==maxLen)	
				longestWords.push_back(word);
			if(wordLen<minLen){
				minLen=wordLen;
				shortestWords.clear();
				shortestWords.push_back(word);
			}
			else if(wordLen==minLen)
				shortestWords.push_back(word);
		}
	
	}
	cout<<"word amount :"<<count<<endl;
	vector<string>::iterator iter;

	cout<<"longest word(s):"<<endl;
	iter=longestWords.begin();
	while(iter!=longestWords.end())
		cout<<*iter++<<endl;

	cout<<"shortest word(s):"<<endl;
	iter=shortestWords.begin();				
	while(iter!=shortestWords.end())	
		cout<<*iter++<<endl;
	return 0;
}																
