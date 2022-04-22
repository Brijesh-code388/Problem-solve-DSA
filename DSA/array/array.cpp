	#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void reverse_array(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        // int temp = arr[start];
        // arr[start] = arr[end];
        // arr[end] = temp;
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
void reverse_array_by_r(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    swap(arr[start], arr[end]);
    reverse_array_by_r(arr, start + 1, end - 1);
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void find_min_max(int arr[], int n)
{
    int min = INT_MAX;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout << min << " " << max << endl;
}
void find_kth_min(int arr[], int n, int k)
{
    // we can also find with the heap and merge sort
    // and also sum advance median method
    set<int> s(arr, arr + n);
    set<int>::iterator itr = s.begin();
    advance(itr, k - 1);

    cout << *itr << "\n";
}

int part(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    int j = l;
    for (j = l; j < r; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // cout << i + 1 << endl;
    // print_array(arr, 5);
    swap(arr[i + 1], arr[r]);
    // print_array(arr, 5);
    return i + 1;
}

int partition(int arr[], int l, int r)
{
    int p = ((r - l) / 2) + l;
    // print_array(arr, 5);

    swap(arr[p], arr[r]);
    return part(arr, l, r);
}
int find_kth_smallest_parition(int arr[], int l, int r, int k)
{
    if (l <= r)
    {
        int q = partition(arr, l, r);
        // cout << q << endl;
        int n = q - l + 1;
        if (k == n)
        {
            // cout << q << endl;
            return q;
        }
        else if (k < n)
        {
            return find_kth_smallest_parition(arr, l, q - 1, k);
        }
        else
        {
            return find_kth_smallest_parition(arr, q + 1, r, k - n);
        }
    }
    else
    {
        return INT_MAX;
    }
}

void sort_without_sort_01(int arr[], int l, int r)
{
    int n = r - l + 1;
    while (l < r)
    {
        while (arr[l] == 0 && l < r)
        {
            l++;
        }
        while (arr[r] == 1 && l < r)
        {
            r--;
        }
        if (l < r)
        {
            arr[l] = 0;
            arr[r] = 1;
            l++;
            r--;
        }
    }
}
void sort_without_sort_012(int a[], int size)
{
    int lo = 0;
    int hi = size - 1;
    int mid = 0;

    // Iterate till all the elements
    // are sorted
    while (mid <= hi)
    {
        switch (a[mid])
        {

        // If the element is 0
        case 0:
            swap(a[lo++], a[mid++]);
            break;

        // If the element is 1 .
        case 1:
            mid++;
            break;

        // If the element is 2
        case 2:
            swap(a[mid], a[hi--]);
            break;
        }
    }
}

void move_negative_oneside(int arr[], int l, int r)
{
    while (l < r)
    {
        while (arr[l] > 0 && l < r)
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
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
void find_union(int a[], int b[], int as, int bs)
{
    if (as < bs)
    {
        int *temp = a;
        a = b;
        b = temp;

        int t = as;
        bs = as;
        as = t;
    }
    for (int i = 0; i < as; i++)
    {
        cout << a[i] << " ";
    }

    for (int i = 0; i < bs; i++)
    {
        int find = binarySearch(b, 0, bs - 1, a[i]);
        if (find == -1)
        {
            cout << b[i] << " ";
        }
    }
}
void find_insertion(int a[], int b[], int as, int bs)
{
    if (as < bs)
    {
        int *temp = a;
        a = b;
        b = temp;

        int t = as;
        bs = as;
        as = t;
    }
    for (int i = 0; i < bs; i++)
    {
        int find = binarySearch(b, 0, bs - 1, a[i]);
        if (find != -1)
        {
            cout << b[i] << " ";
        }
    }
}

void rotate(int a[], int size, int k)
{
    for (int p = 0; p < k; p++)
    {
        int i = 0;
        int j = size - 1;
        while (i != j)
        {
            swap(a[i], a[j]);
            i++;
        }
    }
}

int Largest_sum_contiguous_Subarray(int a[], int size)
{
    int max_here = 0, max_so_far = 0;
    for (int i = 0; i < size; i++)
    {
        max_here += a[i];
        if (max_here < 0)
        {
            max_here = 0;
        }
        if (max_here > max_so_far)
        {
            max_so_far = max_here;
        }
    }
    return max_so_far;
}

int get_Min_Height(int a[], int n, int k)
{
    int ans = 0;
    if (n == 1)
    {
        return 0;
    }
    sort(a, a + n);
    vector<pii> t;
    map<int, int> m;
    int n_ = 1;
    t.push_back(pii(a[0] + k, a[0]));
    t.push_back(pii(a[0] - k, a[0]));
    m[a[0]] = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
        {
            t.push_back(pii(a[i] + k, a[i]));
            t.push_back(pii(a[i] - k, a[i]));
            m[a[i]] = 0;
            n_++;
        }
    }
    cout << "brij" << n_ << "esh";
    sort(t.begin(), t.end());

    map<int, int>::iterator itr;
    for (itr = m.begin(); itr != m.end(); ++itr)
    {
        cout << '\t' << itr->first
             << '\t' << itr->second << '\n';
    }
    int l = 0, r = 0;
    ans = t[t.size() - 1].first - t[0].first;
    // cout << "**" << ans;
    int count = 0;

    while (r < t.size())
    {
        while (r < t.size() && count < n_)
        {
            if (m[t[r].second] == 0)
            {
                count++;
            }
            m[t[r].second]++;
            r++;
        }
        cout << "brij" << r << "esh" << l << endl;

        if (r == t.size() and count < n_)
            break;
        if (t[r - 1].first >= 0 && t[l].first >= 0)
        {
            ans = min(ans, t[r - 1].first - t[l].first);
            cout << ans << "brijesh  ";
        }

        while (l <= r and count >= n_)
        {
            if (m[t[l].second] == 1)
            {
                count--;
            }
            m[t[l].second]--;
            cout << "r=" << r << "l=" << l << endl;
            if (t[r - 1].first >= 0 && t[l].first >= 0)
            {
                ans = min(ans, t[r - 1].first - t[l].first);
                cout << ans << "brijesh*  ";
            }

            l++;
        }
    }
    return ans;
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    //  freopen("./inputf.in", "r", stdin);
    //  freopen("./outputf.out", "w", stdout);

    // int arr[] = {2, 3, 5, 1, 8};
    // int zo[] = {0, 1, 1, 1, 0, 0, 0};
    // int zot[] = {0, 1, 1, 0, 2, 1, 1, 2};
    // int b[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // int zo_n = sizeof(zo) / sizeof(zo[0]);
    // int zot_n = sizeof(zot) / sizeof(zot[0]);
    // int b_n = sizeof(b) / sizeof(b[0]);
    // int k = 1;
    // reverse_array(arr, n);
    // reverse_array_by_r(arr, 0, n - 1);
    // print_array(arr, n);
    // find_min_max(arr, n);
    // find_kth_min(arr, n, k);

    // int t = find_kth_smallest_parition(arr, 0, n - 1, k);
    // print_array(arr, n);
    // cout << arr[t];

    // sort_without_sort_01(zo, 0, zo_n - 1);
    // sort_without_sort_012(zot, zot_n);

    // move_negative_oneside(b, 0, b_n);
    // print_array(b, b_n);

    // int bk[] = {2, 4, 6, 8};
    // int kk[] = {1, 3, 6, 8};
    // find_union(bk, kk, 4, 4);
    // cout << endl;
    // find_insertion(bk, kk, 4, 4);

    // int x = binarySearch(bk, 0, 3, 4);
    // // cout << x;
    // rotate(bk, 4, 2);
    // print_array(bk, 4);

    // int x[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    // cout << Largest_sum_contiguous_Subarray(x, 8);

    // int h[] = {1, 15, 10};
    // int size = 3;
    // int k = 6;
    // cout << get_Min_Height(h, size, k);

    return 0;
}