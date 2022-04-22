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

void reverse_array_by_r(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    swap(arr[start], arr[end]);
    reverse_array_by_r(arr, start + 1, end - 1);
}
void next_permutation(int a[], int n)
{
    cout << "*";
    N;
    int idx;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i - 1] < a[i])
        {
            idx = i;
            break;
        }
    }
    int x = 9999;
    int next_index;

    if (idx != 0)
    {
        for (int j = idx; j < n; j++)
        {
            if (a[idx - 1] < a[j])
            {
                x = min(x, a[j]);
                if (x == a[j])
                {
                    next_index = j;
                }
            }
        }
        swap(a[idx - 1], a[next_index]);
    }
    reverse_array_by_r(a, idx, n - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    int a[] = {3, 2, 1};
    next_permutation(a, 3);
    for (int i = 0; i < 3; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}