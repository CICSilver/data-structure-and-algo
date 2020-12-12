#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// 经典的快慢指针

int kthToLast(ListNode *head, int k)
{
    ListNode *fast = head;
    for (int i = 0; i < k; ++i)
    {
        fast = fast->next;
    }
    while(fast != NULL)
    {
        head = head->next;
        fast = fast->next;
    }

    return head->val;
}