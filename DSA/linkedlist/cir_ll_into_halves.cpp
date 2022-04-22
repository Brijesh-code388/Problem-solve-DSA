
#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>
#define n cout << "\n";
//#define s cout << " ";
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

void split(Node *a, Node **f, Node **s)
{
    Node *slow = a;
    Node *fast = a;

    if (a == NULL)
    {
        return;
    }
    while (fast->next != a && fast->next->next != a)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast->next->next == a)
    {
        fast = fast->next;
    }
    *f = a;
    if (a->next != a)
    {
        *s = slow->next;
    }
    fast->next = slow->next;
    slow->next = a;
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
    push(&a, 6);
    push(&a, 1);
    push(&a, 9);
    push(&a, 5);
    push(&a, 2);

    a->next->next->next->next->next = a;

    Node *f = NULL;
    Node *s = NULL;

    split(a, &f, &s);
    f->next->next->next = NULL;
    s->next->next = NULL;
    printList(f);
    printList(s);
    // printList(a);
    return 0;
}
