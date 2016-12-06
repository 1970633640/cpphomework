#include <iostream>
#include <stdio.h>
#include <cstring>
#include <set>
#include <algorithm>
#define left root*2
#define right root*2+1
//使用数组结构体
using namespace std;
long long int value[160000],l[160000],r[160000],postl[160000],postr[160000],posth[160000],post[160000],hash[160000];
long long int ans=0;
bool same[160000];
void build(long long int L,long long int R,long long int root)
{
    l[root]=L;
    r[root]=R;
    if(L!=R)
    {
        long long int M=(L+R)/2;
        build(L,M,left);
        build(M+1,R,right);
    }
}

void reset()
{
    memset(value,0,sizeof(value));
    memset(same,0,sizeof(same));
    memset(postl,0,sizeof(postl));
    memset(postr,0,sizeof(postr));
    memset(hash,0,sizeof(hash)); //0就是1 1就是0
    memset(post,0,sizeof(post));
    memset(posth,0,sizeof(posth));
}

void repair(long long int root)
{
    if(same[root]==0)
    {
        same[left]=0;
        same[right]=0;
        same[root]=1;
        value[left]=value[root];
        value[right]=value[root];
    }
}

void f(long long int root)
{
    if(same[root]==0)ans+=(hash[r[root]]-hash[l[root]]+1)*value[root];
    else
    {
        f(left);
        f(right);
    }
}

void change(long long int L,long long int R,long long int val,long long int root)
{
    if(L<=l[root] && R>=r[root] && val>value[root] && same[root]==0)
    {
        same[root]=0;
        value[root]=val;
    }
    else if(val<=value[root] && same[root]==0)return;

    else
    {//printf("repair %I64d %I64d %I64d %I64d\n",value[root],l[root],r[root],root);
        repair(root);
        long long int M=(l[root]+r[root])/2;
        if(L<=M)change(L,R,val,left);
        if(R>=M+1)change(L,R,val,right);
    }
}

int find2(long long int l,long long int r,long long int x)
{
    long long int L = l, R = r, mid;
    while (L <= R)
    {
        mid = (L+ R) /2;
        if (hash[mid] >= x)  R = mid - 1;
        else L = mid + 1;
    }
    if (hash[L] == x) return L;
    else return -1;
}

void print()
{

    f(1);
    printf("%I64d\n",ans);
}

int main()
{
    int i,n;
    build(1,40000,1);
    reset();
    scanf("%d\n",&n);
    long long int postsum;
    for(i=1; i<=n; ++i)
    {
        scanf("%I64d%I64d%I64d",&postl[i],&postr[i],&posth[i]);
        --postr[i];
        post[(i-1)*2]=postl[i];
        post[(i-1)*2+1]=postr[i];
    }
sort(post,post+n*2);
postsum=unique(post,post+n*2)-post;
int c=2;hash[1]=post[0];int temp=post[0];
for(i=1;i<postsum;++i)
{
    if(post[i]-temp==1)hash[c]=post[i];else {hash[c]=post[i]-1;++c;hash[c]=post[i];}
    temp=hash[c];
    ++c;
}
for(i=1; i<=n; ++i)
            {//printf("change %d %d %d\n",find2(1,c-1,postl[i]),find2(1,c-1,postr[i]),posth[i]);
                change(find2(1,c-1,postl[i]),find2(1,c-1,postr[i]),posth[i],1);}
        print();
}
