// 9.3
// 二分探索木: 探索

#include <iostream>
#include <string>
#include <cstdlib> // macllocに必要

using namespace std;

struct Node
{
    int key;
    Node *parent, *right, *left;
};

Node *root, *NIL;

void insert(int k)
{
    Node *y = NIL;
    Node *x = root;
    Node *z;

    z = (Node *)malloc(sizeof(Node));
    z->key = k;
    z->left = NIL;
    z->right = NIL;

    while ( x != NIL)
    {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == NIL)
    {
        root = z;
    } else {
        if (z->key < y->key)
        {
            y->left = z;
        } else {
            y->right = z;
        }
    }

}

Node *find(Node *u, int k)
{
    while ( u != NIL && k != u->key)
    {
        if ( k < u->key )
            u = u->left;
        else
            u = u->right;
    }

    return u;
}

void inorder(Node *u)
{
    if (u == NIL) return;
    inorder(u->left);
    cout << " " << u->key;
    inorder(u->right);
}

void preorder(Node *u)
{
    if (u == NIL) return;
    cout << " " << u->key;
    preorder(u->left);
    preorder(u->right);
}

int main()
{
    int n, x;
    string command;
    Node *t;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == "insert")
        {
            cin >> x;
            insert(x);
        }
        else if (command == "find")
        {
            cin >> x;
            t = find(root, x);
            if (t != NIL)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
        else if (command == "print")
        {
            inorder(root);
            cout << endl;
            preorder(root);
            cout << endl;
        }
    }

    return 0;
}