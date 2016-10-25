#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

long long int mod_mul(long long int a, long long int b, long long int n) {
    long long int res = 0;
    while(b) {
        if(b&1)    res = (res + a) % n;
        a = (a + a) % n;
        b >>= 1;
        cout<<b<<endl;
    }
    return res;
}

long long int mod_exp(long long int a, long long int b, long long int n) {
    long long int res = 1;
    while(b) {
        if(b&1)    res = mod_mul(res, a, n);
        a = mod_mul(a, a, n);
        b >>= 1;
    }
    return res;
}

bool miller_rabin(long long int  n) {
    if(n == 2 || n == 3 || n == 5 || n == 7 || n == 11)    return true;
    if(n == 1 || !(n%2) || !(n%3) || !(n%5) || !(n%7) || !(n%11))    return false;

    long long int x, pre, u;
    int i, j, k = 0;
    u = n - 1;    //要求x^u % n

    while(!(u&1)) {    //如果u为偶数则u右移，用k记录移位数
        k++; u >>= 1;
    }

    srand((long long int)time(0));
    for(i = 0; i < 1; i++) {    //进行S次测试
        x = rand()%(n-2) + 2;    //在[2, n)中取随机数
        if((x%n) == 0)    continue;

        x = mod_exp(x, u, n);    //先计算(x^u) % n，
        pre = x;
        for(j = 0; j < k; ++j) {    //把移位减掉的量补上，并在这地方加上二次探测
            x = mod_mul(x, x, n);
            if(x == 1 && pre != 1 && pre != n-1)    return false;    //二次探测定理，这里如果x = 1则pre 必须等于 1，或则 n-1否则可以判断不是素数
            pre = x;
        }
        if(x != 1)    return false;    //费马小定理
    }
    return true;
}
int main()
{
    long long int a,b,c;
    while(cin>>a>>b>>c)
    cout<<mod_exp(a,b,c);
    return 0;
}
