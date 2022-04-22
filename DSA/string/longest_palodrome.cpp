#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>
#define N cout << endl;
using namespace std;
void print_String(string s, int n, int m)
{
    for (int i = n; i < m; i++)
    {
        cout << s[i];
    }
    N;
}
void longest_palidrome(string s)
{
    int l, h;
    int start = 0;
    int end = 1;
    for (int i = 1; i < s.length(); i++)
    {
        l = i - 1;
        h = i;
        while (l >= 0 && h <= s.length() && s[l] == s[h])
        {
            start = l;
            end = h - l + 1;
            l--;
            h++;
        }
        l = i - 1;
        h = i + 1;
        while (l >= 0 && h <= s.length() && s[l] == s[h])
        {
            start = l;
            end = h - l + 1;
            l--;
            h++;
        }
    }
    print_String(s, start, start + end);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    string s = "brijirh";
    string s1 = "brijrirh";

    longest_palidrome(s);
    // print_String(s, 1, 3);

    return 0;
}
