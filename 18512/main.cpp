#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const long long maxn = 5e4 + 300;
const long long mod = 98765431;

struct matrix {
    long long mat[2][2];
    matrix () {
        mat[0][0] = 1, mat[0][1] = 0, mat[1][0] = 0, mat[1][1] = 1;
    }
    matrix (long long a, long long b, long long c, long long d) {
        mat[0][0] = a, mat[0][1] = b, mat[1][0] = c, mat[1][1] = d;
    }
};

matrix mul(matrix& a, matrix& b) {
    matrix ret;
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; j++)
            ret.mat[i][j] = (((a.mat[i][0] % mod) * (b.mat[0][j] % mod)) % mod + ((a.mat[i][1] % mod) * (b.mat[1][j] % mod)) % mod + mod) % mod;
    return ret;
}

matrix pow_m(matrix a, long long n) {
    matrix ret;
    matrix temp = a;
    while (n)
    {
        if (n & 1)
            ret = mul(ret, temp);
        temp = mul(temp, temp);
        n >>= 1;
    }
    return ret;
}

int main()
{
    long long n, t, a[maxn];
    scanf("%I64d%I64d", &n, &t);
    matrix tmp = {n - 1, 0, 1, -1};
    matrix p = pow_m(tmp, t);
    long long aa = p.mat[1][0] % mod, bb = p.mat[1][1] % mod, sum = 0;
//    cout << aa << ' ' << bb << endl;
    for (int i = 0; i < n; ++i)
        scanf("%I64d", &a[i]), sum = (a[i] + sum) % mod;
    for (int i = 0; i < n; ++i)
        printf("%I64d\n", (aa * sum % mod + bb * a[i] % mod) % mod);
    return 0;
}
/*
10 1452133
85 62 3 55 222 55 95 62 321 456
*/
