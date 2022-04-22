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

int main()
{
    BST b;
    BST *root = NULL;
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

    b.Inorder(root);
    cout << endl;
    root = b.deleteNode(root, 30);
    root = b.deleteNode(root, 50);
    cout << endl;
    b.Inorder(root);
    return 0;
}
