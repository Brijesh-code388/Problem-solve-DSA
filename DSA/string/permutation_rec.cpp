#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>
#define N cout << endl;
using namespace std;

void fun(string s, int l, int r)
{
    if (l == r)
    {
        cout << s;
        N;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(s[l], s[i]);
            fun(s, l + 1, r);
            swap(s[l], s[i]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);

    string s = "cab";
    sort(s.begin(), s.end());
    cout << s;
    N;
    while (next_permutation(s.begin(), s.end()))
    {
        cout << s;
        N;
    }
    N;
    N;
    string a = "abc";
    fun(a, 0, a.length() - 1);
    return 0;
}
