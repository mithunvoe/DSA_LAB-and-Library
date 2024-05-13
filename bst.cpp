#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tata return 0
#define all(v) v.begin(), v.end()
#define endl '\n'
#define gap ' '

const int M = 1e9 + 7;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }
};

struct BST
{
    Node *root;
    void createNode(int val, Node *&temp)
    {
        if (temp == NULL)
        {
            temp = new Node(val);
            return;
        }
        if (temp->val > val)
        {
            createNode(val, temp->left);
        }
        else if (temp->val < val)
        {
            createNode(val, temp->right);
        }
    }
    void traverse(Node *temp)
    {
        if (temp == NULL)
            return;
        traverse(temp->left);
        cout << temp->val << gap;
        traverse(temp->right);
    }
    Node *deleteNode(Node *root, int k)
    {

        if (root == NULL)
            return root;

        if (root->val > k)
        {
            root->left = deleteNode(root->left, k);
            return root;
        }
        else if (root->val < k)
        {
            root->right = deleteNode(root->right, k);
            return root;
        }

        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        else
        {

            Node *succParent = root;

            Node *succ = root->right;
            while (succ->left != NULL)
            {
                succParent = succ;
                succ = succ->left;
            }
            if (succParent != root)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;

            root->val = succ->val;

            delete succ;
            return root;
        }
    }
};
void kire()
{
    BST *tree = new BST();
    tree->createNode(5, tree->root);
    tree->createNode(3, tree->root);
    tree->createNode(7, tree->root);
    tree->createNode(2, tree->root);
    tree->createNode(4, tree->root);
    tree->createNode(6, tree->root);
    tree->createNode(8, tree->root);
    tree->traverse(tree->root);
    cout << endl;
    tree->deleteNode(tree->root, 5);
    tree->traverse(tree->root);
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
