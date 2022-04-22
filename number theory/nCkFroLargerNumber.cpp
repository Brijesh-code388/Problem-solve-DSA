#include <bits/stdc++.h>
#define p 1000000007
#define ll long long int
using namespace std;

int F[1000001];

int power(int a, int m)
{
    int res = 1;
    while (m)
    {
        if (m % 2)
        {
            res = (res * 1ll * a) % p;
            m--;
        }
        else
        {
            a = (a * 1ll * a) % p;
            m /= 2;
        }
    }
    return res;
}

int c(int n, int k)
{
    int res = 1;
    res = res * 1ll * F[n];
    res = (res * 1ll * power(F[k], p - 2)) % p;
    res = (res * 1ll * power(F[n - k], p - 2)) % p;
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);

    int n, k, q;
    cin >> q;
    F[0] = F[1] = 1;
    for (int i = 2; i < 1000001; i++)
    {
        F[i] = (F[i - 1] * 1ll * i) % p;
    }
    while (q--)
    {
        cin >> n >> k;
        cout << c(n, k) << endl;
    }

    return 0;
}
