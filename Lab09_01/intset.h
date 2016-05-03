#include <iostream>
#include <algorithm>
#define LL 0x7FFFFFFF
using namespace std;

class intset
{
public:
    intset operator|(intset a);
    intset operator&(intset a);
    intset operator-(intset a);
    intset operator|=(intset a);
    intset operator&=(intset a);
    intset operator-=(intset a);
    int operator()();
    intset(int val=0);
    intset(const intset &x);
    intset setunion(intset &x);
    intset setintsection(intset &x);
    intset setdifference(intset &x);
    intset setsymmetricdifference(intset &x);
    intset &operator=(const intset&x);
    int  count();
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
ostream& operator<<(ostream& s, intset a)
{

    cout<<"{";
    a.print();
    cout<<"}";

}
istream& operator>>(istream& s, intset &a)
{int i,x,k;
s>>x;
for(i=0;i<x;i++)
    {s>>k;a.insert(k);}
    return s;
}
int intset::operator()()
{return this->count();}
intset intset::operator|(intset a)
{
    return this->setunion(a);
}
intset intset::operator-(intset a)
{
    return this->setdifference(a);
}
intset intset::operator|=(intset a)
{*this=this->setunion(a);
    return this->setunion(a);
}
intset intset::operator&=(intset a)
{*this=this->setintsection(a);
    return this->setintsection(a);
}
intset intset::operator-=(intset a)
{*this=this->setdifference(a);
    return this->setdifference(a);
}
intset intset::operator&(intset a)
{
    return this->setintsection(a);
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
    maxsize=num+x.num-maxsize;
    intset s{maxsize};
    for(i=0; i<num; i++)
        if(!x.member(n[i])) s.insert(n[i]);
    for(i=0; i<x.num; i++)
        if(this->member(x.n[i])) s.insert(x.n[i]);
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
    //cout<<x.n[0]<<" "<<x.n[1]<<endl;
    for(int i=0; i<x.num; i++)
        n[num++]=x.n[i];
    //cout<<n[0]<<" "<<n[1]<<endl;
}

int intset::count()
{
    return this->num;
}

void intset::insert(int a)
{
    if(this->num>this->size)
        this->errnum=1;
    else
    {
        if(!member(a))
        {
            this->n[this->num++]=a;
            sort(this->n,this->n+this->num);
        }
    }
}

void intset::print()
{
    if(errnum) throw errnum;
    else
    {
        for(int i=0; i<num; i++)
        {
            if(i!=num-1) cout<<n[i]<<",";
            else cout<<n[i];
        }
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
    for(int i=0; i<this->num; i++)
    {
        if(this->n[i]==a) return true;
    }
    return false;
}

void intset::clear()
{
    delete n;
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
        for(i=0; i<this->num; i++)
            if(this->n[i]==a) break;
        this->n[i]=LL;
        this->num--;
        sort(this->n,this->n+this->num+1);
    }
}
