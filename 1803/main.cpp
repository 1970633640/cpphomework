#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef struct Node
{
    int x;
    Node* next;
} Node;

int main()
{
    int x,i,key,key2;
    cin>>x;
    Node * n;
    Node * temp;
    Node * head=(Node*)malloc(sizeof(Node));
    head->next=0;
    head->x=0;
    n=head;
    Node * p;
    for(i=0; i<x; i++)
    {
        cin>>key;
        p=(Node*)malloc(sizeof(Node));
        p->x=key;
        n->next=p;
        p->next=0;
        n=p;
    }
    cin>>x;
    for(i=0; i<x; i++)
    {
        cin>>key;
        cin>>key2;
        n=head;
        while( (n->x) !=key)n=n->next;
        temp=n->next;
        p=(Node*)malloc(sizeof(Node));
        p->x=key2;
        n->next=p;
        p->next=temp;
        n=head->next;
        while( 1)
        {
            if(n->next!=0)cout<<n->x<<" ";
            else
            {
                cout<<n->x<<endl;
                break;
            }
            n=n->next;
        }
    }
    return 0;
}
