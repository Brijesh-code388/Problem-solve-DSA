
#include <bits/stdc++.h>
#define p 1000000007
#define ll long long int
using namespace std;

int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);

    int a, b;
    cin >> a >> b;
    int x, y;

    cout << gcd(a, b, x, y) << endl;
    cout << x << " " << y;
    return 0;
}
