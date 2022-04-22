#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;

void find_min_diff_bw_max_and_min_choclate(int a[], int n, int m)
{
    int min = INT_MAX;
    sort(a, a + n);
    for (int i = 0; i + m - 1 < n; i++)
    {
        int d = a[i + m - 1] - a[i];
        if (min > d)
        {
            min = d;
        }
    }
    cout << min;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    // int a[] = {3, 4, 1, 9, 56, 7, 9, 12};int m=5;
    int a[] = {7, 3, 2, 4, 9, 12, 56};
    int m = 3;
    find_min_diff_bw_max_and_min_choclate(a, 7, m);
    return 0;
}
