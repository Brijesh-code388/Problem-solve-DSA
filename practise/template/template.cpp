
#include <bits/stdc++.h>
using namespace std;
#define mode 1000000007
#define ll long long int
ll power(ll a, ll b)
{
    ll re = 1;
    a = a % mode;

    while (b)
    {
        if (b & 1)
            re = (re * a) % mode;
        a = (a * a) % mode;
        b = b >> 1;
    }
    return re % mode;
}

int32_t main()
{

    int t;
    cin >> t;

    time_t start, end;

    time(&start);

    time(&end);
    double time_taken = double(end - start);

    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl
         << endl;

    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        cout << ans % mode << endl;
    }
    return 0;
}