#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
#define pii pair<int, int>
#define n cout << "\n";
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

struct Linkedlist
{
    Node *head; // for storing the address of the node type of variable;
    Linkedlist()
    {
        head = NULL;
    }
    void push(int data) // push at frist in ll
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    Node *reverse_rec(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *rest = reverse_rec(head->next);

        head->next->next = head;

        head->next = NULL;
        return rest;
    }

    void reverse()
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
        head = pre;
    }

    Node *rev_by_group(Node *head, int k)
    {
        if (head == NULL)
        {
            return NULL;
        }
        Node *prev = NULL;
        Node *curr = head;
        Node *nex = NULL;
        int count = 0;

        while (curr != NULL && count < k)
        {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
            count++;
        }
        if (curr != NULL)
        {
            head->next = rev_by_group(curr, k);
        }
        return prev;
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
    Linkedlist l;
    l.push(1);
    l.push(2);
    l.push(3);
    l.push(4);
    l.push(5);
    l.push(6);
    l.print();
    n;
    // l.reverse();
    // l.head = l.reverse_rec(l.head);
    l.head = l.rev_by_group(l.head, 2);
    l.print();
    return 0;
}
