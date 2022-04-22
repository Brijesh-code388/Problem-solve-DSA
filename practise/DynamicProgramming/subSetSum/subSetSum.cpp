//problem of find the sub set possible in given number to make sum .
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    int wt;

    memset(arr, -1, sizeof(arr));

    cout << "Add element" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    // cout << "sum @@@" << endl;
    // cin >> wt;
    cout << sum;
    cout << endl;
    wt = sum;

    int dp[n + 1][wt + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < wt + 1; j++)
        {
            dp[i][j] = 0;
        }
    }

    //print of first
    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < wt + 1; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for (int j = 0; j < wt + 1; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < wt + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
            // for(int i=0;i<n+1;i++)
            // {
            //     for(int j=0;j<wt+1;j++)
            //     {
            //          cout<<dp[i][j]<<" ";
            //     }
            //     cout<<endl;
            //}
            // cout<<endl;
        }
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < wt + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    //////////////////////////////
    int ans[wt + 1];
    memset(ans, 0, sizeof(ans));

    for (int j = 0; j < wt + 1; j++)
    {
        if (j >= 10)
            cout << j << " ";

        if (j < 10)
            cout << j << "  ";
    }
    cout << endl;
    int c = 0;
    for (int j = 0; j < wt + 1; j++)
    {
        if (dp[n][j] > 0)
        {
            ans[j] = 1;
            c++;
        }
        cout << ans[j] << "  ";
    }
    //cout << sizeof(ans) / 4;
    int a[c];
    int x = 0;
    for (int j = 0; j < wt + 1; j++)
    {
        if (ans[j] == 1)
        {
            a[x] = j;
            x++;
        }
    }
    cout << endl;
    for (int j = 0; j < c; j++)
    {
        cout << a[j] << " ";
    }
    cout << endl;
    cout << c << endl;

    if (c % 2 == 0)
    {

        cout << (a[c / 2]) - (a[c / 2 - 1]);
    }
    else
    {
        cout << endl
             << c / 2;
    }

    return 0;
}