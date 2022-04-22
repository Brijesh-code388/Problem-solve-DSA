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
int height(node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}

void printdia(map<int, vector<int>> &m, node *root, int d)
{

    if (root == NULL)
    {
        return;
    }
    m[d].push_back(root->data);

    printdia(m, root->left, d + 1);
    printdia(m, root->right, d);
}

void diaTraversal(node *root)
{
    map<int, vector<int>> m;
    printdia(m, root, 0);

    for (auto it : m)
    {
        vector<int> v = it.second;
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}

int findindex(string str, int s, int e)
{
    if (e < s)
    {
        return -1;
    }
    stack<char> st;
    for (int i = s; i <= e; i++)
    {
        if (str[i] == '(')
        {
            st.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (st.top() == '(')
            {
                st.pop();
                if (st.empty())
                {
                    return i;
                }
            }
        }
    }
    return -1;
}

node *maketree(string s, int f, int l)
{
    if (l < f)
    {
        return nullptr;
    }
    node *root = newNode(s[f] - '0');
    int index = -1;

    if (f + 1 < l && s[f + 1] == '(')
    {
        index = findindex(s, f + 1, l);
    }

    if (index != -1)
    {
        root->left = maketree(s, f + 2, index - 1);
        root->right = maketree(s, index + 2, l - 1);
    }
    return root;
}
void preOrder(node *n)
{
    if (n == NULL)
        return;
    printf("%d ", n->data);
    preOrder(n->left);
    preOrder(n->right);
}

int main()
{
    fio();
    node *root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);

    string str = "4(2(3)(1))(6(5))";

    node *tree = maketree(str, 0, str.length() - 1);
    preOrder(tree);

    return 0;
}
