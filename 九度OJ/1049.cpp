#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main(){
	char str[10000];
	while(gets(str)){
		string s=str;
		
		gets(str);
		char c=str[0];
		int pos=s.find(c,0); 
		while(pos!=string::npos){
			s.erase(pos,1);
			pos=s.find(c,0);
		} 
		//cout<<c<<endl;
		cout<<s<<endl;
	}
	return 0;
}
