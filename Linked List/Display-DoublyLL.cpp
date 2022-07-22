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
    int arr[]{1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        Insert(first, arr[i]);
    }
    Display(first);
}