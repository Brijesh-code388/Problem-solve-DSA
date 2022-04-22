#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;
#define S cout << "*" << endl;

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void do_alternative_without_order(int arr[], int n)
{
    // do posotive and negative on side;
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        while (arr[l] >= 0 && l < r)
        {
            l++;
        }

        while (arr[r] < 0 && l < r)
        {
            r--;
        }
        if (l < r)
        {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }
    cout << l << " " << r;
    N;
    // now maintain the alternative
    if (arr[r] > 0)
    {
        r++;
    }
    if (arr[l] > 0)
    {
        l++;
    }
    cout << l << " " << r;
    N;
    int left = 0;
    int right = r;
    while (left < l && right <= n - 1)
    {
        if (arr[left] > 0)
        {
            swap(arr[left], arr[right]);
            left += 2;
            right++;
            l++;
        }
    }
}

void rightrotate(int arr[], int n, int wrongPlace, int cur)
{
    char tmp = arr[cur];
    for (int i = cur; i > wrongPlace; i--)
        arr[i] = arr[i - 1];
    arr[wrongPlace] = tmp;
}
void do_alternative_with_order(int arr[], int n)
{
    int wrongPlace = -1;
    for (int index = 0; index < n; index++)
    {
        if (wrongPlace >= 0)
        {
            if ((arr[wrongPlace] >= 0 && arr[index] < 0) || (arr[wrongPlace] < 0 && arr[index] >= 0))
            {
                rightrotate(arr, n, wrongPlace, index);

                if (wrongPlace - index <= 2)
                {
                    wrongPlace += 2;
                }
                else
                {
                    wrongPlace = -1;
                }
            }
        }
        if (wrongPlace == -1)
        {
            if ((arr[index] >= 0 && index % 2 == 0) || (arr[index] < 0 && index % 2 == 1))
            {
                wrongPlace = index;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    int a[] = {-5, 2, 6, -2, -4, -7, -1, 8, 9, -8};
    // do_alternative_without_order(a, 10);
    do_alternative_with_order(a, 10);
    print_array(a, 10);
    return 0;
}