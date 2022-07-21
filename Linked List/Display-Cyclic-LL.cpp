#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node *next;
    int data;
} *first = nullptr;

void Insert(Node **p, int key)
{
    Node *newNode = new Node;
    newNode->next = nullptr;
    newNode->data = key;
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
    for (int i = 0; i < 5; i++)
    {
        Insert(&first, arr[i]);
    }
    Display(first);
}