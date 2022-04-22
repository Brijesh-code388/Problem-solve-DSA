#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;

int min_jump(int a[], int n)
{
    int dp[n];
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = INT_MAX;
        // cout << "i = " << jump[i];
        // cout << endl;
        for (int j = 0; j < i; j++)
        {
            if (dp[j] != INT_MAX)
                if (a[j] + j >= i)
                {
                    if (dp[j] + 1 < dp[i])
                        dp[i] = dp[j] + 1;
                }
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << jump[i] << " ";
    // }
    return (dp[n - 1] != INT_MAX) ? dp[n - 1] : -1;
}

int max(int x, int y)
{
    return (x > y) ? x : y;
}

// Returns minimum number of jumps
// to reach arr[n-1] from arr[0]
int minJumps(int arr[], int n)
{

    // The number of jumps needed to
    // reach the starting index is 0
    if (n <= 1)
        return 0;

    // Return -1 if not possible to jump
    if (arr[0] == 0)
        return -1;

    // initialization
    // stores all time the maximal
    // reachable index in the array.
    int maxReach = arr[0];

    // stores the number of steps
    // we can still take
    int step = arr[0];

    // stores the number of jumps
    // necessary to reach that maximal
    // reachable position.
    int jump = 1;

    // Start traversing array
    int i = 1;
    for (i = 1; i < n; i++)
    {
        // Check if we have reached the end of the array
        if (i == n - 1)
            return jump;

        // updating maxReach
        maxReach = max(maxReach, i + arr[i]);
        cout << step << " " << maxReach << " ";

        // we use a step to get to the current index
        step--;
        // If no further steps left
        if (step == 0)
        {
            // we must have used a jump
            jump++;
            cout << "jump on index " << i;

            // Check if the current index/position or lesser index
            // is the maximum reach point from the previous indexes
            if (i >= maxReach)
                return -1;

            // re-initialize the steps to the amount
            // of steps to reach maxReach from position i.
            step = maxReach - i;
        }
        cout << " " << step << " ";

        N;
    }

    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 3, 2, 2, 6, 7, 6, 8, 9};
    int arr1[] = {1, 4, 3, 2, 6, 7};

    cout << min_jump(arr, 11);
    N;
    cout << minJumps(arr, 11);
    return 0;
}