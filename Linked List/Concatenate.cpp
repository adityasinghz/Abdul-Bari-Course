#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
} *first = nullptr, *second = nullptr;

void Insert(Node *p, int key)
{
    Node *newNode = new Node;
    newNode->data = key;
    newNode->next = nullptr;

    if (first == nullptr)
        first = newNode;
    else
    {
        while (p->next)
        {
            p = p->next;
        }
        p->next = newNode;
    }
}
void Display(Node *p)
{
    while (p)
    {
        cout << p->data << ' ';
        p = p->next;
    }
}

void Concat(Node *p, Node *q)
{
    if (p == nullptr || q == nullptr)
    {
        p = q;
        return;
    }
    while (p->next)
        p = p->next;
    p->next = q;
}

int main()
{
    int arr[]{2, 9, 6, 8};
    int arr1[]{10, 4, 7};
    int m = sizeof(arr) / sizeof(arr[0]);
    int n = sizeof(arr1) / sizeof(arr1[0]);
    for (int i = 0; i < m; i++)
        Insert(first, arr[i]);

    Display(first);
}