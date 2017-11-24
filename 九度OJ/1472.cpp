#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main(){
    int l1,l2;
    while(cin>>l1){
        int a[2001]={0};
        int flag=0;
        for(int i = 0;i < l1 ; i++){
            int zs,xs;
            cin>>xs>>zs;
            a[zs+1000] = xs;
        }
        cin>>l2;
            for(int i = 0;i < l2 ; i++){
            int zs,xs;
            cin>>xs>>zs;
            a[zs+1000] += xs;
        }
        for(int i = 2000;i>=0;i--){
            if(a[i]) {
                flag++;
                if(flag>1) cout<<" ";
                cout<<a[i]<<" "<<(i-1000);
            }
        }
        cout<<endl;
    }
    return 0;
}
