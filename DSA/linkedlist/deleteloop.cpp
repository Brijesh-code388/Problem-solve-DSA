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
    bool detectLoop(Node *h) // with n space
    {
        unordered_set<Node *> s;
        while (h != NULL)
        {
            // If this node is already present
            // in hashmap it means there is a cycle
            // (Because you we encountering the
            // node for the second time).
            if (s.find(h) != s.end())
                return true;

            // If we are seeing the node for
            // the first time, insert it in hash
            s.insert(h);

            h = h->next;
        }
        return false;
    }

    void remove_loop(Node *inloop, Node *head)
    {
        Node *pt1 = inloop;
        Node *pt2 = inloop;
        // find the size of loop;
        int k = 1;
        while (pt2->next != pt1)
        {
            pt2 = pt2->next;
            k++;
        }
        pt1 = pt2 = head;
        for (int i = 0; i < k; i++)
        {
            pt2 = pt2->next;
        }
        while (pt2 != pt1)
        {
            pt1 = pt1->next;
            pt2 = pt2->next;
        }
        for (int i = 0; i < k - 1; i++)
        {
            pt2 = pt2->next;
        }
        n;
        pt2->next = NULL;
    }
    bool detect_loop()
    {
        Node *one = head;
        Node *two = head;
        while (one && two && two->next)
        {
            one = one->next;
            two = two->next->next;
            if (one == two)
            {
                remove_loop(one, head);
                return true;
            }
        }
        return false;
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
    l.push(7);
    l.head->next->next->next->next->next->next->next = l.head->next->next;
    // cout << l.detectLoop(l.head);

    cout << l.detect_loop();
    n;
    l.print();
    return 0;
}
