#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
    map <int,int> data;
    map <int,int>::iterator iter;
typedef struct node
{
    node * left;
    node * right;
    int l,r;
    int value;
    bool same;
} node;

void build(int L,int R,node * root)
{
    int m =(L+R)/2;
    node * p=new node;
    node * q=new node;
    p->left=NULL;
    p->right=NULL;
    q->left=NULL;
    q->right=NULL;
    root->left=p;
    root->right=q;
    p->l=L;
    p->r=m;
    q->l=m+1;
    q->r=R;
    p->same=false;
    q->same=false;
    if(L!=m)build(L,m,p);
    if(m+1!=R)build(m+1,R,p);
}

void qindin(int L,int R,int value,node * root)
{
    int m=(root->l+root->r)/2;
    if(L==root->l && R==root->r){root->same=true;root->value=value;}

    else
    {
       if(L<=m &&root->left!=NULL) qindin(L,m,value,root->left);
        if(R>=m+1&& root->right!=NULL)qindin(m+1,R,value,root->right);
    }
}

void f(int L,int R,node * root)
{

    if(root->same==true)
    {
if(data.find(root->value)==data.end())data[root->value]=min(root->r,R) -max(root->l,L)+1;
else data[root->value]=data[root->value]+min(root->r,R) -max(root->l,L)+1;
return;
    }
else
{
    if(L<=(root->l+root->r)/2 && root->left!=NULL)f(L,R,root->left);
    if(R>=(root->l+root->r)/2+1 && root->right!=NULL  )f(L,R,root->left);
}


}

int main()
{
    int x,y,n,q,templ,tempr,temp;

    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        scanf("%d",&q);
        node * head=new node;
        head->l=1;
        head->r=n;
        head->left=NULL;
        head->right=NULL;
        head->same=false;
        build(1,n,head);
        scanf("%d",&x);
        temp=x;
        templ=1;
        tempr=1;
        for(int i=2; i<=n; ++i)
        {
            scanf("%d",&x);
            if(x==temp)tempr=i;
            else
            {
                qindin(templ,tempr,temp,head);
                templ=i;
                tempr=i;
                temp=x;
            }
        }
        qindin(templ,tempr,temp,head);

        for(int i=0; i<q; ++i)
        { data.clear();
            scanf("%d%d",&x,&y);
            f(x,y,head);
             for(iter=data.begin();iter!=data.end();iter++)
            printf("--%d--%d--\n",iter->first,iter->second);
        }

    }return 0;
}
