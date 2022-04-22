#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;
#define S cout << "*" << endl;

// method 1:
// sort all interval by starting face
// and use stack and start from first from sorted intervals and if any starting index is less then our end index then make end index is compared ending index and if not then take second interval and go forward;
// complexity time:nlogn and space n

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
struct Interval
{
    int start;
    int end;
};

bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}
void mergeInterval(Interval a[], int n)
{
    if (n <= 0)
    {
        return;
    }
    stack<Interval> s;
    sort(a, a + n, compareInterval);
    s.push(a[0]);

    for (int i = 1; i < n; i++)
    {
        Interval top = s.top();
        if (top.end < a[i].start)
        {
            s.push(a[i]);
        }
        else if (top.end < a[i].end)
        {
            top.end = a[i].end;
            s.pop();
            s.push(top);
        }
    }

    while (!s.empty())
    {
        Interval t = s.top();
        cout << "[" << t.start << "," << t.end << "]";
        s.pop();
        N;
    }
    return;
}
// method 2:
// not use stack track by 2 veriable start and end;
// complexity time:0(nlogn) and space o(1)
void mergeIntervalOptimal(Interval a[], int n)
{
    sort(a, a + n, compareInterval);
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[index].end >= a[i].start)
        {
            a[index].end = max(a[index].end, a[i].end);
            a[index].start = min(a[index].start, a[i].start);
        }
        else
        {
            // cout << "[" << a[index].start << "," << a[index].end << "]";
            index++;
            // S;
            a[index] = a[i];
        }
    }
    for (int i = 0; i <= index; i++)
    {
        cout << "[" << a[i].start << "," << a[i].end << "]";
        N;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    Interval a[] = {{1, 3}, {2, 5}, {6, 3}, {10, 12}, {14, 16}};
    int n = sizeof(a) / sizeof(a[0]);
    mergeInterval(a, n);
    N;
    mergeIntervalOptimal(a, n);
    return 0;
}