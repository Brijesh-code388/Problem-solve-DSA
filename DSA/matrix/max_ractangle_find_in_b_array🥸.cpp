#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>
#define N cout << endl;
#define MAX 5
using namespace std;

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void print_array2(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void find_prev_smaller_element(int a[], int store[], int m)
{

    stack<int> stack;

    for (int i = 0; i < m; i++)
    {
        // store[i] = -1;
        while (!stack.empty() && a[stack.top()] >= a[i])
        {
            stack.pop();
        }
        if (stack.empty())
        {
            store[i] = -1;
        }
        else if (a[stack.top()] < a[i])
        {

            store[i] = stack.top();
        }
        stack.push(i);
    }
}
void find_next_smaller_element(int a[], int store[], int m)
{
    stack<int> stack;
    for (int i = m - 1; i >= 0; i--)
    {
        // store[i] = -1;
        while (!stack.empty() && a[stack.top()] >= a[i])
        {
            stack.pop();
        }

        if (stack.empty())
        {
            store[i] = m;
        }
        else
        {
            store[i] = stack.top();
        }

        stack.push(i);
    }
}
int find_max_rect_from_histo(int a[], int m)
{
    int fp[m];
    find_prev_smaller_element(a, fp, m);
    // print_array(a, fp, m);
    int fn[m];
    find_next_smaller_element(a, fn, m);
    // print_array(a, fn, m);
    int max = 0;
    for (int i = 0; i < m; i++)
    {

        max = std::max((fn[i] - fp[i] - 1) * a[i], max);
    }
    return max;
}

void find_max_size_ractangle(int a[][4], int n, int m)
{
    int histo[m];
    for (int j = 0; j < m; j++)
    {
        histo[j] = 0;
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 1)
                histo[j]++;
            else
                histo[j] = 0;
        }

        max = std::max(find_max_rect_from_histo(histo, m), max);
    }
    cout << max;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    int a[][4] = {{1, 1, 1, 1},
                  {1, 1, 1, 1},
                  {1, 1, 1, 1},
                  {1, 1, 1, 1}};
    int n = 4, m = 4;
    find_max_size_ractangle(a, n, m);
    N;

    // int b[] = {2, 3, 3, 2};
    // // int c[] = {1, 4, 4, 3, 2, 1};
    // int x[4];
    // int y[4];

    // find_prev_smaller_element(b, x, 4);
    // print_array(b, 4);
    // print_array(x, 4);

    // N;
    // find_next_smaller_element(b, y, 4);
    // print_array(b, 4);
    // print_array(y, 4);
    // int max = 0;
    // for (int i = 0; i < m; i++)
    // {

    //     max = std::max(abs(y[i] - x[i] - 1) * b[i], max);
    //     cout << "maxxx " << max << " ";
    // }

    return 0;
}
