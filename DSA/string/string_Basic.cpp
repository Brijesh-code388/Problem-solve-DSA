
#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>
#define N cout << endl;
using namespace std;

void reverse_(string &s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
    {
        swap(s[i], s[n - i - 1]);
    }
}

char *getstring()
{
    char *s = "Brijesh";
    // char s[] = "brijesh";//not return usefull garbeg value
    return s;
}

int main()
{
    // ios::sync_with_stdio(0);
    //  cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);

    // string s = "brijeshKachhadiya";
    // reverse_(s);
    // cout << s;
    // reverse(s.begin(), s.end());
    // cout << s;
    int k[] = {1, 2, 3};
    string b = "A Brijesh Kachhadiya brijesh kachhadiya Brijesh kachhadiya";
    char *s = "A Brijesh Kachhadiya brijesh kachhadiya Brijesh kachhadiya"; // use when you want string are unmutable
    cout << *(s + 2);
    N;
    cout << *s;
    N;
    cout << &s; // add of str
    N;
    cout << s;
    N;
    cout << *(s + 4);
    N;
    cout << *s;
    N;
    // *(s + 4) = 'B';//unmuttable
    N;
    cout << s;
    N;
    cout << *(&b);
    N;
    cout << b[1];
    N;
    cout << sizeof(string);
    N;
    cout << sizeof(b);
    N;

    // mutable //best i think
    char *str;
    str = (char *)malloc(sizeof(char) * 4);
    *(str + 0) = 'G';
    *(str + 1) = 'f';
    *(str + 2) = 'G';
    *(str + 3) = '\0';
    *(str + 1) = 'B';
    cout << str;
    N;
    cout << getstring();
    N;
    char *brijesh;
    brijesh = "Brijesh";
    return 0;
}
