
#include <bits/stdc++.h>
using namespace std;
#define mode 1000000007
#define int long long int

int32_t main()
{
    //time_t start, end;
    clock_t start, end;

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
    }
    //  for (int i = 0; i < n; i++)
    //  {
    //      cout << a[i] << " ";
    //  }
    cout << endl;
    //time(&start);
    start=clock();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    // time(&end);
    end=clock();
    double time_taken = double(end - start);

    //  for (int i = 0; i < n; i++)
    //  {
    //      cout << a[i] << " ";
    //  }
     cout<<endl;
    cout << "Time taken by program is : " << fixed
         << time_taken <<setprecision(6);
    cout  << endl;

    return 0;
}