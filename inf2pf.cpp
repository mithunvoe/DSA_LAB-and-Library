#include <bits/stdc++.h>
using namespace std;
#define gap ' '
// linkedlist for stack
struct vuaStack
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

// Function to return precedence of operators
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to return associativity of operators
char associativity(char c)
{
    if (c == '^')
        return 'R';
    return 'L'; // Default to left-associative
}

// The main function to convert infix expression
// to postfix expression
void infixToPostfix(string s)
{
    // stack<char> st;
    vuaStack *st = new vuaStack;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        // If the scanned character is
        // an operand, add it to the output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (c == '(')
            st->addLast('(');

        // If the scanned character is an ‘)’,
        // pop and add to the output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')')
        {
            while (st->back() != '(')
            {
                result += st->back();
                st->deleteTail();
            }
                st->deleteTail();
             // Pop '('
        }

        // If an operator is scanned
        else
        {
            while (!st->empty() && prec(s[i]) < prec(st->back()) || !st->empty() && prec(s[i]) == prec(st->back()) && associativity(s[i]) == 'L')
            {
                result += st->back();
                st->deleteTail();;
            }
            st->addLast(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st->empty())
    {
        result += st->back();
        st->deleteTail();;
    }

    cout << result << endl;
}

// Driver code
int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";

    // Function call
    infixToPostfix(exp);

    return 0;
}
