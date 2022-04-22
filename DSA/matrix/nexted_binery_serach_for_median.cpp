#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>
#define N cout << endl;
#define MAX 3
using namespace std;
int countSmallerThanMid(int a[][MAX], int i, int mid)
{
    int l = 0;
    int r = MAX - 1;
    while (l <= r)
    {
        int md = (l + r) / 2;
        if (a[i][md] <= mid)
            l = md + 1;
        else
            r = md - 1;
    }
    return l;
}
void bineryMedian(int m[][MAX], int r, int c)
{
    int low = 0;
    int high = 1e9;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int cnt = 0;
        for (int i = 0; i < r; i++)
        {
            cnt += countSmallerThanMid(m, i, mid);
        }
        if (cnt <= (r * c) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << low << "*";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    // sorted and alwayed r and c are odd;
    int r = 3, c = 3;
    int m[][MAX] = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};

    bineryMedian(m, r, c);

    return 0;
}
