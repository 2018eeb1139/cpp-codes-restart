#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
}

Node *
lca(Node *root, int a, int b)
{
    if (root == NULL)
        return root;
    if (root->data == a || root->data == b)
        return root;

    Node *left = lca(root->left, a, b);
    Node *right = lca(root->right, a, b);

    if (left != NULL && right != NULL)
        return root;

    if (left != NULL)
        return left;
    else
        return right;
}

int distance(Node *root, int n, int start)
{
    if (root == NULL)
        return -1;
    if (root->data == n)
        return start;

    int left_distance = distance(root->left, n, start + 1);

    if (left_distance != -1)
        return left_distance;

    return distance(root->right, n, start + 1);
}

int findDist(Node *root, int a, int b)
{
    // Your code here
    Node *LCA = lca(root, a, b);
    if (!LCA)
        return -1;
    int start_distance = 0;
    int dist1 = distance(LCA, a, start_distance);
    int dist2 = distance(LCA, b, start_distance);

    return dist1 + dist2;
}