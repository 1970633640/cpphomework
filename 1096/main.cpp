#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int x[9][9];
int sum[9][9];
double d[14][9][9][9][9];
double f(int x1, int y1, int x2, int y2)
{
    double ans = (double)(sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]);
    return pow(ans,2);
}

int main()
{
    int n, total=0;
    scanf("%d",&n);
    for(int i=1; i<=8; ++i)
        for(int j=1; j<=8; ++j)
        {
            scanf("%d",&x[i][j]);
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + x[i][j];
            total += x[i][j];
        }
    for(int x1=1; x1<=8; ++x1)
        for(int y1=1; y1<=8; ++y1)
            for(int x2=x1; x2<=8; ++x2)
                for(int y2=y1; y2<=8; ++y2)
                    d[0][x1][y1][x2][y2] = f(x1,y1,x2,y2);
    for(int i=1;i<n; ++i)
        for(int x1=1; x1<=8; ++x1)
            for(int y1=1; y1<=8; ++y1)
                for(int x2=x1; x2<=8; ++x2)
                    for(int y2=y1; y2<=8; ++y2)
                    {
                        d[i][x1][y1][x2][y2] = 9999999999.99;
                        for(int j=x1; j<x2; ++j)
                        {
                            d[i][x1][y1][x2][y2] = min(d[i][x1][y1][x2][y2], d[0][x1][y1][j][y2]+d[i-1][j+1][y1][x2][y2]);
                            d[i][x1][y1][x2][y2] = min(d[i][x1][y1][x2][y2], d[i-1][x1][y1][j][y2]+d[0][j+1][y1][x2][y2]);
                        }
                        for(int j=y1; j<y2; ++j)
                        {
                            d[i][x1][y1][x2][y2] = min(d[i][x1][y1][x2][y2], d[0][x1][y1][x2][j]+d[i-1][x1][j+1][x2][y2]);
                            d[i][x1][y1][x2][y2] = min(d[i][x1][y1][x2][y2], d[i-1][x1][y1][x2][j]+d[0][x1][j+1][x2][y2]);
                        }
                    }
    double ans = d[n-1][1][1][8][8]*1.000/n - ((double)total*1.000/n)*((double)total*1.000/n);
    printf("%.3f",pow(ans,0.5));
    return 0;
}
