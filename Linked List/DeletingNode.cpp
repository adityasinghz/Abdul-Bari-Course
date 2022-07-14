#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *first = nullptr;

void Insert(Node **p, int key)
{
    Node *newNode = new Node;
    newNode->data = key;
    newNode->next = nullptr;
    if (*p == nullptr)
    {
        *p = newNode;
        return;
    }
    Node *q = *p;
    while (q->next)
        q = q->next;
    q->next = newNode;
}
void DeleteNode(Node *p, int pos)
{
    Node *q = nullptr;
    for (int i = 0; i < pos - 1; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    delete p;
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
    for (int i = 0; i < 10; i++)
        Insert(&first, i);
    DeleteNode(first, 4);
    Display(first);
}