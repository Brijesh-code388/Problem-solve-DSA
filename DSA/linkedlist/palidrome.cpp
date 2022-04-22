
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
Node *reverse(Node *head)
{
    Node *curr;
    Node *pre;
    Node *next;
    curr = head;
    pre = NULL;
    next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    return pre;
}

void isplidrome(Node *h, Node *a)
{
    Node *r = reverse(a);
    printList(r);
    cout << "*";
    cout << r->next->data;
    n;
    cout << h->next->data;
    while (h != NULL && r != NULL)
    {
        cout << "*";
        n;
        if (h->data == r->data)
        {
            r = r->next;
            h = h->next;
        }
        else
        {
            break;
        }
    }
    if (h == NULL && r == NULL)
    {
        cout << "palidrome";
    }
    else
    {
        cout << "not palidrome";
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
    // fio();
    Node *a = NULL;
    push(&a, 6);
    push(&a, 5);
    push(&a, 6);
    Node *b = NULL;
    push(&b, 6);
    push(&b, 5);
    push(&b, 6);
    printList(a);
    isplidrome(b, a);

    return 0;
}
