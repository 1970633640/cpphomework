#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct node
{
    int same;
    int l,r;
    node * left;
    node * right;
    int sum;
} node;

void build(int L,int R,node * root)
{
    //printf("build %d %d\n",L,R);
    int M=(L+R)/2;
    if(L==R)
    {
        root->l=L,root->r=R;
        root->same=0;
        root->sum=0;
        return;
    }
    else
    {
        node * p=new node;
        node * q=new node;
        root->left=p;
        root->right=q;
        p->left=NULL;
        p->right=NULL;
        q->left=NULL;
        q->right=NULL;
        p->l=L;
        p->r=M;
        q->l=M+1;
        q->r=R;
        p->same=0;
        q->same=0;
        p->sum=0;
        q->sum=0;
        build(L,M,p);
        build(M+1,R,q);
    }
}
void fast(node * root)
{
    root->sum=(root->left)->sum+(root->right)->sum;
}
void repair (node * root)
{
    if(root->same!=0)
    {
        (root->left)->same+=root->same;
        (root->right)->same+=root->same;
        if( (root->same % 2)!=0)
        {
            (root->left)->sum= (root->left)->r- (root->left)->l+1- (root->left)->sum;
            (root->right)->sum= (root->right)->r- (root->right)->l+1- (root->right)->sum;
        }
        root->same=0;
    }
}

void change(int L,int R,node * root)
{
    int M=(root->l+root->r)/2;
    if(L<=root->l && R>=root->r)
    {
        root->sum=root->r-root->l+1-root->sum;
        ++(root->same);
    }
    else
    {
        repair(root);
        if(L<=M)change(L,R,root->left);
        if(R>=M+1)change(L,R,root->right);
        fast(root);
    }
}

int count(int L,int R,node * root)
{
    int M=(root->l+root->r)/2;
    // printf("count %d %d\n",root->l,root->r);
    if(L<=root->l && R>=root->r)
    {
        return root->sum;
    }
    else
    {
        repair(root);
        if(L>M)return count(L,R,root->right);
        else if(R<M+1)return count(L,R,root->left);
        else return count(L,R,root->right)+count(L,R,root->left);
    }
}

int main()
{
    int N,M,operation,s,e;
    scanf("%d%d",&N,&M);
    node * head=new node;
    head->left=NULL;
    head->right=NULL;
    head->l=1;
    head->r=N;
    head->sum=0;
    head->same=0;
    build(1,N,head);
    while(M--)
    {
        scanf("%d%d%d",&operation,&s,&e);
        if (!operation)change(s,e,head);
        else printf("%d\n",count(s,e,head));
    }
    return 0;
}
