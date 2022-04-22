#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>
#define N cout << endl;
using namespace std;

void fun(string t, int i, int n, string s)
{
    if (i == n)
    {
        cout << t << endl;
    }
    else
    {
        fun(t, i + 1, n, s);
        t = t + s[i];
        fun(t, i + 1, n, s);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);

    string s = "abc";
    fun("", 0, s.length(), s);

    return 0;
}
