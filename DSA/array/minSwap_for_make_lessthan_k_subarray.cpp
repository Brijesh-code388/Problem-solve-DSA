#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;

// move subarray contiguse oneside that id less than k;
void minSwap(int a[], int n, int k)
{
    int good = 0;
    int bad = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= k)
        {
            good++;
        }
    }
    // int first window slide
    for (int i = 0; i < good; i++)
    {
        if (a[i] > k)
        {
            bad++;
        }
    }
    int i = 0;
    int j = good;
    int ans = bad;
    while (j < n)
    {
        if (a[i] > k)
        {
            bad--;
        }
        if (a[j] > k)
        {
            bad++;
        }
        ans = min(ans, bad);
        i++;
        j++;
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    int arr[] = {2, 7, 9, 5, 8, 7, 4};
    int k = 6;
    minSwap(arr, 7, k);

    return 0;
}
