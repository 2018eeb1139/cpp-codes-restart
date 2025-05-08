#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArrayToLinkedList(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthOfLL(Node *head)
{
    int ct = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        ct++;
        temp = temp->next;
    }
    return ct;
}

int search(Node *head, int val)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == val)
            return 1;
        temp = temp->next;
    }
    return 0;
}

Node *deleteHead(Node *head)
{
    if (head == nullptr)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node *removeKthNode(Node *head, int k)
{
    if (head == nullptr)
        return head;
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int ct = 0;
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != NULL)
    {
        ct++;
        if (ct == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *removeElement(Node *head, int el)
{
    if (head == nullptr)
        return head;
    if (head->data == el)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != NULL)
    {
        if (temp->data == el)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *insertHead(Node *head, int val)
{
    Node *temp = new Node(val, head);
    return temp;
}

Node *insertTail(Node *head, int val)
{
    if (head == NULL)
    {
        return new Node(val);
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(val);
    temp->next = newNode;
    return head;
}

Node *insertPosition(Node *head, int el, int k)
{
    if (head == NULL)
    {
        if (k == 1)
        {
            return new Node(el);
        }
        else
        {
            return head;
        }
    }
    if (k == 1)
    {
        Node *temp = new Node(el, head);
        return temp;
    }
    int ct = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        ct++;
        if (ct == (k - 1))
        {
            Node *x = new Node(el);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node *insertBeforeVal(Node *head, int el, int val)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data == val)
    {
        Node *temp = new Node(el, head);
        return temp;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == val)
        {
            Node *x = new Node(el);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {1, 3, 5, 2};
    Node *y = new Node(arr[0], nullptr);
    // cout << y->data;
    // cout << y->next;
    Node *head = convertArrayToLinkedList(arr);
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data;
        temp = temp->next;
    }
}