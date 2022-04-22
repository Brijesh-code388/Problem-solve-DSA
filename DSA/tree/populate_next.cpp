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
    void populateNext(b *root)
    {
        if (root == NULL)
        {
            return;
        }
        stack<b *> s;
        b *tmp = root;

        while (tmp->left)
        {
            s.push(tmp);
            tmp = tmp->left;
        }

        b *c = tmp;
        if (c->right)
        {
            b *a = c->right;
            while (a)
            {
                s.push(a);
                a = a->left;
            }
        }

        while (s.empty() == false)
        {
            b *inorder = s.top();
            s.pop();
            c->next = inorder;
            if (inorder->right)
            {
                b *q = inorder->right;
                while (q)
                {
                    s.push(q);
                    q = q->left;
                }
            }
            c = inorder;
        }
    }
    b *inorder(b *root)
    {
        if (root->left == NULL)
        {
            return root;
        }
        return inorder(root->left);
    }
};

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

    b *root = new b(10);
    root->left = new b(8);
    root->right = new b(12);
    root->left->left = new b(3);
    root->left->left = new b(3);

    root->populateNext(root);

    b *ptr = root->inorder(root);
    int x;

    while (ptr)
    {

        if (ptr->next)
        {
            x = ptr->next->data;
        }
        else
        {
            x = -1;
        }
        cout << ptr->data << " " << x << endl;
        ptr = ptr->next;
    }

    return 0;
}
