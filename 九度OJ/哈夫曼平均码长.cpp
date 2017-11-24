#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <algorithm>
using namespace std;

int num1 = 0;
double sum = 0;

typedef struct BiTNode
{
    double data;
    struct BiTNode *lchild,*rchild;//左右孩纸指针
}BiTNode,*BiTree;

bool cmp(BiTree T1,BiTree T2){
    return (T1->data > T2->data);
}
void Traerse(BiTree &T,int n)
{
    if(T)
    {
        if(T->lchild==NULL&&T->rchild==NULL){
            num1++;
            sum = sum + (n*T->data);
            cout<<"节点权重："<<T->data<<";路径长度："<<n<<endl;
        }
        Traerse(T->lchild,n+1);
        Traerse(T->rchild,n+1);
    }
}

int main(){
    int num=0;
    BiTree temp;
    BiTree b[100];
    cin>>num;
    for(int i = 0;i < num;i++){
        b[i] = (BiTree)malloc(sizeof(BiTNode));
        b[i]->lchild = NULL;
        b[i]->rchild = NULL;
        cin>>b[i]->data;
    }
    sort(b,b+num,cmp);
 /*   for(int i = 1;i < num;i++)
    for(int j = 0;j < num-i;j++){
        if(b[j]->data < b[j+1]->data)
        {temp=b[j];b[j]=b[j+1];b[j+1]=temp;}
    }*/
    while(num > 1){
        temp  = b[num-2];
        b[num-2] = (BiTree)malloc(sizeof(BiTNode));
        b[num-2]->data = temp->data + b[num-1]->data;
        b[num-2]->lchild = temp;
        b[num-2]->rchild =  b[num-1];
        num--;
        for(int j = num-1;j >= 1;j--){

            if(b[j]->data > b[j-1]->data)
            {temp=b[j];b[j]=b[j-1];b[j-1]=temp;}
            else break;
        }
    }
    cout<<endl;
    Traerse(b[0],0);
    cout<<endl;
    cout<<"叶节点个数："<<num1<<endl;
    cout<<"带权路径长度："<<sum<<endl;
    return 0;
}
