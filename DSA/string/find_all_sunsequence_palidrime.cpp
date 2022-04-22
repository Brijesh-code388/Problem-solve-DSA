#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>
#define N cout << endl;
using namespace std;
int dp[100][100];

void find_all_palidirome_sybsequence(string s)
{
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
            }
            else if ((j - i) == 1)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = 3;
                }
                else
                {
                    dp[i][j] = 2;
                }
            }
            else
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] + 1;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            cout << dp[i][k] << " ";
        }
        N;
    }
    N;

    cout << dp[0][s.length() - 1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);

    string s = "abca";
    find_all_palidirome_sybsequence(s);
    return 0;
}
