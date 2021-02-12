#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    auto tempHead = headA;
    while (tempHead->next != NULL)
    {
        tempHead = tempHead->next;
    }
    auto link = tempHead;
    tempHead->next = headB;
    tempHead = headA;
    auto slow = tempHead;
    auto fast = tempHead;
    ListNode *ret = NULL;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            ret = fast;
            break;
        }
    }
    link->next = NULL;
    return ret;
}

int main(int argc, char *argv[])
{
    ListNode *node0 = new ListNode(4);
    ListNode *node1 = new ListNode(1);

    ListNode *node2 = new ListNode(5);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(1);

    ListNode *node5 = new ListNode(8);
    ListNode *node6 = new ListNode(4);
    ListNode *node7 = new ListNode(5);

    node5->next = node6;
    node6->next = node7;

    node0->next = node1;
    node1->next = node5;

    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    getIntersectionNode(node0, node2);
}