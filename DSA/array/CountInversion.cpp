#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;
#define S cout << "*" << endl;
#define SS cout << "**" << endl;
// naive approach
void countInverse(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                count++;
            }
        }
    }
    cout << count;
}

// by merge sort
int merge(int a[], int temp[], int left, int mid, int right)
{
    int i, j, k, inv = 0;
    i = left;
    j = mid;
    k = left; // thinkable subject;
    while (i <= mid - 1 && j <= right)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
            cout << mid << "*" << i;
            N;
            inv = inv + (mid - i);
        }
    }
    while (i <= mid - 1)
    {
        temp[k++] = a[i++];
    }
    while (j <= right)
    {
        temp[k++] = a[j++];
    }
    for (int m = left; m <= right; m++)
    {
        a[m] = temp[m];
    }
    return inv;
}

int mergeSort(int a[], int temp[], int left, int right)
{
    int inv = 0;
    if (left < right)
    {
        int mid = (left + right) / 2;
        cout << left << "_" << mid << "_" << right;
        N;
        inv += mergeSort(a, temp, left, mid);
        inv += mergeSort(a, temp, mid + 1, right);
        cout << left << "___" << mid << "___" << right;
        N;
        inv += merge(a, temp, left, mid + 1, right);
        cout << "*" << inv;
        N;
    }
    return inv;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    int a[] = {1, 4, 3, 2, 5, 8, 9, 20};
    int n = 8;
    // countInverse(a, n);
    // N;
    int temp[n];
    cout << mergeSort(a, temp, 0, n - 1);
    N;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}