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

    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    int x, y;
    // cout << (a == 0 && b == 0);
    if (a == 0 && b == 0)
    {
        if (c == 0)
            cout << "infinite";
        else
            cout << "0 solution";
    }
    else
    {
        int sol_x, sol_y;
        int d = gcd(abs(a), abs(b), x, y);
        if (c % d)
        {
            cout << "there is no solution";
        }
        else
        {
            sol_x = x * (c / d);
            sol_y = y * (c / d);
            if (a < 0)
                sol_x = -sol_x;
            if (b < 0)
                sol_y = -sol_y;
            cout << sol_x << " " << sol_y;
        }
    }

    return 0;
}
