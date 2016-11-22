#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct node
{
    bool same,lit;
    int l,r;
    node * left;
    node * right;
} node;

node* head;
void build(int L,int R,node * root)
{
    printf("build L=%d R=%d l=%d r=%d\n",L,R,root->l,root->r);
    int M=(L+R)/2;
    node * p=new node;
    node * q=new node;
    root->left=p;
    root->right=q;
    p->l=L;
    p->r=M;
    q->l=M+1;
    q->r=R;
    p->same=true;
    q->same=true;
    p->left=NULL;
    p->right=NULL;
    q->left=NULL;
    q->right=NULL;
    p->lit=false;
    q->lit=false;
    if(L!=R)
    {
        build(L,M,p);
        build(M+1,R,q);
    }
}
void repair (node * root)
{
    if (root->left!=NULL)
    {
        (root->left)->lit=root->lit;
        (root->left)->same=true;
        (root->right)->lit=root->lit;
        (root->right)->same=true;
        root->same=false;
    }
    else cout<<"repair error!\n";
}
void change(int L,int R,node * root)
{

   if(L>R || R<root->l || L>root->r)return;
   if(L<root->l)L=root->l; if(R>root->r)R=root->r;
       printf("change L=%d R=%d rootl=%d r=%d\n",L,R,root->l,root->r);
    int mid=(root->l+root->r)/2;
    if(root->l==root->r)root->lit=!(root->lit);
    else
    {
        if (root->same)
        {
            if(L==root->l && R==root->r)root->lit=!(root->lit);
            else
            {
                repair(root);
                change(L,R,root);
            }
        }
        else
        {
            if (L<=mid && R>=mid+1 )
            {
                change(L,mid,root->left);
                change(mid+1,R,root->right);
            }
            else if (L>mid && R>=mid+1)
            {
                change(L,R,root->right);
            }
            else if (L<=mid && R<mid+1)
            {
                change(L,R,root->left);
            }
            else cout<<"naive!";
        }
    }
}

int  count(int L,int R,node * root)
{   if(L>R || R<root->l || L>root->r)return 0;
   if(L<root->l)L=root->l; if(R>root->r)R=root->r;
    printf("L=%d R=%d l=%d r=%d\n",L,R,root->l,root->r);
    int mid=(root->l+root->r)/2;
    if(L==R)return root->lit;
    else if (root->same==true)
    {
        if (L>=root->l && R<=root->r)return (R-L+1)*(int)(root->lit);
        else
        {
            cout<<"count error!\n";
            return 0;
        }

    }
    else if(root->left!=NULL)
    {
        if(L<=mid && R>=mid+1)return count(L,mid,root->left)+count(mid+1,R,root->right);
        else if(L<=mid && R<mid+1)return count(L,R,root->left);
        else if(L>mid && R>=mid+1)return count(L,R,root->right);
        else
        {
            cout<<"damn!\n";
            return 0;
        }
    }
    else
    {
        cout<<"empty!?\n";
        return root->lit;
    }

}


int main()
{
    int N,M,operation,s,e;
    scanf("%d%d",&N,&M);
    head=new node;
    head->l=1;
    head->same=true;
    head->lit=false;
    head->r=N;
    head->left=NULL;
    head->right=NULL;
    build(1,(1+N)/2,head);
    build((1+N)/2+1,N,head);
    for(int i=0; i<M; i++)
    {
        scanf("%d%d%d",&operation,&s,&e);
        if (!operation)change(s,e,head);
        else
        {

            cout<<count(s,e,head)<<endl;
        }

    }



    return 0;
}
