#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 1 2 2 1
// 1 2 3 2 1
bool isPalindrome(ListNode *head)
{
    if(head == NULL)
    {
        return true;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 翻转后半段
    ListNode *pre = NULL;
    ListNode *cur = slow;
    // 1 1 2 1 1
    while(cur != NULL)
    {
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    while (pre != NULL && head != NULL)
    {
        if(pre->val != head->val)
        {
            return false;
        }

        pre = pre->next;
        head = head->next;
    }

    return true;
}

int main(int argc, char *argv[])
{
    ListNode *node0 = new ListNode(1);
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(1);
    // ListNode *node4 = new ListNode(0);

    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    // node3->next = node4;

    cout << isPalindrome(node0) << endl;
}