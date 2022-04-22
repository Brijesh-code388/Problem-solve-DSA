#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// two pointer with for loop uniq;
void threeWayPartition(int arr[], int n, int a, int b)
{
    int l = 0;
    int r = n - 1;
    for (int i = 0; i <= r; i++)
    {
        if (arr[i] < a)
        {
            swap(arr[i], arr[l]);
            l++;
        }
        else if (arr[i] > b)
        {
            swap(arr[i], arr[r]);
            r--;
            i--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87,
                 98, 3, 1, 32};
    int n = sizeof(arr) / sizeof(arr[0]);

    threeWayPartition(arr, n, 10, 20);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}