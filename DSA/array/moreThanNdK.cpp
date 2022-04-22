#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;
#define S cout << "*" << endl;

// Given an array of size n and a number k, fin all elements that appear more than " n/k " times.

// 1.bruteforce n^2
// 2.by sorting nlogn
// 3.by hash map o(n)
void Morethan_nbyk(int a[], int n, int k)
{
    unordered_map<int, int> m;
    int x = n / k;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
        if (m[a[i]] >= x)
        {
            count++;
            cout << a[i] << endl;
            m[a[i]] = -1000;
        }
    }
    cout << "ans = " << count;
}

// method : time o(nk)
// space o(k)
struct eleCount
{
    int e; // Element
    int c; // Count
};
void moreThanNdK(int arr[], int n, int k)
{
    // k must be greater than
    // 1 to get some output
    if (k < 2)
        return;

    /* Step 1: Create a temporary
       array (contains element
       and count) of size k-1.
       Initialize count of all
       elements as 0 */
    struct eleCount temp[k - 1];
    for (int i = 0; i < k - 1; i++)
        temp[i].c = 0;

    /* Step 2: Process all
      elements of input array */
    for (int i = 0; i < n; i++)
    {
        int j;

        /* If arr[i] is already present in
           the element count array,
           then increment its count
         */
        for (j = 0; j < k - 1; j++)
        {
            if (temp[j].e == arr[i])
            {
                temp[j].c += 1;
                break;
            }
        }

        /* If arr[i] is not present in temp[] */
        if (j == k - 1)
        {
            int l;

            /* If there is position available
              in temp[], then place arr[i] in
              the first available position and
              set count as 1*/
            for (l = 0; l < k - 1; l++)
            {
                if (temp[l].c == 0)
                {
                    temp[l].e = arr[i];
                    temp[l].c = 1;
                    break;
                }
            }

            /* If all the position in the
               temp[] are filled, then decrease
               count of every element by 1 */
            if (l == k - 1)
                for (l = 0; l < k - 1; l++)
                    temp[l].c -= 1;
        }
    }

    /*Step 3: Check actual counts of
     * potential candidates in temp[]*/
    for (int i = 0; i < k - 1; i++)
    {
        // Calculate actual count of elements
        int ac = 0; // actual count
        for (int j = 0; j < n; j++)
            if (arr[j] == temp[i].e)
                ac++;

        // If actual count is more than n/k,
        // then print it
        if (ac > n / k)
            cout << "Number:" << temp[i].e
                 << " Count:" << ac << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    int a[] = {3, 1, 4, 5, 1, 2, 3, 3};
    int k = 5;
    moreThanNdK(a, 8, k);
    return 0;
}
