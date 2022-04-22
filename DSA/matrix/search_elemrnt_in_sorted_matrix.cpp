#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>
#define N cout << endl;
#define MAX 5
using namespace std;

// for row and column both wise sorted;
void search(int a[][4], int n, int s)
{
    int i = 0;
    int j = n - 1;
    while (i < n && j >= 0)
    {
        if (a[i][j] == s)
        {
            cout << i << " " << j;
        }
        if (a[i][j] > s)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
}

// for only row wise sorted but ........see array
void sortedMatrixSearch(int a[][MAX], int n, int m, int s)
{
    if (n == 0 && m == 0)
    {
        return;
    }
    int l = 0;
    int r = n * m - 1;

    while (l <= r)
    {

        int mid = ((l) + (r)) / 2;
        cout << l << " " << r << endl;
        cout << mid << endl;

        if (a[mid / m][mid % m] == s)
        {
            cout << "true";
            return;
        }
        if (a[mid / m][mid % m] < s)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << "false";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);

    int mat[4][4] = {{10, 20, 30, 40},
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50}};
    search(mat, 4, 29);
    N;

    int n = 4, m = 5, x = 29;
    int matrix[][5] = {{0, 6, 8, 9, 11},
                       {20, 22, 28, 28, 31},
                       {36, 38, 50, 61, 63},
                       {64, 66, 100, 122, 128}};

    sortedMatrixSearch(matrix, n, m, x);
    return 0;
}
