#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *head = nullptr;

void Insert(Node *p, int key)
{
    Node *newNode = new Node;
    newNode->data = key;
    newNode->next = nullptr;
    if (head == NULL)
        head = newNode;
    else
    {
        while (p->next)
            p = p->next;
        p->next = newNode;
    }
}

void RemovingDuplicates(Node *p)
{
    Node *q = head->next;
    while (q && p)
    {
        if (p->data != q->data)
        {
            p = p->next;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
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

int main()
{
    int arr[]{3, 5, 5, 8, 8, 8};
    for (int i = 0; i < 6; i++)
    {
        Insert(head, arr[i]);
    }
    // Display(head);
    RemovingDuplicates(head);
    Display(head);
}
