#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    Node *next;
    int data;
} *first = nullptr;

void Delete(Node *p, int pos)
{
    Node *q = p;
    Node *t = p;
    for (int i = 0; i < pos - 1; i++)
    {
        q = t;
        t = t->next;
    }
    q->next = t->next;
    delete t;
}

void Insert(Node **p, int key)
{
    Node *newNode = new Node;
    newNode->next = nullptr;
    newNode->data = key;
    if (first == nullptr)
    {
        first = newNode;
        return;
    }

    Node *q = *p;
    while (q->next)
        q = q->next;
    q->next = newNode;
}

void Display(Node *p)
{
    static int flag = 0;
    if (p != first || flag == 0)
    {
        flag = 1;
        cout << p->data << ' ';
        Display(p->next);
    }
    flag = 0;
}

int main()
{
    int arr[]{1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < 5; i++)
    {
        Insert(&first, arr[i]);
    }
    Node *last = first;
    while (last->next)
    {
        last = last->next;
    }
    last->next = first;

    Delete(first, 3);
    Display(first);
}