#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tata return 0
#define all(v) v.begin(), v.end()
#define endl '\n'
#define gap ' '

const int M = 1e9 + 7;

struct linkedList
{
    struct Node
    {
        int val;
        Node *next = NULL;
    };

    Node *head = NULL;
    Node *tail = NULL;

    bool empt = 1;

    void push(int val)
    {
        Node *temp = new Node;
        temp->val = val;

        temp->next = NULL;
        if (tail == NULL)
        {
            head = temp;
            tail = temp;
            empt = 0;
        }
        else
        {
            tail->next = temp;

            tail = tail->next;
        }
        temp = NULL;
    }
    void pop()
    {
        if (head != NULL)
        {
            head = head->next;
            if (head == NULL)
            {
                tail = NULL;
                empt = 1;
            }
        }
    }

    int front()
    {
        if (head != NULL)
            return head->val;
        else
            return 0;
    }

    bool empty()
    {
        return empt;
    }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << gap;
            temp = temp->next;
        }
        cout << endl;
        temp = NULL;
    }
};

void kire()
{
    linkedList *l = new linkedList;
    l->push(4);
    l->push(6);
    l->print();
    l->pop();
    l->print();
    l->pop();
    l->print();
    l->print();
    l->pop();
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;

    for (int i = 1; i <= t; i++)
    {

        kire();
    }

    tata;
}