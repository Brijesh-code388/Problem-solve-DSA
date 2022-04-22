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
bool check_composite(int n, int a, int d, int s)
{
    int x = binpower(a, d, n);
    cout << "x= " << x << endl;
    if (x == 1 || x == n - 1)
    {
        // cout << "x= " <<  x << endl;
        return false;
    }
    for (int r = 1; r < s; r++)
    {
        x = (int)x * x % n;
        cout << "x= " << x << endl;
        if (x == n - 1)
            return false;
    }
    cout << "composite" << endl;
    return true;
};

bool MillerRabin(int n, int itr = 5)
{
    if (n < 4)
    {
        return n == 3 || n == 2;
    }
    int s = 0;
    int d = n - 1;
    while ((d & 1) == 0)
    {
        d >>= 1;
        s++;
    }
    cout << s << " " << d << endl;

    for (int i = 0; i < itr; i++)
    {
        int a = 2 + rand() % (n - 3);
        cout << "a =" << a << endl;
        // cout << check_composite(n, a, d, s) << endl;

        if (check_composite(n, a, d, s))
            return false;
        cout << endl;
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
    bool prime = MillerRabin(n);
    cout << prime;

    return 0;
}
