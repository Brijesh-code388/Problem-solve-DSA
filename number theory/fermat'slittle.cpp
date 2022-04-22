#include <bits/stdc++.h>
#define p 1000000007
#define ll long long int
using namespace std;

int binpower(int base, int e, int mod)
{
    int result = 1;
    base %= mod;
    while (e)
    {
        if (e & 1)
            result = (int)result * base % mod;
        base = (int)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool probablyPrimeFermat(int n, int iter = 5)
{
    if (n < 4)
        return n == 2 || n == 3;

    for (int i = 0; i < iter; i++)
    {
        int a = 2 + rand() % (n - 3);
        if (binpower(a, n - 1, n) != 1)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);

    int n;
    cin >> n;
    bool prime = probablyPrimeFermat(n);
    cout << prime;

    return 0;
}
