
#include <bits/stdc++.h>
using namespace std;

struct Node
{

    int val;
    Node *left;
    Node *right;
    int height;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};

int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

Node *rotateRight(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;

    return x;
}

Node *rotateLeft(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;

    return y;
}

int balancingFactor(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) -
           height(N->right);
}

Node *insert(Node *node, int val)
{

    if (node == NULL)
        return (new Node(val));

    if (val < node->val)
        node->left = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);
    else
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = balancingFactor(node);

    if (balance > 1 && val < node->left->val)
        return rotateRight(node);

    else if (balance < -1 && val > node->right->val)
        return rotateLeft(node);

    else if (balance > 1 && val > node->left->val)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    else if (balance < -1 && val < node->right->val)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

Node *leastValNode(Node *node)
{
    Node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

Node *deleteNode(Node *root, int val)
{

    if (root == NULL)
        return root;

    if (val < root->val)
        root->left = deleteNode(root->left, val);

    else if (val > root->val)
        root->right = deleteNode(root->right, val);

    else
    {

        if ((root->left == NULL) || (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;

            free(temp);
        }
        else
        {

            Node *temp = leastValNode(root->right);

            root->val = temp->val;

            root->right = deleteNode(root->right, temp->val);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = balancingFactor(root);

    if (balance > 1 && balancingFactor(root->left) >= 0)
        return rotateRight(root);

    if (balance > 1 && balancingFactor(root->left) < 0)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && balancingFactor(root->right) <= 0)
        return rotateLeft(root);

    if (balance < -1 && balancingFactor(root->right) > 0)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;

    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);

    root = deleteNode(root, 10);

    cout << "\nPreorder traversal after"
         << " deletion of 10 \n";
    preOrder(root);

    return 0;
}
