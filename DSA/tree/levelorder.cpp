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

void printThisLevel(node *node, int l)
{
    if (node == NULL)
    {
        return;
    }
    if (l == 1)
    {
        cout << node->data << " ";
    }
    else if (l > 1)
    {
        printThisLevel(node->left, l - 1);
        printThisLevel(node->right, l - 1);
    }
}

void printlevel(node *node)
{
    int h = height(node);
    for (int i = h; i >= 1; i--)
    {
        printThisLevel(node, i);
    }
}

void byq(node *r)
{
    if (r == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(r);

    while (q.empty() == false)
    {
        node *n = q.front();
        cout << n->data << " ";
        q.pop();
        if (n->left != NULL)
            q.push(n->left);
        if (n->right != NULL)
            q.push(n->right);
    }
}

void reverse(node *root)
{

    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    stack<node *> s;
    q.push(root);

    while (q.empty() == false)
    {
        root = q.front();
        q.pop();

        s.push(root);
        if (root->right != NULL)
            q.push(root->right);

        if (root->left != NULL)
            q.push(root->left);
    }
    while (s.empty() == false)
    {
        root = s.top();
        cout << root->data << " ";
        s.pop();
    }
}

int maxdia(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    int ld = maxdia(root->left);
    int rd = maxdia(root->right);

    return max(lh + rh + 1, max(ld, rd));
}

void mirror(node *r, node **m)
{
    if (r == NULL)
    {
        m = NULL;
        return;
    }

    *m = newNode(r->data);
    mirror(r->left, &((*m)->right));
    mirror(r->right, &((*m)->left));
}

void inorder(node *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << " ";
    inorder(node->left);
    inorder(node->right);
}

void preorderIteration(node *n)
{
    stack<node *> s;
    node *c = n;
    while (s.empty() == false || c != nullptr)
    {
        if (c != nullptr)
        {
            s.push(c);
            cout << c->data << " ";
            c = c->left;
        }
        else
        {
            c = s.top();
            s.pop();
            c = c->right;
        }
    }
}

void preo(node *n)
{
    stack<node *> s;
    node *c = NULL;
    s.push(n);
    while (s.empty() == false)
    {
        c = s.top();
        s.pop();
        cout << c->data << " ";
        if (c->right)
            s.push(c->right);
        if (c->left)
            s.push(c->left);
    }
}

void posto(node *n)
{
    stack<node *> s;
    stack<int> out;
    node *c = NULL;
    s.push(n);
    while (s.empty() == false)
    {
        c = s.top();
        out.push(c->data);
        s.pop();
        if (c->left)
            s.push(c->left);
        if (c->right)
            s.push(c->right);
    }
    while (out.empty() == false)
    {
        cout << out.top() << " ";
        out.pop();
    }
}
//////////////////////////////////////////////////////////////////

int main()
{
    fio();
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->left->left = newNode(5);
    // int h = height(root);
    // cout << h << endl;
    // printlevel(root);
    // cout << endl;
    // byq(root);
    // cout << endl;
    // reverse(root);
    // cout << endl;
    // cout << maxdia(root);

    node *m = NULL;

    mirror(root, &m);
    inorder(root);
    cout << endl;
    inorder(m);
    cout << endl;
    preo(root);
    return 0;
}
