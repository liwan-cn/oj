#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int pd(int a,int b,int c){
    if(a>-1&&c>-1&&a==c&&b==1) return 1;
    else if(a<0||b<1||c<0) return 0;
    else return pd(a,b-1,c-a);
}
int main(){
    char s[1002];
    while(cin>>s){
        int f_z=-1,f_j=-1,f_z_f=0;
        int c_z=0,c_j=0,c_o_1=0,c_o_2=0,c_o_3=0;
        int l = strlen(s);
        int i;
        for(i = 0;i < l;i++){
            if(s[i]!='z'&&s[i]!='o'&&s[i]!='j') break;
            else if(s[i]=='z'){c_z++;f_z=i;}
            else if(s[i]=='j'){c_j++;f_j=i;}
        }
        if(i==l&&c_z==1&&c_j==1&&f_z<f_j) {
            c_o_1 = f_z;
            c_o_2 = f_j-f_z-1;
            c_o_3 = l-f_j-1;
            if (pd(c_o_1,c_o_2,c_o_3))
                cout<<"Accepted"<<endl;
            else cout<<"Wrong Answer"<<endl;
        }
        else cout<<"Wrong Answer"<<endl;
    }
    return 0;
}
