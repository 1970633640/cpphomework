#include <iostream>
//#include <string.h>
using namespace std;
char x[1025];
void strequ(char * s)
{
    int i=0,flag=1;
    while(1)
    {
        if(x[i]!=s[i])
        {
            flag=0;
            break;
        }
        if(x[i]=='\0')break;
        i++;
    }
    if(flag==1)cout<<"yes"<<endl;
    if(flag==0)cout<<"no"<<endl;
}

void strcat (char* s)
{
    int i=0,j=0;
    for(i=0; i<1026; i++)if(x[i]=='\0')break;
    for(j=0; j<1026; j++)
    {
        x[i+j]=s[j];
        if(s[j]=='\0')break;
    }
    cout<<x<<endl;
}
void strsub (int a,int b)
{
    int i=0,j=0;
    for(i=0; i<1026; i++)if(x[i]=='\0')break;
    if (a<0||b<=0||a+b>i)
        cout<<"fail"<<endl;
    else
    {
        char ans[1024];
        for(i=a; i<=a+b-1; i++)ans[i-a]=x[i];
        ans[i-a]='\0';
        i=-1;
        while(0)
        {
            i++;
            x[i]=ans[i];
            if(ans[i]=='\0')break;
        }
        cout<<ans<<endl;
    }
}

int main()
{

    string e;
    int n,i;
    cin>>x;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>e;
        if(e=="strcat")
        {
            char s[1024];
            cin>>s;
            strcat(s);
        }
        else if(e=="strsub")
        {
            int a,b;
            cin>>a>>b;
            strsub(a,b);
        }
        else if (e=="strequ")
        {
            char s[1024];
            cin>>s;
            strequ(s);
        }
    }
    return 0;
}
