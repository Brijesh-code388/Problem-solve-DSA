#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;
// it count all ideal profit without limited transaction
void MaxProfit(int a[], int n)
{
    int profit = 0;
    int max = a[n - 1];
    int min = a[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > a[i + 1])
        {
            max = a[i];
        }
        if (a[i] < a[i + 1])
        {
            min = a[i];
        }

        if ((a[i - 1] > a[i]) && (a[i] < a[i + 1]))
        {
            profit += (max - min);
            max = a[i - 1];
            min = a[i - 1];
            i--;
        }
    }
    cout << "all ideal profit without limited transaction: " << profit;
}
// it count only 2 time transaction max profit
//  using Dynamic Programming
int maxProfit(int price[], int n)
{
    // Create profit array and
    // initialize it as 0
    int *profit = new int[n];
    for (int i = 0; i < n; i++)
        profit[i] = 0;

    /* Get the maximum profit with
       only one transaction
       allowed. After this loop,
       profit[i] contains maximum
       profit from price[i..n-1]
       using at most one trans. */
    int max_price = price[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        // max_price has maximum
        // of price[i..n-1]
        if (price[i] > max_price)
            max_price = price[i];

        // we can get profit[i] by taking maximum of:
        // a) previous maximum, i.e., profit[i+1]
        // b) profit by buying at price[i] and selling at
        //    max_price
        profit[i] = max(profit[i + 1], max_price - price[i]);
    }

    /* Get the maximum profit with two transactions allowed
       After this loop, profit[n-1] contains the result */
    int min_price = price[0];
    for (int i = 1; i < n; i++)
    {
        // min_price is minimum price in price[0..i]
        if (price[i] < min_price)
            min_price = price[i];

        // Maximum profit is maximum of:
        // a) previous maximum, i.e., profit[i-1]
        // b) (Buy, Sell) at (min_price, price[i]) and add
        //    profit of other trans. stored in profit[i]
        profit[i] = max(profit[i - 1],
                        profit[i] + (price[i] - min_price));
    }
    int result = profit[n - 1];

    delete[] profit; // To avoid memory leak

    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    int price[] = {3, 5, 0, 1, 4, 0, 5};
    // int price[] = {2, 30, 15, 10, 8, 25, 80};
    int n = sizeof(price) / sizeof(price[0]);
    cout << maxProfit(price, n);
    N;
    MaxProfit(price, n);

    return 0;
}
