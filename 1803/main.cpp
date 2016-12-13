#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef struct Node  //定义链表数据结构
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
    Node * head=(Node*)malloc(sizeof(Node)); //建立链表头
    head->next=0;
    head->x=0;
    n=head;
    Node * p;
    for(i=0; i<x; i++)
    {
        cin>>key;
        p=(Node*)malloc(sizeof(Node));  //插入初始链表内容
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
        while( (n->x) !=key)n=n->next;  //查找插入位置
        temp=n->next;
        p=(Node*)malloc(sizeof(Node));  //新建结构体
        p->x=key2;
        n->next=p;
        p->next=temp;
        n=head->next;
        while( 1)
        {
            if(n->next!=0)cout<<n->x<<" "; //打印链表内容
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
