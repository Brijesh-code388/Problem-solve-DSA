#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;

void findMinOps(int a[], int n)
{
    int ans = 0;
    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        if (a[l] == a[r])
        {
            l++;
            r--;
        }
        else if (a[l] < a[r])
        {
            l++;
            a[l] = a[l] + a[l - 1];
            ans++;
        }
        else
        {
            r--;
            a[r] = a[r] + a[r + 1];
            ans++;
        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    int arr[] = {1, 4, 3, 1, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    // it work when it has chances for make the pelidrome
    findMinOps(arr, n);

    return 0;
}
