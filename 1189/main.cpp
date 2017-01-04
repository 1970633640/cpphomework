#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;
const double pai=3.14159265358979323546264;
typedef struct node
{
    int x;
    int y;
} node;
node p[1001];
node s[1001];
bool check(node n1,node n2)
{
    return (n1.x-p[0].x)*(n2.y-p[0].y)>(n2.x-p[0].x)*(n1.y-p[0].y);
}
bool check2(node p1, node p2, node p0)
{
    return ((p1.x - p0.x) * (p2.y - p0.y) >= (p2.x - p0.x) * (p1.y - p0.y));
}
int cmp(const void *a,const void * b)
{
    //return check((*(node*)a),(*(node*)b));
    double ans1,ans2;
    int X1= (*(node*)a).x-p[0].x;
    int Y1= (*(node*)a).y-p[0].y;
    int X2= (*(node*)b).x-p[0].x;
    int Y2= (*(node*)b).y-p[0].y;
    if(X1<0)
        ans1=atan((double)Y1/(double)X1)+pai;
    else if(X1>0)
        ans1=atan((double)Y1/(double)X1);
    else
        ans1=pai/2.0;
    if(X2<0)
        ans2=atan((double)Y2/(double)X2)+pai;
    else if(X2>0)
        ans2=atan((double)Y2/(double)X2);
    else
        ans2=pai/2.0;
    if( fabs(ans1-ans2)<0.0000000001)
        return (X1*X1+Y1*Y1)-(X2*X2+Y2*Y2);
    else
        return ans1-ans2>0?1:-1;
}
bool operator < (const node &p1, const node &p2)
{
    return p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x);
}

int g(int n)
{
    int i, len, k = 0, sum = 1;
    sort(p, p + n);
    s[0] = p[0];
    s[1] = p[1];
    s[2] = p[2];
    for(int i = 2; i<n; i++)
    {
        while(sum && check2(p[i],s[sum],s[sum-1])) sum--;
        s[++sum]=p[i];
    }
    len=sum;
    s[++sum]=p[n - 2];
    for(int i=n-3;i>=0;i--)
    {
        while(sum && check2(p[i],s[sum],s[sum-1]))sum--;
        s[++sum]=p[i];
    }
    return sum;
}

double dis(node n1,node n2)
{
    return sqrt(  (double)(n1.x-n2.x)*(double)(n1.x-n2.x) +(double)(n1.y-n2.y)*(double)(n1.y-n2.y)  );
}
node next_to_top(stack <node> s)
{
    node temp=s.top();
    s.pop();
    node ans=s.top();
    s.push(temp);
    return ans;
}
int main()
{
    int n,w;
    scanf("%d%d",&n,&w);
    for(int i=0; i<n; ++i)
        scanf("%d%d",&p[i].x,&p[i].y);
    int minx=99999,miny=99999,minm;
    for(int i=0; i<n; ++i)
    {
        if(p[i].y<miny||(p[i].y==miny && p[i].x<minx) )
        {
            minx=p[i].x;
            miny=p[i].y;
            minm=i;
        }
    }

    int t2=p[0].x;
    p[0].x=p[minm].x;
    p[minm].x=t2;
    t2=p[0].y;
    p[0].y=p[minm].y;
    p[minm].y=t2;
    //qsort(p+1,n-1,sizeof(p[1]),cmp);
    //for(int i=0;i<n;++i)cout<<"\n"<<p[i].x<<" "<<p[i].y;
    //cout<<"\n\n";
    int sum=g(n);
    double ans=0;
    for(int i=0; i<sum-1; ++i)
        ans+=dis(s[i],s[i+1]);
    ans+=dis(s[sum-1],s[0]);
    ans+=2.0*pai*(double)w;
    printf("%.0f\n",ans);
    return 0;
}
