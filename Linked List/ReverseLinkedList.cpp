#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *first = nullptr;

void Insert(Node **q, int key)
{
    Node *newNode = new Node;
    newNode->next = nullptr;
    newNode->data = key;
    if (*q == nullptr)
    {
        *q = newNode;
        return;
    }
    Node *p = *q;
    while (p->next)
        p = p->next;
    p->next = newNode;
}
void ReverseUsingArray(Node **p)
{
    int arr[5];
    Node *q = *p;
    int i = 0;
    while (q)
    {
        arr[i++] = q->data;
        q = q->next;
    }
    q = *p;
    for (int i = 4; i >= 0; i--)
    {
        q->data = arr[i];
        q = q->next;
    }
}
void ReverseUsingSlidingPointers(Node *p)
{
    Node *q = nullptr, *r = nullptr;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
void ReverseUsingTwoPointers(Node *q, Node *p)
{

    if (p)
    {
        ReverseUsingTwoPointers(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

void Display(Node *p)
{
    while (p)
    {
        cout << p->data << ' ';
        p = p->next;
    }
}
int main()
{
    int arr[5]{1, 2, 3, 4, 5};
    for (size_t i = 0; i < 5; i++)
        Insert(&first, arr[i]);
    ReverseUsingTwoPointers(nullptr, first);
    Display(first);
}