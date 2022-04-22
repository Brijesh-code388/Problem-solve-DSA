#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;

float findMedianSortArrays(int a[], int b[], int n1, int n2)
{
    if (n2 < n1)
        return findMedianSortArrays(b, a, n2, n1);

    int low = 0;
    int high = n1;
    while (low <= high)
    {
        int cut1 = (low + high) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int left1 = cut1 == 0 ? INT_MIN : a[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];

        int right1 = cut1 == n1 ? INT_MAX : a[cut1];
        int right2 = cut2 == n2 ? INT_MAX : b[cut2];

        if ((left1 <= right2) && (left2 <= right2))
        {
            if ((n1 + n2) % 2 == 0)
            {
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }
            else
                return max(left1, left2);
        }
        else if (left1 > right2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 0.0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {2, 4, 6, 7, 8, 9, 10};
    // find_median(a, b, 5);
    int n = 5;
    // cout << find_median(a, b, 0, 0, n - 1, n - 1);
    cout << findMedianSortArrays(a, b, 5, 7);
    return 0;
}
