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
void merge(int a1[], int a2[], int n1, int n2)
{
    int i = 0, j = 0;
    while (n1 > 0)
    {
        if (a1[i] > a2[j])
        {
            swap(a1[i], a2[j]);
        }
        i++;
        n1--;
        for (int k = 0; k < n2 - 1; k++)
        {
            for (int p = 0; p < n2 - k - 1; p++)
            {
                if (a2[j] > a2[j + 1])
                {
                    swap(a2[j], a2[j + 1]);
                }
            }
        }
    }

    cout << i;
    N;
    cout << j;
    N;
    for (int m = 0; m < i; m++)
    {
        cout << a1[m] << " ";
    }
    for (int m = 0; m < n2; m++)
    {
        cout << a2[m] << " ";
    }
}
// 2nd method
void rotate(int a[], int l, int r)
{
    int i = l;
    int j = r;
    while (i != j)
    {
        swap(a[i], a[j]);
        i++;
    }
}
void merge1(int a1[], int a2[], int n1, int n2)
{
    for (int i = n2 - 1; i >= 0; i--)
    {
        for (int j = 0; j < n1; j++)
        {
            int l = a1[n1 - 1];
            if (a2[i] < a1[j])
            {
                rotate(a1, j, n1 - 1);
                a1[j] = a2[i];
                a2[i] = l;
            }
        }
        N;
    }
}
int nextGap(int gap)
{
    if (gap <= 1)
    {
        return 0;
    }
    return (gap / 2 + gap % 2);
}
void merge2(int a1[], int a2[], int n, int m)
{
    int gap = n + m;
    int i = 0;
    int j = 0;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {
        cout << gap << "..............................";
        N;
        for (i = 0; n > i + gap; i++)
        {

            // cout << i << "............";
            // N;
            cout << a1[i] << " * " << a1[i + gap];
            if (a1[i] > a1[i + gap])
            {
                swap(a1[i], a1[i + gap]);
            }
            N;
        }
        for (j = (gap > n) ? (gap - n) : 0; i < n && j < m; i++, j++)
        {
            if (a1[i] > a2[j])
            {
                swap(a1[i], a2[j]);
            }
            cout << a1[i] << " ** " << a2[j];
            N;
        }
        if (j < m)
        {
            for (int j = 0; j + gap < m; j++)
            {
                cout << a2[j] << " *** " << a2[j + gap];
                if (a2[j] > a2[j + gap])
                {
                    swap(a2[j], a2[j + gap]);
                }
                N;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    int a1[] = {1, 7, 9};
    int a2[] = {2, 6, 8};
    merge2(a1, a2, 3, 3);

    // for (int m = 0; m < 3; m++)
    // {
    //     cout << a1[m] << " ";
    // }
    // for (int m = 0; m < 3; m++)
    // {
    //     cout << a2[m] << " ";
    // }
    // rotate(a1, 0, 2);
    // rotate(a1, 0, 2);
    // for (int m = 0; m < 3; m++)
    // {
    //     cout << a1[m] << " ";
    // }
    return 0;
}