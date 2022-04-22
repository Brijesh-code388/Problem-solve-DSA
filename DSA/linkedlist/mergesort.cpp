
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
// rev
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
// divide into two
void divide(Node *l, Node **a, Node **b)
{
    Node *slow = l;
    Node *fast = l->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *a = l;
    *b = slow->next;
    slow->next = NULL;
}
// merge
Node *merge(Node *a, Node *b)
{
    Node *result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->data <= b->data)
    {
        result = a;
        result->next = merge(a->next, b);
    }
    else
    {
        result = b;
        result->next = merge(a, b->next);
    }
    return (result);
}

Node *merge1(Node *a, Node *b)
{
    Node *ans = NULL;
    while (a != NULL || b != NULL)
    {
        if (a == NULL)
        {
            push(&ans, b->data);
            b = b->next;
        }
        else if (b == NULL)
        {
            push(&ans, a->data);
            a = a->next;
        }
        else if (a->data <= b->data)
        {
            push(&ans, a->data);
            a = a->next;
        }
        else
        {
            push(&ans, b->data);
            b = b->next;
        }
    }
    ans = reverse(ans);
    return ans;
}

// merge sort
void mergeSort(Node **l)
{
    Node *head = *l;
    Node *a;
    Node *b;
    // cout << "*";
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    // divide into halves
    divide(head, &a, &b);
    // divide
    mergeSort(&a);
    mergeSort(&b);
    // merge
    *l = merge1(a, b);
    // printList(*l);
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
    push(&a, 7);
    push(&a, 2);
    push(&a, 3);
    push(&a, 5);
    push(&a, 9);

    printList(a);
    mergeSort(&a);

    printList(a);
    n;

    // Node *e = NULL;
    // Node *b = NULL;
    // push(&e, 5);
    // push(&e, 4);
    // push(&e, 3);
    // push(&e, 2);

    // push(&b, 6);
    // push(&b, 4);
    // push(&b, 3);
    // printList(e);
    // printList(b);
    // Node *m = merge1(e, b);
    // printList(m);

    return 0;
}
