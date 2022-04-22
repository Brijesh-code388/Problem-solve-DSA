#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;
// 1.bruteforce n^3
// 2.hashing n^2 and space n
void find_tripplate_sum(int a[], int n, int x)
{
    int res = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int k = x - (a[i] + a[j]);
            if (m[k] > 0)
            {
                res = 1;
                break;
            }
        }
    }
    if (res == 1)
        cout << "yes";
    else
        cout << "no";
}

// 3.sorting and two pointer n^2 and o(1)space
void find_tripplate_sum2(int a[], int n, int x)
{
    sort(a, a + n);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int l = 0;
        int r = n - 1;
        while (l < r)
        {
            if (a[i] + a[l] + a[r] == x)
            {
                res = 1;
                break;
            }
            else if (a[i] + a[l] + a[r] < x)
            {
                l++;
            }
            else if (a[i] + a[l] + a[r] > x)
            {
                r--;
            }
        }
    }
    if (res == 1)
        cout << "yes";
    else
        cout << "no";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    int a[] = {1, 3, 3, 5, 6, 7};
    int b[] = {1, 3, 6, 7};
    find_tripplate_sum2(a, 6, 13756);
    return 0;
}
