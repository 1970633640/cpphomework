#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    double a,b,c,x1,x2;
    cin>>a>>b>>c;
    x1=(-b-sqrt(b*b-4*a*c))/(2*a);
    x2=(-b+sqrt(b*b-4*a*c))/(2*a);
    if (fabs(x1-x2)>0.00001)
        cout<< fixed <<setprecision(6)<<x1<<" "<<x2<<endl;
        else
            cout<< fixed <<setprecision(6)<<x1<<endl;
    return 0;
}
