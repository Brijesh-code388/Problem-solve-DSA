#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>
using namespace std;

void fio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
}

class node
{
public:
    int data;
    node *left, *right;
};
node *newNode(int a)
{
    node *Node = new node();
    Node->data = a;
    Node->left = NULL;
    Node->right = NULL;

    return Node;
}

void inorder(int a[], vector<int> &v, int n, int i)
{
    if (i >= n)
    {
        return;
    }
    static int last = 0;
    inorder(a, v, n, (2 * i + 1));
    v[last] = a[i];
    last++;
    inorder(a, v, n, (2 * i + 2));
}

int minSwap(vector<int> &v)
{
    int n = v.size();
    vector<pii> vec(n);

    for (int i = 0; i < n; i++)
    {
        vec[i].first = v[i];
        vec[i].second = i;
    }

    sort(vec.begin(), vec.end());

    vector<bool> vis(n, false);

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (vec[i].second == i)
        {
            continue;
        }
        else
        {
            int j = i;
            int c = 0;
            while (!vis[j])
            {
                vis[j] = 1;
                j = vec[j].second;
                c++;
            }
            if (c > 0)
            {
                ans = ans + c - 1;
            }
        }
    }

    return ans;
}

int main()
{
    fio();
    // node *root = newNode(1);
    // root->left = newNode(2);
    // root->right = newNode(3);

    int a[] = {5, 6, 7};
    int l = sizeof(a) / sizeof(a[0]);
    vector<int> v(l);
    inorder(a, v, l, 0);

    cout << minSwap(v);

    return 0;
}
