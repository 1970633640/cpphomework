#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef struct x
{
    int lev;
    char data;
    x* child[26];  //一共26个节点，不一定二叉树，孩子数量不确定
    x* parent;  //便于遍历
} x;

typedef struct a //存储数据与层数
{
    char data;
    int lev;
} a;

void print(x* x)
{
    for(int i=0; i<26; i++)
        if(x->child[i]!=NULL)print(x->child[i]);  //递归前序遍历打印树
    printf("%c",x->data);
}

int main()
{
    int i,n;
    scanf("%d\n",&n);
    a a[26];
    if(n==0)return 0;
    for(i=0; i<n-1; i++)scanf("(%d,%c) ",&a[i].lev,&a[i].data); //输入数据
    scanf("(%d,%c)",&a[i].lev,&a[i].data);
    x* head=new x; //建立树根
    head->parent=NULL;
    head->data=a[0].data;
    head->lev=a[0].lev;
    for(int temp=0; temp<26; temp++)head->child[temp]=NULL; //初始化树根子树
    x* p=head;
    int level=a[0].lev;
    for(int k=1; k<n; k++)  //建立子树
    {
        x* t=new x;
        for(int temp=0; temp<26; temp++)t->child[temp]=NULL;
aaa:
        if (a[k].lev>level)
        {
            int pp=0;

            while(p->child[pp]!=NULL)pp++; //使用空的子节点
            t->parent=p;
            t->data=a[k].data;  //建立子树
            t->lev=a[k].lev;
            p->child[pp]=t;
            p=t;
            level=a[k].lev;
        }
        else  //往上回退
        {
            p=p->parent;
            level=p->lev;
            goto aaa; //再开始尝试建立子树
        }

    }
    print(head); //打印
    return 0;
}
