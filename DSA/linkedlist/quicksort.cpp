
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
Node *tail(Node *head)
{
    while (head != NULL && head->next != NULL)
    {
        head = head->next;
    }
    return head;
}

Node *partition(Node *start, Node *end, Node **nstart, Node **nend)
{
    Node *pivot = end;
    Node *pre = NULL;
    Node *curr = start;
    Node *tail = pivot;

    while (curr != pivot)
    {
        if (curr->data < pivot->data)
        {
            if (*nstart == NULL)
            {
                *nstart = curr;
            }
            pre = curr;
            curr = curr->next;
        }
        else
        {
            if (pre)
            {
                pre->next = curr->next;
            }
            Node *tmp = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            curr = tmp;
        }
        if (*nstart == NULL)
        {
            *nstart = pivot;
        }
        *nend = tail;
    }
    return pivot;
}

Node *quickreq(Node *start, Node *end)
{
    // base
    if (start == NULL || start == end)
    {
        return start;
    }
    Node *nstart = NULL;
    Node *nend = NULL;
    // partition
    Node *pivot = partition(start, end, &nstart, &nend);
    // part1
    // left
    if (nstart != pivot)
    {
        Node *tmp = nstart;
        while (tmp->next != pivot)
        {
            tmp = tmp->next;
        }
        tmp->next = NULL;
        nstart = quickreq(nstart, tmp);
        tmp = tail(nstart);
        tmp->next = pivot;
    }

    // part2
    // right
    pivot->next = quickreq(pivot->next, nend);

    return nstart;
}

void QuickSort(Node **head)
{
    *head = quickreq(*head, tail(*head));
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

    printList(a);
    QuickSort(&a);
    printList(a);
    return 0;
}
