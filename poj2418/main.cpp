#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;
int sum=0;
typedef struct node
{
    string value;
    int times;
    node * left;
    node * right;
} node;
void insertnode(node * x,string t)
{
    while(1)
    {
        if(x->left!=NULL && t<x->value)x=x->left;
        else if(x->right!=NULL && t>x->value)x=x->right;
        else if  (x->left==NULL && t<x->value)
        {
            node *p=new node;
            p->value=t;
            p->left=NULL;
            p->right=NULL;
            p->times=1;
            x->left=p;
            return;
        }
        else if  (x->right==NULL && t>x->value)
        {
            node *p=new node;
            p->value=t;
            p->left=NULL;
            p->right=NULL;
            p->times=1;
            x->right=p;
            return;
        }
        else if( t==x->value)
        {
           ++ x->times;return;
        }

            else
        {
            cout<<"unknown error!!!!\n";
            break;
        }
    }
}
void print(node * x)

{std::ios::sync_with_stdio(false);
    if(x)
    {
        print(x->left);
cout<<x->value<<" "<<setiosflags(ios::fixed)<<setprecision(4) <<(double)x->times/(double)sum*100.0<<endl;
    print(x->right);
    }
}
int main()
{
std::ios::sync_with_stdio(false);
   string t;
    getline(cin,t);
    sum=1;
    node * x=new node;
    x->value=t;
    x->left=NULL;
    x->right=NULL;
    x->times=1;
while(getline(cin,t))
    {++sum;
        insertnode(x,t);
    }
    print(x);
    return 0;
}
