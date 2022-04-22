#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>
//#define N cout << endl;
using namespace std;

#define M 4
#define N 5

int findCommon(int mat[M][N])
{
    unordered_map<int, int> cnt;

    int i, j;

    for (i = 0; i < M; i++)
    {

        cnt[mat[i][0]]++;

        for (j = 1; j < N; j++)
        {

            if (mat[i][j] != mat[i][j - 1])
                cnt[mat[i][j]]++;
        }
    }

    for (auto ele : cnt)
    {
        if (ele.second == M)
        {
            return ele.first;
        }
    }

    return -1;
}

int find_Common(int a[M][N], int m, int n)
{
    int column[M];
    int min_row;

    for (int i = 0; i < M; i++)
    {
        column[i] = N - 1;
    }

    min_row = 0;

    while (column[min_row] >= 0)
    {
        // find min_row for this column
        for (int i = 0; i < M; i++)
        {
            if ((a[min_row][column[min_row]]) > (a[i][column[i]]))
            {
                min_row = i;
            }
        }

        // re intialize counter
        int counter = 0;

        // if any are equal to column[min_row] than intialize counter otherwise reduce column and loop.
        for (int i = 0; i < M; i++)
        {
            if ((a[min_row][column[min_row]]) < (a[i][column[i]]))
            {
                if (column[i] == 0)
                {
                    return -1;
                }
                column[i]--;
            }
            else
            {
                counter++;
            }
        }
        if (counter == M)
        {
            return a[min_row][column[min_row]];
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);

    int mat[M][N] = {
        {1, 2, 3, 4, 5},
        {2, 4, 5, 8, 10},
        {3, 5, 7, 9, 11},
        {1, 3, 5, 7, 9},
    };
    int result = findCommon(mat);
    cout << result;

    find_Common(mat, M, N);
    return 0;
}
