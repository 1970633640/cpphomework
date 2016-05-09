#ifndef QUEUE2_H_INCLUDED
#define QUEUE2_H_INCLUDED
using namespace std;
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
class StrQueue
{
public:
    StrQueue();
    void enqueue(string a);
    string dequeue();
    bool isEmpty();
private:
    struct data
    {
        string s;
        data *next;
    };
    data* head;
    data* end;
    data* p;
};
StrQueue::StrQueue()
{
    head=(data*)new data;
    head->s="NAIVE!";
    head->next=NULL;
    end=head;
}
void StrQueue::enqueue(string a)
{
    p=(data*)new data;
    (p->s)=a;
    p->next=NULL;
    end->next=p;
    end=p;
}
string StrQueue::dequeue()
{
    data* temp;
    temp=head->next;
    head=head->next;
    return temp->s;
}
bool StrQueue::isEmpty()
{
    if(head==end)return true;
    else return false;
}

#endif // QUEUE2_H_INCLUDED
