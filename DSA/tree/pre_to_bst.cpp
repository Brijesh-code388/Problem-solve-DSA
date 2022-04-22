#include <bits/stdc++.h>
using namespace std;

class b
{

public:
    int data;
    b *left, *right, *next;
    b()
    {
        data = 0;
        left = right = next = NULL;
    }
    b(int v)
    {
        data = v;
        left = right = next = NULL;
    }
};

b *constructTreeUtil(int pre[], int size, int key, int min, int max, int *preindex)
{
    if (*preindex > size)
    {
        return NULL;
    }
    b *root = NULL;

    if (key > min && key < max)
    {
        root = new b(key);
        *preindex = *preindex + 1;
        if (*preindex < size)
        {
            root->left = constructTreeUtil(pre, size, pre[*preindex], min, key, preindex);
        }
        if (*preindex < size)
        {
            root->right = constructTreeUtil(pre, size, pre[*preindex], key, max, preindex);
        }
    }
    return root;
}

b *constructTree(int pre[], int size)
{
    int preindex = 0;
    return constructTreeUtil(pre, size, pre[0], INT_MIN, INT_MAX, &preindex);
}

void fio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
}

void inorder(b *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{

    fio();

    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(pre) / sizeof(pre[0]);

    b *root = constructTree(pre, size);

    // b *root = new b(10);
    // root->left = new b(8);
    // root->right = new b(12);
    // root->left->left = new b(3);
    // root->left->left = new b(3);
    inorder(root);
    return 0;
}
