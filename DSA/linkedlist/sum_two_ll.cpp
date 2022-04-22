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
    // add one
    void code_add_one()
    {
        Node *curr = head;
        int carry = 1;
        while (curr != NULL)
        {
            int sum = 0;
            sum = curr->data + carry;
            carry = (sum >= 10) ? 1 : 0;
            sum = sum % 10;
            curr->data = sum;
            curr = curr->next;
        }
        if (carry > 0)
        {
            Node *x = new Node(carry);
            x->next = head;
            head = x;
        }
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
};

void add_two_ll(Node *f, Node *s)
{
    Linkedlist ans;
    int carry = 0;
    int sum;
    while (f != NULL || s != NULL)
    {

        sum = f->data + s->data + carry;
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        ans.push(sum);
        f = f->next;
        s = s->next;
    }
    if (carry > 0)
    {
        cout << "*";
        ans.push(carry);
    }
    n;
    ans.print();
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
    Linkedlist l;
    l.push(3);
    l.push(2);
    l.push(1);
    l.print();
    l.reverse();
    n;
    Linkedlist m;
    m.push(7);
    m.push(2);
    m.push(1);
    m.print();
    m.reverse();

    // l.reverse();
    // //l.code_add_one();
    // l.reverse();

    add_two_ll(l.head, m.head);

    return 0;
}
