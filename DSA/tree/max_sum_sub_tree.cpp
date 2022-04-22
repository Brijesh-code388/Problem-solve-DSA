#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int v)
{
    Node *x = new Node();
    x->data = v;
    x->left = NULL;
    x->right = NULL;
    return x;
}

int MaxSubSumTree(Node *root, int ans)
{
    if (root == NULL)
    {
        return 0;
    }
    int sum = root->data + MaxSubSumTree(root->left, ans) + MaxSubSumTree(root->right, ans);
    ans = max(sum, ans);
    return ans;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(-2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(-6);
    root->right->right = newNode(2);

    int ans = INT_MIN;
    cout << MaxSubSumTree(root, ans);

    return 0;
}
