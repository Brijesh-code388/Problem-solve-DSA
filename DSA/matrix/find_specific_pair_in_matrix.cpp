#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>
#define N 5
using namespace std;

void printArray(int a[5][5], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void find_pair_max_min(int mat[][5], int n, int m)
{
    int maxValue = INT_MIN;
    for (int a = 0; a < n - 1; a++)
        for (int b = 0; b < n - 1; b++)
            for (int d = a + 1; d < n; d++)
                for (int e = b + 1; e < n; e++)
                    if (maxValue < (mat[d][e] - mat[a][b]))
                        maxValue = mat[d][e] - mat[a][b];
    cout << maxValue;
    cout << "\n";
}

void findMaxValue(int mat[][N])
{
    // stores maximum value
    int maxValue = INT_MIN;

    // maxArr[i][j] stores max of elements in matrix
    // from (i, j) to (N-1, N-1)
    int maxArr[N][N];

    // last element of maxArr will be same's as of
    // the input matrix
    maxArr[N - 1][N - 1] = mat[N - 1][N - 1];

    // preprocess last row
    int maxv = mat[N - 1][N - 1]; // Initialize max
    for (int j = N - 2; j >= 0; j--)
    {
        if (mat[N - 1][j] > maxv)
            maxv = mat[N - 1][j];
        maxArr[N - 1][j] = maxv;
    }

    // preprocess last column
    maxv = mat[N - 1][N - 1]; // Initialize max
    for (int i = N - 2; i >= 0; i--)
    {
        if (mat[i][N - 1] > maxv)
            maxv = mat[i][N - 1];
        maxArr[i][N - 1] = maxv;
    }

    // preprocess rest of the matrix from bottom
    for (int i = N - 2; i >= 0; i--)
    {
        for (int j = N - 2; j >= 0; j--)
        {
            // Update maxValue
            if (maxArr[i + 1][j + 1] - mat[i][j] > maxValue)
                maxValue = maxArr[i + 1][j + 1] - mat[i][j];

            // set maxArr (i, j)
            maxArr[i][j] = max(mat[i][j],
                               max(maxArr[i][j + 1],
                                   maxArr[i + 1][j]));
        }
    }
    printArray(maxArr, 5, 5);
    cout
        << maxValue;
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    cout << "*";
    int mat[][5] = {{1, 2, -1, -4, -20},
                    {-8, -3, 4, 2, 1},
                    {3, 8, 6, 1, 3},
                    {-4, -1, 1, 7, -6},
                    {0, -4, 10, -5, 1}};
    findMaxValue(mat);
    printArray(mat, 5, 5);
    return 0;
}
