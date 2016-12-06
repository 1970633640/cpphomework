#include <iostream>
#include <stdio.h>
#include <cstring>
#include <set>
#include <algorithm>
#define left root*2
#define right root*2+1
using namespace std;

int l[1600000],r[1600000],value[1600000],postl[10005],postr[10005],post[90010],hash[90010];
bool same[160000];
set <int> ans;

void build(int L,int R,int root)
{
    l[root]=L;
    r[root]=R;
    if(L!=R)
    {
        int M=(L+R)/2;
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
    memset(hash,0,sizeof(hash));
    memset(post,0,sizeof(post));
}

void repair(int root)
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

void change(int L,int R,int val,int root)
{
    if(L<=l[root] && R>=r[root])
    {
        same[root]=0;
        value[root]=val;
    }
    else
    {
        repair(root);
        int M=(l[root]+r[root])/2;
        if(L<=M)change(L,R,val,left);
        if(R>=M+1)change(L,R,val,right);
    }
}

void f(int root)
{
    if(same[root]==0)ans.insert(value[root]);
    else
    {
        f(left);
        f(right);
    }
}

void print()
{
    ans.clear();
    f(1);
    printf("%d\n",ans.size()-1);
}
int find2(int l,int r,int x)
{
 int L = l, R = r, mid;
  while (L <= R) {
        mid = (L+ R) /2;
        if (hash[mid] >= x)  R = mid - 1;
        else L = mid + 1;
    }
     if (hash[L] == x) return L;
    else return -1;
}
int main()
{
    int i,nn,n,a,b,postsum;
    scanf("%d",&nn);
    build(1,40004,1);
    while(nn--)
    {
        reset();
        scanf("%d",&n);

        for(i=1; i<=n; ++i)
        {
            scanf("%d%d",&a,&b);
post[(i-1)*2]=a;post[(i-1)*2+1]=b;
            postl[i]=a;
            postr[i]=b;
        }
sort(post,post+n*2);
postsum=unique(post,post+n*2)-post;
//for(i=0;i<postsum;++i)printf("--%d\n",post[i]);
int c=2;hash[1]=post[0];int temp=post[0];
for(i=1;i<postsum;++i)
{
    if(post[i]-temp==1)hash[c]=post[i];else {hash[c]=post[i]-1;++c;hash[c]=post[i];}
    temp=hash[c];
    ++c;
}
//for(i=0;i<c;i++)printf("-%d-",hash[i]);
        for(i=1; i<=n; ++i)
            change(find2(1,c-1,postl[i]),find2(1,c-1,postr[i]),i,1);
        print();

    }
    return 0;
}
