#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} *head = nullptr;

ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode *sorted_temp = new ListNode;
    ListNode *current_node = sorted_temp;

    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val < l2->val)
        {
            current_node->next = l1;
            l1 = l1->next;
        }
        else
        {
            current_node->next = l2;
            l2 = l2->next;
        }
        current_node = current_node->next;
    }
    if (l1 != nullptr)
    {
        current_node->next = l1;
        l1 = l1->next;
    }
    if (l2 != nullptr)
    {
        current_node->next = l2;
        l2 = l2->next;
    }
    return sorted_temp->next;
}

ListNode *sortList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *temp = head;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    temp->next = nullptr;

    ListNode *left_side = sortList(head);
    ListNode *right_side = sortList(slow);
    return merge(left_side, right_side);
}

void Insert(ListNode *p, int key)
{
    ListNode *newNode = new ListNode;
    newNode->next = nullptr;
    newNode->val = key;
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        while (p->next)
            p = p->next;
        p->next = newNode;
    }
}

void Display(ListNode *p)
{
    while (p)
    {
        cout << p->val << ' ';
        p = p->next;
    }
    cout << '\n';
}
int main()
{
    int arr[]{-1, 5, 3, 4, 0};
    for (int i = 0; i < 5; i++)
    {
        Insert(head, arr[i]);
    }
    Display(head);
    sortList(head);
    Display(head);
}