#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>
#define N cout << endl;
#define inf 10000000
using namespace std;

void printIndex(int a[], int n)
{
    if (a[n] == 1)
    {
        cout << a[n] << " " << n << " ";
        N;
    }
    else
    {
        printIndex(a, a[n] - 1);
        cout << a[n] << " " << n;
        N;
    }
}

void find_min_cost_sol(int a[], int n, int k)
{

    // space table
    int space[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        space[i][i] = k - a[i];
        for (int j = i + 1; j <= n; j++)
        {
            space[i][j] = space[i][j - 1] - a[j] - 1;
        }
    }

    // cost table
    int cost[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (space[i][j] < 0)
            {
                cost[i][j] = inf;
            }
            else if (j == n && space[i][j] >= 0)
                cost[i][j] = 0;
            else
            {
                cost[i][j] = space[i][j] * space[i][j];
            }
        }
    }

    // upto min cost upto all line all cost
    int c[n + 1];
    c[0] = 0;
    int index[n + 1];
    for (int i = 1; i <= n; i++)
    {
        c[i] = inf;
        for (int j = 1; j <= i; j++)
        {
            if ((c[j - 1] != inf) && (cost[j][i] != inf) && (c[j - 1] + cost[j][i] < c[i]))
            {
                c[i] = c[j - 1] + cost[j][i];
                index[i] = j;
            }
        }
    }
    printIndex(index, n);

    cout << c[n];

    // find the word per line
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);

    int a[] = {-1, 3, 2, 2, 5};
    int k = 6;
    find_min_cost_sol(a, 4, k);

    return 0;
}
