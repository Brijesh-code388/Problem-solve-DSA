#include <bits/stdc++.h>
using namespace std;

class BST
{
    int data;
    BST *left, *right;
    BST *minValueNode(BST *);

public:
    BST();

    BST(int);

    BST *Insert(BST *, int);

    void Inorder(BST *);

    BST *deleteNode(BST *, int);

    int countNode(BST *root)
    {
        BST *cur = root;
        int c = 0;
        while (cur != NULL)
        {
            if (cur->left == NULL)
            {
                c++;
                cur = cur->right;
            }
            else
            {
                BST *p = cur->left;
                while (p->right && p->right != cur)
                {
                    p = p->right;
                }
                if (p->right == NULL)
                {
                    p->right = cur;
                    cur = cur->left;
                }
                else
                {
                    p->right = NULL;
                    c++;
                    cur = cur->right;
                }
            }
        }
        return c;
    }

    int findNode(int k, BST *root)
    {
        BST *cur = root;
        int a = 0;
        int c = 0;
        while (cur != NULL)
        {
            if (cur->left == NULL)
            {
                c++;
                cout << cur->data << " ";
                if (c == k)
                {
                    a = cur->data;
                }
                cur = cur->right;
            }
            else
            {
                BST *p = cur->left;
                while (p->right && p->right != cur)
                {
                    p = p->right;
                }
                if (p->right == NULL)
                {
                    p->right = cur;
                    cur = cur->left;
                }
                else
                {
                    p->right = NULL;
                    c++;
                    cout << cur->data << " ";
                    if (c == k)
                    {
                        a = cur->data;
                    }
                    cur = cur->right;
                }
            }
        }
        return a;
    }

    // your task is to complete the Function
    // Function should return median of the BST
    float findMedian(BST *root)
    {
        int n = countNode(root);
        cout << n << endl;
        float ans = 0;
        if (n % 2 == 0)
        {
            // cout
            //     << root->data << " " << n / 2 + 1 << " " << findNode((n / 2) + 1, root) << endl;
            // cout
            //     << root->data << " " << n / 2 << " " << findNode(n / 2, root) << endl;
            ans = (float)(findNode(n / 2, root) + findNode((n / 2) + 1, root)) / 2;
        }
        else
        {
            ans = findNode((n + 1) / 2, root);
        }
        return ans;
    }
};

BST ::BST()
{
    data = 0;
    left = right = NULL;
}

BST ::BST(int value)
{
    data = value;
    left = right = NULL;
}

BST *BST ::Insert(BST *root, int value)
{
    if (root == NULL)
    {
        return new BST(value);
    }

    if (value > root->data)
    {

        root->right = Insert(root->right, value);
    }
    else
    {
        root->left = Insert(root->left, value);
    }
    return root;
}

void BST ::Inorder(BST *root)
{
    if (!root)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}

BST *BST ::deleteNode(BST *root, int value)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data > value)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            return NULL;
        }
        else if (root->left == NULL)
        {
            BST *temp = root->left;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            BST *temp = root->right;
            free(root);
            return temp;
        }

        // find min value node.
        BST *node = minValueNode(root->right);
        root->data = node->data;
        root->right = deleteNode(root->right, node->data);
    }
    return root;
}

BST *BST::minValueNode(BST *root)
{
    BST *c = root;
    while (c && c->left != NULL)
    {
        c = c->left;
    }
    return c;
}

void fio()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
}

int main()
{
    fio();
    BST b;
    BST *root = NULL;
    // root = b.Insert(root, 50);
    // b.Insert(root, 30);
    // b.Insert(root, 20);
    // b.Insert(root, 40);
    // b.Insert(root, 70);
    // b.Insert(root, 60);
    // b.Insert(root, 80);

    root = b.Insert(root, 13);
    b.Insert(root, 10);
    b.Insert(root, 18);
    b.Insert(root, 3);
    b.Insert(root, 11);
    b.Insert(root, 15);
    b.Insert(root, 20);
    b.Insert(root, 1);
    b.Insert(root, 6);
    b.Insert(root, 12);

    // b.Inorder(root);
    // cout << endl;
    // root = b.deleteNode(root, 30);
    // root = b.deleteNode(root, 50);
    // cout << endl;
    // b.Inorder(root);
    cout << b.findMedian(root);

    return 0;
}
