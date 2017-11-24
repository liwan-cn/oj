#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int main(){
	char str[128];
	while(gets(str)){
		string s=str;
		gets(str);
		string a=str;
		gets(str);
		string b=str;
		int pos=s.find(a,0);
		while(pos!=string::npos){
			//cout<<pos<<endl;
			bool flag=false;
			if(pos==0&&s.size()==a.size()) flag=true;
			else if(pos==0&&s[a.size()]==' ') flag=true;
			else if(pos==0) flag=false;
			else if(s[pos-1]==' '&&pos+a.size()==s.size()) flag=true;
			else if(s[pos-1]==' '&&s[pos+a.size()]==' ') flag=true;
			if(flag){
				s.replace(pos,a.size(),b);
				pos=s.find(a,pos+b.size());
			}
			else pos=s.find(a,pos+a.size());
		}
		cout<<s<<endl;
	}
	return 0;
}
