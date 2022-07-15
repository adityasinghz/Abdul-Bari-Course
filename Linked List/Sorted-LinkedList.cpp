#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *first = nullptr;

void insertSorted(struct Node *p, int key)
{
    Node *q = nullptr;
    Node *newNode = new Node;
    newNode->next = nullptr;
    newNode->data = key;
    if (first == nullptr)
        first = newNode;
    else
    {
        while (p && p->data < key)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            newNode->next = first;
            first = newNode;
        }
        else
        {
            newNode->next = q->next;
            q->next = newNode;
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
    int arr[]{23, 1, 43, 5, 21};
    for (size_t i = 0; i < 5; i++)
    {
        insertSorted(first, arr[i]);
    }
    Display(first);
}