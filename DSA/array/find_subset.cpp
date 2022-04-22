#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;
// 1.bruteforce
// 2.sorting and binerysearch
// 3.sorting and pointers
void Find_subset2(int a[], int b[], int n1, int n2)
{
    sort(a, a + n1);
    sort(b, b + n2);
    int c = 0;
    int i = 0;
    int j = 0;
    while (i < n1 && j < n2)
    {
        while (a[i] < b[j])
        {
            i++;
        }
        if (a[i] == b[j])
        {
            i++;
            j++;
            c++;
        }
        if (a[i] > b[j])
        {
            break;
        }
    }
    if (c == n2)
        cout << "yes";
    else
        cout << "no";
}

// 4.hash method
void Find_subset(int a1[], int a2[], int n1, int n2)
{
    int c = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n1; i++)
    {
        m[a1[i]]++;
    }
    for (int i = 0; i < n2; i++)
    {
        if (m[a2[i]] > 0)
        {
            c++;
        }
    }
    if (c == n2)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    int a[] = {1, 3, 3, 5, 6, 7};
    int b[] = {1, 3, 6, 7};
    Find_subset2(a, b, 6, 4);
    return 0;
}
