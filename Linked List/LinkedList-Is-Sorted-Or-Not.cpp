#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *next;
    int data;
} *first = nullptr;

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
            p = p->next;

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
bool CheckSort(Node *p)
{
    while (p->next)
    {
        if (p->data < p->next->data)
            p = p->next;
        else
            return false;
    }
    return true;
}
int main()
{
    int arr[]{1, 2, 9, 4};
    for (int i = 0; i < 4; i++)
    {
        Insert(first, arr[i]);
    }
    Display(first);
    cout << CheckSort(first) << ' ';
}