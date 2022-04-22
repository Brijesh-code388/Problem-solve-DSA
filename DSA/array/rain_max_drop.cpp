#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// bruteforce
void maxWater(int arr[], int n)
{

    // To store the maximum water
    // that can be stored
    int res = 0;

    // For every element of the array
    for (int i = 1; i < n - 1; i++)
    {

        // Find the maximum element on its left
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);

        // Find the maximum element on its right
        int right = arr[i];
        for (int j = i + 1; j < n; j++)
            right = max(right, arr[j]);

        // Update the maximum water
        res = res + (min(left, right) - arr[i]);
    }

    cout << res;
}

// in o(n) and space o(n)
void find_max_rain_block(int arr[], int n)
{
    int left[n];

    int right[n];

    int water = 0;

    left[0] = arr[0];
    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);

    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);

    for (int i = 0; i < n; i++)
        water += min(left[i], right[i]) - arr[i];
    cout << water;
}
// o(n) and space o(1)
void find_max_rain_block2(int a[], int n)
{
    int l = 0;
    int r = n - 1;
    int maxl = 0;
    int maxr = 0;
    int sum = 0;
    while (l < r)
    {
        if (a[l] < a[r])
        {
            if (a[l] > maxl)
            {
                maxl = a[l];
            }
            else
            {
                sum = sum + (maxl - a[l]);
            }
            l++;
        }
        else
        {
            if (a[r] > maxr)
            {
                maxr = a[r];
            }
            else
            {
                sum = sum + (maxr - a[r]);
            }
            r--;
        }
    }
    cout << sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    int a[] = {3, 0, 2, 1, 0, 4};
    find_max_rain_block2(a, 6);
    return 0;
}
