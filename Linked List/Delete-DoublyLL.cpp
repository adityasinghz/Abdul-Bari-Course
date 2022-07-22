#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
} *first = nullptr;

void Insert(Node *p, int key)
{
    Node *newNode = new Node;
    newNode->prev = nullptr;
    newNode->data = key;
    newNode->next = nullptr;
    if (first == nullptr)
    {
        first = newNode;
        return;
    }
    Node *q = p;
    while (q->next)
        q = q->next;
    newNode->prev = q;
    q->next = newNode;
}

void Delete(Node *p, int pos)
{

    if (pos == 0)
    {
        first = first->next;
        delete p;
        return;
    }

    Node *q = p;
    for (int i = 0; i < pos - 1; i++)
    {
        q = q->next;
    }
    q->prev->next = q->next;
    if (q->next)
        q->next->prev = q->prev;
    delete q;
}
void Display(Node *p)
{
    if (p)
    {
        cout << p->data << ' ';
        Display(p->next);
    }
}

int main()
{
    int arr[]{1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        Insert(first, arr[i]);
    }
    Delete(first, 0);
    Delete(first, 5);
    Display(first);
}