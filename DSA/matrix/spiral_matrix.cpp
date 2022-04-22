#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>
#define N cout << endl;
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;

    if (matrix.size() == 0)
    {
        return ans;
    }
    int R = matrix.size(), C = matrix[0].size();
    vector<vector<bool>> seen(R, vector<bool>(C, false));
    int r = 0;
    int c = 0;
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    int di = 0;
    for (int i = 0; i < R * C; i++)
    {
        ans.push_back(matrix[r][c]);
        seen[r][c] = true;
        int next_r = r + dr[di];
        int next_c = c + dc[di];

        if (next_r < R && next_r >= 0 && next_c < C && next_c >= 0 && !seen[next_r][next_c])
        {
            r = next_r;
            c = next_c;
        }
        else
        {
            di = (di + 1) % 4;
            r = r + dr[di];
            c = c + dc[di];
        }
    }

    return ans;
}

void spiralPrint2(int m, int n, int a[3][6])
{
    int k = 0;
    int l = 0;
    while (k < m && l < n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[k][i] << " ";
        }
        k++;
        for (int i = k; i < m; i++)
        {
            cout << a[i][n - 1] << " ";
        }
        n--;
        if (k < m)
        {
            for (int i = n - 1; i >= l; --i)
            {
                cout << a[m - 1][i] << " ";
            }
            m--;
        }
        if (l < n)
        {
            for (int i = m - 1; i >= k; --i)
            {
                cout << a[i][l] << " ";
            }
            l++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    // vector<vector<int>> a{{1, 2, 3, 4},
    //                       {5, 6, 7, 8},
    //                       {9, 10, 11, 12},
    //                       {13, 14, 15, 16}};

    // for (int x : spiralOrder(a))
    // {
    //     cout << x << " ";
    // }

    int a[3][6] = {{1, 2, 3, 4, 5, 6},
                   {7, 8, 9, 10, 11, 12},
                   {13, 14, 15, 16, 17, 18}};

    spiralPrint2(3, 6, a);
    return 0;
}
