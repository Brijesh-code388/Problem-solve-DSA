#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;

// in this approach tc->o(n)
void find_median(int a[], int b[], int n)
{
    int i = 0;
    int j = 0;
    int m1 = -1;
    int m2 = -1;
    // it's like merge sort merge but upto n
    for (int c = 0; c <= n; c++)
    {
        if (i == n)
        {
            m1 = m2;
            m2 = b[0];
            break;
        }
        else if (j == n)
        {
            m1 = m2;
            m2 = a[0];
            break;
        }
        if (a[i] <= b[j])
        {
            m1 = m2;
            m2 = a[i];
            i++;
        }
        else
        {
            m1 = m2;
            m2 = b[j];
            j++;
        }
    }
    cout << (float)((m1 + m2) / 2);
}

// now very optimal solution for find median of two same size array after mergeing
// o(log(n))
int median(int arr[], int s, int e)
{
    return (arr[(s + e) / 2] + arr[(s + e + 1) / 2]) / 2;
}
int find_median(int a[], int b[], int Sa, int Sb, int Ea, int Eb)
{
    if (Ea - Sa <= 1)
        return (max(a[Sa], b[Sb]) + min(a[Ea], b[Eb])) / 2;
    int m1 = median(a, Sa, Ea);
    int m2 = median(b, Sb, Eb);
    if (m1 == m2)
        return m1;
    if (m1 > m2)
        return find_median(a, b, Sa, (Sb + Eb + 1) / 2, (Sa + Ea + 1) / 2, Eb);
    return find_median(a, b, (Sa + Ea + 1) / 2, Sb, Ea, (Sb + Eb + 1) / 2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {2, 4, 6, 7, 8};
    // find_median(a, b, 5);
    int n = 5;
    cout << find_median(a, b, 0, 0, n - 1, n - 1);
    return 0;
}
