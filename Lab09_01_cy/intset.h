#ifndef INTSET2_H_INCLUDED
#define INTSET2_H_INCLUDED
#include <iostream>
#include <algorithm>
#define LL 0x7FFFFFFF
using namespace std;

class intset
{
public:
    intset(int val=0);
    intset(const intset &x);
    intset setunion(intset &x);
    intset setintsection(intset &x);
    intset setdifference(intset &x);
    intset setsymmetricdifference(intset &x);
    struct bad_intset{
        int errnum=0;
    };
    intset &operator=(const intset&x);
    intset &operator|=(intset &);
    intset &operator&=(intset &);
    intset &operator-=(intset &);
    int  count();
    int operator()();
    bool empty();
    bool member(int);
    bool subset(const intset&);
    void insert(int);
    void clear();
    void print();
    void erase(int);
private:
    int *n;
    int num=0;
    int errnum=0;
    int size=0;
};

intset operator&(intset&,intset&);
intset operator|(intset&,intset&);
intset operator-(intset&,intset&);

ostream& operator<<(ostream& s, intset a)
{
    s<<"{";
    if(a.count()!=0)
        a.print();
    s<<"}";
    return s;
}

istream& operator>>(istream& s, intset &a)
{
    int i,x,k;
    s>>x;
    for(i=0; i<x; i++)
    {
        s>>k;
        a.insert(k);
    }
    return s;
}

int intset::operator()()
{
    return this->count();
}
intset operator&(intset&x,intset&y)
{
    return x.setintsection(y);
}

intset operator|(intset &x,intset &y)
{
    return x.setunion(y);
}

intset operator-(intset&x,intset&y)
{
    return x.setdifference(y);
}

intset& intset::operator|=(intset&x)
{
    *this=this->setunion(x);
}

intset& intset::operator&=(intset &x)
{
    *this=this->setintsection(x);
}

intset& intset::operator-=(intset& x)
{
    *this=this->setdifference(x);
}

intset& intset::operator=(const intset&x)
{
    if(this!=&x)
    {
        delete []n;
        n=new int[size=x.size];
        uninitialized_copy_n(x.n,x.num,n);
        num=x.num;
    }
    return *this;
}

void intset::insert(int a)
{
    if(num>size&&size!=0&&errnum==0)
    {
        errnum=2;
        bad_intset bi;
        bi.errnum=errnum;
        throw bi;
    }
    else if(size==0&&errnum==0)
    {
        size=1000;
        errnum=3;
        n=new int[size];
        n[num++]=a;
    }
    else if(errnum==3)
    {
        n[num++]=a;
        sort(n,n+num);
    }
    else if(errnum==0&&num<=size&&size!=0)
    {
        if(!member(a))
        {
            n[num++]=a;
            sort(n,n+num);
        }
    }
}

intset intset::setintsection(intset&x)
{
    int i,t,minsize=0;
    for(i=0; i<num; i++)
        if(x.member(n[i]))  minsize++;
    intset s(minsize);
    s.n=new int[minsize];
    for(i=0,t=0; i<num; i++)
        if(x.member(n[i]))
        {
            s.n[s.num++]=n[i];
        }
    return s;
}

intset intset::setunion(intset &x)
{
    int maxsize=0,i;
    for(i=0; i<num; i++)
        if(x.member(n[i])) maxsize++;
    maxsize=num+x.num-maxsize;
    intset s{maxsize};
    for(i=0; i<num; i++)
    {
        if(x.member(n[i])) continue;
        else s.insert(n[i]);
    }
    for(i=0; i<x.num; i++)
        s.insert(x.n[i]);
    return s;
}

intset intset::setdifference(intset &x)
{
    int maxsize=0,i;
    for(i=0; i<num; i++)
        if(!x.member(n[i])) maxsize++;
    intset s{maxsize};
    for(i=0; i<num; i++)
        if(!x.member(n[i])) s.insert(n[i]);
    return s;
}

intset intset::setsymmetricdifference(intset &x)
{
    int maxsize=0,i;
    for(i=0; i<num; i++)
        if(x.member(n[i])) maxsize++;
    maxsize=num+x.num-2*maxsize;
    intset s{maxsize};
    for(i=0; i<num; i++)
        if(!x.member(n[i])) s.insert(n[i]);
    for(i=0; i<x.num; i++)
        if(!this->member(x.n[i])) s.insert(x.n[i]);
    return s;
}

intset::intset(int val)
{
        n=new int[val];
        size=val;
}

intset::intset(const intset&x)
{
    n=new int[x.size];
    size=x.size;
    for(int i=0; i<x.num; i++)
        n[num++]=x.n[i];
}

int intset::count()
{
    return num;
}

void intset::print()
{
    for(int i=0; i<num; i++)
    {
        if(i!=num-1) cout<<n[i]<<",";
        else cout<<n[i];
    }
}

bool intset:: subset(const intset&x)
{
    bool eq=true;
    if(num>=x.num)
    {
        for(int i=0; i<x.num; i++)
            if(!this->member(x.n[i]))
            {
                eq=false;
                break;
            }
    }
    else eq=false;
    return eq;
}
bool intset::member(int a)
{
    for(int i=0; i<num; i++)
    {
        if(n[i]==a) return true;
    }
    return false;
}

void intset::clear()
{
    delete []n;
    num=0;
    size=0;
}

bool intset::empty()
{
    if(this->num==0) return true;
    else
        return false;
}

void intset::erase(int a)
{
    if(member(a))
    {
        int i=0;
        for(i=0; i<num; i++)
            if(n[i]==a) break;
        n[i]=LL;
        num--;
        sort(n,n+num+1);
    }
}


#endif // INTSET2_H_INCLUDED
