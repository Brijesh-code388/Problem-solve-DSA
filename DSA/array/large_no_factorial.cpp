#include <bits/stdc++.h>
#include <math.h>
#define mod 1000000007
#define ll long long int
using namespace std;
#define pii pair<int, int>
#define N cout << endl;
#define S cout << "*" << endl;
#define MAX 500

// by array
int multiply(int x, int res[], int res_size)
{
    int c = 0;
    for (int i = 0; i < res_size; i++)
    {
        int data = res[i] * x + c;
        res[i] = data % 10;
        c = data / 10;
    }
    while (c != 0)
    {
        res[res_size] = c % 10;
        c = c / 10;
        res_size++;
    }

    return res_size;
}

void factorial(int n)
{
    int res[MAX];

    // Initialize result
    res[0] = 1;
    int res_size = 1;

    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
    for (int x = 2; x <= n; x++)
        res_size = multiply(x, res, res_size);

    cout << "Factorial of given number is \n";
    for (int i = res_size - 1; i >= 0; i--)
        cout << res[i];
}

// linked list
class Node
{
public:
    int data;
    Node *prev = NULL;
    Node(int n)
    {
        this->data = n;
        this->prev = NULL;
    }
};

void multiply(Node *tail, int n)
{
    Node *temp = tail;
    Node *prevNode = tail;
    int c = 0;
    while (temp != NULL)
    {
        int data = temp->data * n + c;
        temp->data = data % 10;
        c = data / 10;
        prevNode = temp;
        temp = temp->prev;
    }
    while (c != 0)
    {
        prevNode->prev = new Node((int)(c % 10));
        c = c / 10;
        prevNode = prevNode->prev;
    }
}
void print(Node *tail)
{
    if (tail == NULL)
    {
        return;
    }
    print(tail->prev);
    cout << tail->data << " " << tail->prev << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("./inputf.in", "r", stdin);
    freopen("./outputf.out", "w", stdout);
    int n = 5;
    Node tail(1);
    for (int i = 2; i <= n; i++)
    {
        multiply(&tail, i);
    }
    print(&tail);
    N;
    factorial(5);

    return 0;
}
