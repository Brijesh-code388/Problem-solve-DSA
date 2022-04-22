#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;
#define S cout << "*" << endl;

void Max_product_subarray(int a[], int n)
{
    if (n == 0)
    {
        cout << "0";
        return;
    }
    int res = 0;
    int min = 1, max = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            max *= a[i];
            min = std::min(a[i] * min, 1);
        }
        else if (a[i] == 0)
        {
            min = max = 1;
        }
        else if (a[i] < 0)
        {
            int temp = max;
            max = min;
            min = temp;
            min *= a[i];
            max = std::max(1, max * a[i]);
        }
        res = std::max(res, max);
    }

    cout << res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    int a[] = {6, -3, -10, 0, -2};
    Max_product_subarray(a, 5);
    return 0;
}
