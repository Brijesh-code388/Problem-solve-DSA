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

string inorder(Node *root, unordered_map<string, int> &m)
{
    if (root == NULL)
    {
        return "";
    }

    string s = "";
    s += inorder(root->left, m);
    s += to_string(root->data);
    s += inorder(root->right, m);

    if (m[s] == 1)
    {
        cout << root->data << " ";
    }
    m[s]++;
    return s;
}

void printAllDups(Node *root)
{
    unordered_map<string, int> m;
    inorder(root, m);
    cout << endl;
    for (auto i = m.begin(); i != m.end(); i++)
        cout << i->first << "   " << i->second << endl;
}

bool isIsomorphic(Node *n1, Node *n2)
{
    // Both roots are NULL, trees isomorphic by definition
    if (n1 == NULL && n2 == NULL)
        return true;

    // Exactly one of the n1 and n2 is NULL, trees not isomorphic
    if (n1 == NULL || n2 == NULL)
        return false;

    if (n1->data != n2->data)
        return false;

    // There are two possible cases for n1 and n2 to be isomorphic
    // Case 1: The subtrees rooted at these nodes have NOT been "Flipped".
    // Both of these subtrees have to be isomorphic, hence the &&
    // Case 2: The subtrees rooted at these nodes have been "Flipped"
    return (isIsomorphic(n1->left, n2->left) && isIsomorphic(n1->right, n2->right)) ||
           (isIsomorphic(n1->left, n2->right) && isIsomorphic(n1->right, n2->left));
}

int main()
{
    Node *root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(2);
    root->right->left->left = newNode(4);
    root->right->right = newNode(4);
    printAllDups(root);

    Node *n1 = newNode(1);
    n1->left = newNode(2);
    n1->right = newNode(3);
    n1->left->left = newNode(4);
    n1->left->right = newNode(5);
    n1->right->left = newNode(6);
    n1->left->right->left = newNode(7);
    n1->left->right->right = newNode(8);

    Node *n2 = newNode(1);
    n2->left = newNode(3);
    n2->right = newNode(2);
    n2->right->left = newNode(4);
    n2->right->right = newNode(5);
    n2->left->right = newNode(6);
    n2->right->right->left = newNode(8);
    // n2->right->right->right = newNode(7);

    if (isIsomorphic(n1, n2) == true)
        cout << "Yes";
    else
        cout << "No";

    // int ans = INT_MIN;
    // cout << MaxSubSumTree(root, ans);

    return 0;
}
