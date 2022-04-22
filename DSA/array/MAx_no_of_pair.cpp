#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;
#define S cout << "*" << endl;

int Find_No_Of_Pair(int a[], int n, int sum)
{
    unordered_map<int, int> m;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    int pair = 0;
    for (int i = 0; i < n; i++)
    {
        pair = pair + m[sum - a[i]];
        if (sum - a[i] == a[i])
            pair--;
    }
    return pair / 2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    int a[] = {1, 5, 7, -1, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int sum = 6;
    cout << Find_No_Of_Pair(a, n, sum);

    return 0;
}