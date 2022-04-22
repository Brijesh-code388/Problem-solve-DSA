#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>
//#define N cout << endl;
using namespace std;
#define d 256

/* pat -> pattern
    txt -> text
    q -> A prime number
*/
void search1(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {

        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters one by one
        if (p == t)
        {
            bool flag = true;
            /* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    flag = false;
                    break;
                }
                // if (flag)
                //     cout << i << " ";
            }

            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]

            if (j == M)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            // We might get negative value of t, converting it
            // to positive
            if (t < 0)
                t = (t + q);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);

    char text[] = "Brijesh Kachhadiya is nice guy.";
    char ptn[] = "is nice";
    search1(ptn, text, 5381); // prime
    return 0;
}

// rolling hash
// strong hash
// o(size of ptn, size of text)