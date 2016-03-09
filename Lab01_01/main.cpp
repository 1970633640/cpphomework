#include <iostream>
#include <ctype.h>
using namespace std;
int main()
{
    char i;
    for(i=0; i<127; i++)
        if(isprint(i))
            cout<<i<<" "<<dec<<(int)i<<" "<<hex<<(int)i <<endl;
    return 0;
}
