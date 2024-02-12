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
        Node *prev = NULL;
    };
    Node *head = NULL;
    Node *tail = NULL;
    bool empt = 1;
    void addFirst(int val)
    {
        Node *temp = new Node;
        temp->val = val;
        temp->prev = NULL;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            empt = 0;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = head->prev;
        }
        temp = NULL;
    }
    void addLast(int val)
    {
        Node *temp = new Node;
        temp->val = val;
        temp->prev = NULL;
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
            temp->prev = tail;
            tail = tail->next;
        }
        temp = NULL;
    }
    void deleteHead()
    {
        if (head != NULL)
        {
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            else
            {
                tail = NULL;
                empt = 1;
            }
        }
    }
    void deleteTail()
    {
        if (tail != NULL)
        {
            tail = tail->prev;
            if (tail != NULL)
                tail->next = NULL;
            else
            {
                head = NULL;
                empt = 1;
            }
        }
    }
    void deleteX(int x)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (x == temp->val)
            {
                if (temp == head)
                {
                    deleteHead();
                }
                else if (temp == tail)
                {
                    deleteTail();
                }
                else
                {
                    temp->next->prev = temp->prev;
                    temp->prev->next = temp->next;
                }
                break;
            }
            temp = temp->next;
        }
        temp = NULL;
    }
    int front()
    {
        if (head != NULL)
            return head->val;
        else
            return 0;
    }
    int back()
    {
        if (tail != NULL)
            return tail->val;
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
    l->addFirst(45);
    l->addFirst(35);
    l->deleteHead();
    l->print();
    l->addLast(9);
    l->print();
    // l->deleteHead();
    l->deleteHead();
    l->deleteTail();
    // l->deleteHead();
    // l->deleteHead();
    l->print();
    l->addFirst(3);
    l->addFirst(63);
    l->addFirst(23);
    l->addFirst(10);
    l->print();
    // l->deleteX(10);
    l->print();
    cout << l->front() << endl;
    l->print();
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin>>t;

    for (int i = 1; i <= t; i++)
    {
        // cout<<"Case "<<i<<": ";
        kire();
    }

    tata;
}