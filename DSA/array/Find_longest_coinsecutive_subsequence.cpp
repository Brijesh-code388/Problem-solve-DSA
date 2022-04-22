#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;
#define S cout << "*" << endl;

void Find_longest_coinsecutive_subsequence(int a[], int n)
{
    int res = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (m[a[i] - 1] < 0)
        {
            continue;
        }
        else
        {
            int j = a[i] + 1;
            while (m[j] > 0)
            {
                j++;
            }
            res = max(res, j - a[i]);
        }
    }
    cout << res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    int a[] = {4, 2, 8, 7, 3, 1, 6, 8};
    Find_longest_coinsecutive_subsequence(a, 8);
    return 0;
}
