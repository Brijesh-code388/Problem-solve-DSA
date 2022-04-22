#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;

int maxProfit(int p[], int n) // on double pass
{
    int maxprofit = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int profit = p[j] - p[i];
            if (profit > maxprofit)
                maxprofit = profit;
        }
    }
    return maxprofit;
}
int maxProfit2(int p[], int n) // on single pass
{
    int maxpro = 0;
    int minPrize = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (p[i] < minPrize)
        {
            minPrize = p[i];
        }
        else if (p[i] - minPrize > maxpro)
        {
            maxpro = p[i] - minPrize;
        }
    }
    return maxpro;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    int a[] = {7, 6, 4, 3, 1};
    cout << maxProfit(a, 5);
    N;
    cout << maxProfit2(a, 5);

    return 0;
}