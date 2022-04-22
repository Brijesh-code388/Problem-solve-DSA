#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>
#define N cout << endl;
#define MAX 5
using namespace std;

void find_row_with_max_1s(int a[][4], int n, int m)
{
    int j = m - 1;
    int row = -1;
    while (j >= 0 && a[0][j] == 1)
    {
        j--;
    }

    for (int i = 1; i < n; i++)
    {
        while (j >= 0 && a[i][j] == 1)
        {
            j--;
            row = i;
        }
    }
    cout << "max has " << row;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    // sorted b_arr;
    int a[][4] = {{0, 0, 0, 0},
                  {0, 0, 0, 0},
                  {0, 1, 1, 1},
                  {0, 0, 1, 1}};
    int n = 4, m = 4;
    find_row_with_max_1s(a, 4, 4);
    return 0;
}
