#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>
#define N cout << endl;
using namespace std;

bool find_full(string a[], int i, int j, int count, string w, int n)
{
    if (count == w.length())
    {
        return true;
    }
    if (i == -1 || i == n || j == -1 || j == n || a[i][j] != w[count])
    {
        return false;
    }
    char temp = a[i][j];
    a[i][j] = '*';
    bool found = find_full(a, i + 1, j, count + 1, w, n) ||
                 find_full(a, i - 1, j, count + 1, w, n) ||
                 find_full(a, i, j + 1, count + 1, w, n) ||
                 find_full(a, i, j - 1, count + 1, w, n);
    a[i][j] = temp;
    if (found == 1)
    {
        cout << "(" << i << "," << j << ")";
        N;
    }
    return found;
}

void exist(string a[], string w, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == w[0])
            {
                if (find_full(a, i, j, 0, w, n))
                {
                    N;
                    count++;
                }
            }
        }
    }
    cout << count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    string a[] = {"BBABBM",
                  "CBMBBA",
                  "IBABBG",
                  "GOZBMI",
                  "ACIGAC",
                  "MCIGAM"};
    string w = "MAGIC";
    reverse(w.begin(), w.end());
    // cout << w;
    exist(a, w, 6);

    return 0;
}
