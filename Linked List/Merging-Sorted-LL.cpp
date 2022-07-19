#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *first = nullptr, *second = nullptr, *third = nullptr;

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
    {
        q = q->next;
    }
    q->next = newNode;
}

void MergesortedLL(Node *p, Node *q)
{
    Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = nullptr;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = nullptr;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = nullptr;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = nullptr;
        }
    }
    if (p)
        last->next = p;

    if (q)
        last->next = q;
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
    int arr[]{2, 3, 4, 5, 6, 89};
    int m = sizeof(arr) / sizeof(arr[0]);
    int arr1[]{4, 5, 6, 7, 8, 111};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    for (int i = 0; i < m; i++)
        Insert(&first, arr[i]);

    for (int i = 0; i < n; i++)
        Insert(&second, arr1[i]);

    MergesortedLL(first, second);
    Display(third);
}