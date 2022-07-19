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

bool isLoop(Node *head)
{
    Node *p = head;
    Node *q = head;
    while (q && q->next)
    {
        q = q->next->next;
        p = p->next;
        if (p == q)
            return 1;
    }
    return 0;
}

int main()
{
    int arr[]{1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        Insert(&first, arr[i]);
    }

    /*
    int count = 0;
    Node *q = first;
    while (q && count != 2)   //Uncomment this for making Linked List Cyclic.
    {
        q = q->next;
        count++;
    }
    q->next = first;
    */
    cout << isLoop(first);
}