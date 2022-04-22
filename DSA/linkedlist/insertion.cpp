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

Node *sorted_insertion(Node *a, Node *b)
{
    Node *head = NULL;
    while (a != NULL && b != NULL)
    {
        if (a->data == b->data)
        {
            push(&head, a->data);
            a = a->next;
            b = b->next;
        }
        else if (a->data < b->data)
        {
            push(&head, a->data);
            a = a->next;
        }
        else
        {
            push(&head, b->data);
            b = b->next;
        }
    }
    while (a != NULL)
    {
        push(&head, a->data);
        a = a->next;
    }
    while (b != NULL)
    {
        push(&head, b->data);
        b = b->next;
    }
    return head;
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
    push(&a, 6);
    push(&a, 5);
    push(&a, 4);

    push(&b, 5);
    push(&b, 4);
    push(&b, 3);

    printList(a);
    printList(b);

    Node *in = sorted_insertion(a, b);
    printList(in);

    return 0;
}
