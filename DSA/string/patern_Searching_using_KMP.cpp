#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>
#define N cout << endl;
using namespace std;

// this is KMP Algo.
void longest_prefix_suffix(string s, int pi[])
{
    int n = s.length();
    pi[0] = 0;
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        j = pi[i - 1];
        while (s[i] != s[j] && j > 0)
        {
            j = pi[j - 1];
        }
        if (s[i] == s[j])
        {
            j++;
        }
        pi[i] = j;
    }
}

// one of the method id sliding window;
int patern_matching(string t, int pi[], string s)
{
    int i = 0;
    int j = 0;
    int pos = -1;
    while (i < t.length())
    {
        if (t[i] == s[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j > 0)
            {
                j = pi[j - 1];
            }
            else
            {
                i++;
            }
        }
        if (j == s.length())
        {
            pos = i - s.length();
            break;
        }
    }
    return pos;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    // string s = "ababc";
    string s = "acbacb";
    int n = s.length();
    int pi[n];
    longest_prefix_suffix(s, pi);
    for (int i = 0; i < s.length(); i++)
    {
        cout << pi[i] << " ";
    }
    N;

    // we can use this KMP algo for string matching!!'

    string t = "acback";

    cout << patern_matching(t, pi, s);

    return 0;
}

// o(n)