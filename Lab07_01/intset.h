#ifndef INTSET_H_INCLUDED
#define INTSET_H_INCLUDED
//#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

class intset
{

public:

    intset(int a=0);
    intset(const intset&  s);
    void init(int a);
    void insert(int a);
    void clear();
    void test();
    void print();
    void qs();
    void erase(int a);
    int count() const;
    bool member(int a);
    bool empty();
    bool subset(intset& a);
    intset setunion( intset& a) ;
    intset setintsection( intset& a) ;
    intset setdifference( intset& a) ;
    intset setsymmetricdifference( intset& a) ;
    int read(int a);
private:
  struct data
    {
        int x;
        data *next;
    };
    data* head;
    data* node;
    data* p;
    data* end;
    int maxsize;
};

intset::intset(int a)
{maxsize=a;
    this->init(a);
}
intset::intset(const intset& s)
{
    int i;
    int j;
    j=s.count();


    init(j);
    p=head;
    node=s.head;
    for(i=0; i<j; i++)
    {
        p->x=node->x;
        p=p->next;
        node=node->next;
    }
}
void intset::init(int a)
{
    int i;

    node= (data *)malloc(sizeof(data));
    node->next=NULL;
    p=node;
    for(i=0; i<a; i++)
    {
        node=(data*)malloc(sizeof(data));
        node->next=p;
        p=node;
    }
    head=p;
    end=head;
}
void intset::test()
{
    cout<<"Excited!可以运行！"<<endl;
}
void intset::insert(int a)
{
    p=end;
    if(end->next != NULL)
    {
        p->x=a;
        end=end->next   ;
    }
    else
    {
        cout<<"Angry!输入太多了！！"<<endl;
        throw 2;
    }
}
int intset::count() const
{
    int temp=0;
    data* point=head;
    while(point!=end)
    {
        temp++;
        point=point->next;
    }
    return temp;
}
void intset::qs()
{int temp,i;
for(i=0;i<this->count();i++){
   for(p=this->head;p!=end;)
   {
      if (p->x > (p->next)->x){temp=p->x;p->x=(p->next)->x;(p->next)->x=temp;}
      p=p->next;
   }
}}
void intset::print()
{this->qs();
    p=head;
    cout<<"{";
    if(p!=end)
    {
        cout<<p->x;
        while(p->next!=end)
        {
            p=p->next;
            cout<<","<<p->x;

        }

    }
    cout<<"}";
}
bool intset::member(int a)
{
    p=head;
    while(p!=end)
    {
        if(p->x==a)return 1;
        p=p->next;
    }
    return 0;
}
intset intset::setunion( intset& a)
{
    int i;
    intset ans{a.count()+this->count()};
    for(i=0; i<a.count(); i++)ans.insert(a.read(i));
    for(i=0; i<this->count(); i++)  if(a.member(this->read(i))==0)  ans.insert(this->read(i));
    return ans;
}
intset intset::setintsection( intset& a)
{
    int i;
    intset ans{a.count()};
    for(i=0;i<this->count();i++)if(a.member(this->read(i))==1)ans.insert(this->read(i));
return ans;
}
intset intset::setdifference( intset& a)
{
    int i;
    intset ans{this->count()};
    for(i=0;i<this->count();i++)if(a.member(this->read(i))==0)ans.insert(this->read(i));
return ans;
}
intset intset::setsymmetricdifference( intset& a)
{
int i;
intset ans{a.count()+this->count()};
for(i=0;i<this->count();i++)if(a.member(this->read(i))==0)ans.insert(this->read(i));
for(i=0;i<a.count();i++)if(this->member(a.read(i))==0)ans.insert(a.read(i));
return ans;
}
int intset::read(int a)
{
    int i;
    p=head;
    for(i=0; i<a; i++)p=p->next;
    return p->x;
}
void intset::clear()
{
   int i;p=head;
intset ans{this->maxsize};
this->head=ans.head;this->end=ans.end;
}
bool intset::empty()
{
    if (this->count()==0)return 1;
    else return 0;
}
void intset::erase(int a)
{int i;data* point;point=head;
  if(this->member(a)==0)cout<<"删除无中生有的东西，等于你也有责任吧！\n";
  else{
  intset ans{this->count()-1};
  for(i=0;i<this->count();i++)
  {
      if(this->read(i)!=a)ans.insert(this->read(i));

  }
      this->head=ans.head;
      this->end=ans.end;
}}
bool intset::subset(intset& a)
{
    int i,flag=1;
    for(i=0;i<this->count();i++)if(a.member(this->read(i))==0)flag=0;
        return flag;
}
#endif // INTSET_H_INCLUDED
