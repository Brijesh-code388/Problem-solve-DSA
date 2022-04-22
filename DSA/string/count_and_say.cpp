#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>
#define N cout << endl;
using namespace std;
string Count_and_say(int n)
{
    string s;
    if (n == 1)
    {
        s = "1";
        return s;
    }
    if (n == 2)
    {
        s = "11";
        return s;
    }
    s = "11";
    for (int i = 3; i <= n; i++)
    {
        string t = "";
        s = s + '$';
        int c = 1;
        for (int j = 1; j < s.length(); j++)
        {
            if (s[j] != s[j - 1])
            {
                t = t + to_string(c);
                t = t + s[j - 1];
                c = 1;
            }
            else
            {
                c++;
            }
        }
        s = t;
    }
    return s;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);

    cout << Count_and_say(42);

    return 0;
}
