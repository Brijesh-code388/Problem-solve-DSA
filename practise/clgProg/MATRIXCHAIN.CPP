#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, s[10][10];
void display_m(int i, int j)
{
    if (i == j)
    {
        cout << " "
             << "A" << i << " ";
    }
    else
    {
        cout << "(";
        display_m(i, s[i][j]);
        display_m(s[i][j] + 1, j);
        cout << ")";
    }
}
int main()
{
    int i, j, k, len, diff = 0, q;
    cin >> n;
    int p[n + 1], m[n + 1][n + 1];
    for (i = 0; i <= n; i++)
            cin >> p[i];
    
    for (i = 1; i <= n; i++)
        m[i][i] = 0;
    for (len = 2; len <= n; len++)
    {
        for (i = 1; i <= n - len + 1; i++)
        {
            j = i + len - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
                {
                    q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k]) * p[j];
                    if (q < m[i][j])
                    {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
        }
    }
    cout << m[1][n];
    cout << "\n";
    display_m(1, n);

    cout<<endl;

    for(int i=0;i<n+1;i++){
        for(int i=0;i<n+1;i++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
