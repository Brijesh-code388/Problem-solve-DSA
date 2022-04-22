#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>
#define n cout << "\n";
#define s cout << " ";
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void push(Node **head, int data)
{
    Node *ne = new Node(data);
    ne->next = *head;
    *head = ne;
}
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    n;
}

int count(Node *a)
{
    int c = 0;
    while (a != NULL)
    {
        c++;
        a = a->next;
    }

    return c;
}
void find_insection(Node *a, Node *b)
{
    int a1 = count(a);
    int b1 = count(b);
    cout << a1;
    n;
    cout << b1;
    int c = abs(a1 - b1);
    if (a1 > b1)
    {
        while (a != NULL && c > 0)
        {
            a = a->next;
            c--;
        }
        while (a != NULL && b != NULL)
        {
            if (a == b)
            {
                n;
                cout << a->data;
                return;
            }
            a = a->next;
            b = b->next;
        }
    }
    else
    {
        while (a != NULL && c > 0)
        {
            b = b->next;
            c--;
        }
        while (a != NULL && b != NULL)
        {
            if (a == b)
            {
                n;
                cout << a->data;
                return;
            }
            a = a->next;
            b = b->next;
        }
    }
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
    Node *a = NULL;
    Node *b = NULL;
    Node *c = NULL;
    push(&a, 4);
    push(&a, 5);
    push(&a, 6);
    push(&a, 7);

    push(&b, 4);
    push(&b, 5);
    push(&b, 6);

    push(&c, 1);
    push(&c, 2);
    push(&c, 3);

    a->next->next->next->next = c;
    b->next->next->next = c;

    printList(a);
    printList(b);

    find_insection(b, a);

    return 0;
}
