#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>
#define N cout << endl;
using namespace std;

unordered_map<string, int> dp;

int word_break(string s, vector<string> &b)
{
    int n = s.length();
    if (n == 0)
        return 1;
    if (dp[s] != 0)
    {
        return dp[s];
    }

    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        string ss = s.substr(0, i);
        for (int j = 0; j < b.size(); j++)
        {
            if (ss.compare(b[j]) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1 && word_break(s.substr(i, n - i), b) == 1)
            return dp[s] = 1;
    }
    return dp[s] = -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);

    vector<string> b;
    b.push_back("i");
    b.push_back("like");
    b.push_back("to");
    string s = "iliketoliketo";

    cout << word_break(s, b);

    return 0;
}

// not use dp fool me @@