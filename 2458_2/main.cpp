#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

typedef struct node
{
    node * left;
    node * right;
    int l,r;
} node;
int data[100002];

void build (int L,int R,node * root)
{
    int M=(L+R)/2;
    if(L!=R)
    {
        node * p=new node;
        p->left=NULL;
        p->right=NULL;
        p->l=data[L-1]+1;
        p->r=data[(L+R)/2];
        root->left=p;

        node * q=new node;
        q->left=NULL;
        q->right=NULL;
        q->l=data[(L+R)/2]+1;
        q->r=data[R];
        root->right=q;
        // printf("build %d %d %d %d\n",data[L-1]+1,data[(L+R)/2],data[(L+R)/2]+1,data[R]);
        build(L,M,p);
        build(M+1,R,q);
    }
    else
    {
        root->l=data[L-1]+1;
        root->r=data[R];
        // printf("haha %d %d\n",data[L-1]+1,data[R]);
    }
}

int f(int L,int R,node * root)
{
    if(root->left==NULL)
    {
        return min(root->r,R)-max(root->l,L)+1;
    }
    else
    {
        if(L<=(root->left)->r  &&  R>=(root->right)->l  )return max(f(L,R,root->left),f(L,R,root->right));
        else if (L<=(root->left)->r    )return f(L,R,root->left);
        else if (R>=(root->right)->l  )return f(L,R,root->right);
        else printf("angry!\n");
    }
}

void del(node * root)
{
    if(root->left!=NULL)del(root->left);
    if(root->right!=NULL)del(root->right);
    delete root;
}
int main()
{
    int x,y,n,q,tempr,temp;

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
        scanf("%d",&x);
        temp=x;
        tempr=1;
        data[0]=0;
        int c=1;
        for(int i=2; i<=n; ++i)
        {
            scanf("%d",&x);
            if(x==temp)tempr=i;
            else
            {
                data[c++]=tempr;
                tempr=i;
                temp=x;
            }
        }
        data[c]=tempr;
        build(1,c,head);
        for(int i=0; i<q; ++i)
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",f(x,y,head));
        }
    //    del(head);
    }

    return 0;
}
