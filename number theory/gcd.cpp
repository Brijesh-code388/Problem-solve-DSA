#include <bits/stdc++.h>
#define mode 1000000007
#define ll long long int
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    else
    {
        return gcd(b % a, a);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);

    int result = gcd(16, 2000);
    cout << result;
    return 0;
}
