#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;
#define S cout << "*" << endl;
// method 1 n^2;
void find_subarray(int a[], int n)
{
    int f = 0;
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = i + 1; j < n; j++)
        {
            s += a[j];
            if (s == 0)
            {
                f = 1;
                break;
            }
        }
        if (f == 1)
            break;
    }
    if (f == 1)
        cout << "possible";
    else
        cout << "not possible";
}
// method 2 o(n);
void find_subarray2(int a[], int n)
{
    int f = 0;
    int s = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        s = s + a[i];
        if (s == 0 || m[s] == 1 || a[i] == 0)
        {
            f = 1;
            break;
        }
        else
        {
            m[s] = 1;
        }
    }
    if (f == 1)
        cout << "possible";
    else
        cout << "not possible";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    int a[] = {4, 2, -3, 1, 6};
    find_subarray2(a, 5);
    return 0;
}
