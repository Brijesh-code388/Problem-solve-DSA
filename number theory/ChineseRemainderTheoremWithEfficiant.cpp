#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;
// by euclidean Method in o(logm)
int inv(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    // Apply extended Euclid Algorithm
    while (a > 1)
    {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now, process same aseuclid's algo
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

int gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int InvUsingGcd(int a, int m)
{
    int x, y;
    int g = gcd(a, m, x, y);
    if (g != 1)
    {
        return 0;
    }
    else
    {
        int ans = (x % m + m) % m;
        cout << ans << endl;
        return ans;
    }
}

// Naive Approach in o(m)
int InverseModulo(int a, int m)
{
    for (int i = 1; i < m; i++)
    {
        if (((a % m) * (i % m)) % m == 1)
        {
            return i;
        }
    }
    return 0;
}
int findchineseReminderWithInverseModulo(int num[], int rem[], int k)
{
    // Compute product of all numbers
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];

    // Initialize result
    int result = 0;

    // Apply above formula
    for (int i = 0; i < k; i++)
    {
        int pp = prod / num[i];
        int x = InverseModulo(pp, num[i]);
        // cout << x << endl;
        result += rem[i] * x * pp;
    }
    // cout << result << endl;
    return result % prod;
}
int findchineseReminder(int num[], int rem[], int k)
{
    int x = 1;

    while (true)
    {
        int i;
        for (i = 0; i < k; i++)
        {
            if (x % num[i] != rem[i])
            {
                break;
            }
        }
        if (i == k)
        {
            return x;
        }
        x++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);

    int num[] = {3, 4, 5};
    int rem[] = {2, 3, 1};
    int k = 3;
    cout << findchineseReminderWithInverseModulo(num, rem, k);
    return 0;
}
