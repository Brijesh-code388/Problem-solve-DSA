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
    void remove_dyuplicate()
    {

        Node *curr = head;
        Node *next_next;
        if (curr == NULL)
            return;
        while (curr->next != NULL)
        {
            if (curr->next->data == curr->data)
            {
                next_next = curr->next->next;
                free(curr->next);
                curr->next = next_next;
            }
            else
            {
                curr = curr->next;
            }
        }
    }
    void remove_duplicate()
    {

        Node *curr = head;
        Node *next_next;
        if (curr == NULL)
            return;
        while (curr->next != NULL)
        {
            if (curr->next->data == curr->data)
            {
                next_next = curr->next->next;
                free(curr->next);
                curr->next = next_next;
            }
            else
            {
                curr = curr->next;
            }
        }
    }
    void remove_duplicate_unsorted()
    {
        unordered_set<int> s;
        Node *curr = head;
        Node *prev;

        while (curr->next != NULL)
        {
            if (s.find(curr->data) != s.end())
            {
                prev->next = curr->next;
                free(curr);
            }
            else
            {
                s.insert(curr->data);
                prev = curr;
            }
            curr = prev->next;
        }
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
    l.push(2);
    l.push(3);
    l.push(4);
    l.push(4);
    l.print();
    l.remove_duplicate();
    n;
    l.print();
    n;
    n;
    Linkedlist li;
    li.push(1);
    li.push(2);
    li.push(4);
    li.push(2);
    li.push(4);
    li.push(3);
    li.print();
    li.remove_duplicate_unsorted();
    n;
    li.print();

    return 0;
}
