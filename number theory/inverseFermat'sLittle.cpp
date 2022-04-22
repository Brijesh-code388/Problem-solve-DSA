#include <bits/stdc++.h>
#define mode 1000000007
#define ll long long int
using namespace std;

long long int power(long long int a, long long int n)
{
    long long int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
        {
            ans = ((ans % mode) * (a % mode)) % mode;
            n--;
        }
        else
        {
            a = ((a % mode) * (a % mode)) % mode;
            n = n / 2;
        }
    }
    return ans % mode;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("./inputf.in", "r", stdin);
    // freopen("./outputf.out", "w", stdout);

    int a, m;
    cin >> a >> m;
    cout << (power(a, m - 2) % m);
    return 0;
}
