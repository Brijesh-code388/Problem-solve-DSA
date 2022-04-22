#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;

// method 1:bruteforce
void Find_sum_gtr_x_subarray(int a[], int n, int x)
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int s = a[i];
        for (int j = i + 1; j < n; j++)
        {
            s += a[j];
            if (s > x)
            {
                min = std::min(min, j - i + 1);
            }
        }
    }
    cout << min << endl;
}

// method 2:o(n)
void Find_sum_gtr_x_subarray2(int a[], int n, int x)
{
    int min = INT_MAX;
    int i = 0;
    int j = 0;
    int s = 0;
    while (i <= j && j < n)
    {
        while (s <= x && j < n)
        {
            s += a[j];
            j++;
        }
        while (s > x && i < j)
        {
            min = std::min(min, j - i);
            s = s - a[i];
            i++;
        }
    }

    cout << min << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);

    int a[] = {1, 4, 45, 6, 0, 19};
    int x = 51;
    Find_sum_gtr_x_subarray2(a, 6, x);

    return 0;
}
