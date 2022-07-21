#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *next;
} *first = nullptr;

void NormalInsert(Node *p, int key)
{
  Node *newNode = new Node;
  newNode->next = nullptr;
  newNode->data = key;
  if (first == nullptr)
  {
    first = newNode;
    return;
  }
  else
  {
    Node *q = p;
    while (q->next)
      q = q->next;

    q->next = newNode;
  }
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

void InsertCyclic(Node **p, int key, int pos)
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
  if (pos == 0)
  {
    Node *l = *p;
    while (l->next && l->next != *p)
    {
      l = l->next;
    }
    newNode->next = *p;
    *p = newNode;
    l->next = *p;
    return;
  }
  for (int i = 0; i < pos - 1; i++)
  {
    q = q->next;
  }
  newNode->next = q->next;
  q->next = newNode;
}

int main()
{
  int arr[]{1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < n; i++)
  {
    NormalInsert(first, arr[i]);
  }
  Node *last = first;
  while (last->next)
    last = last->next;

  last->next = first;

  InsertCyclic(&first, 89, 3);
  InsertCyclic(&first, 78, 0);
  InsertCyclic(&first, 81, 0);
  Display(first);
}