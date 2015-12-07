#include<iostream>
#include<string>
#include<stack>
/*
 * 使用stack处理带圆括号的表达式
 * 遇到左括号时，将其标记下来
 * 遇到右括号时，弹出stack对象中这两个括号之间的相关元素，并压入@
 * */
using namespace std;
int main()
{
	stack<char> sexp;
	string exp;
	cout<<"Enter a expression:"<<endl;
	cin>>exp;
	string::iterator iter=exp.begin();
	while(iter!=exp.end())
	{
		if(*iter!=')') sexp.push(*iter);
		else{
			while(sexp.top()!='('&&!sexp.empty())
				sexp.pop();
					if(sexp.empty())
						cout<<"parentheses are not matched"<<endl;
					else{
						sexp.pop();
						sexp.push('@');
					}
		}
		++iter;
	}
	return 0;
}
