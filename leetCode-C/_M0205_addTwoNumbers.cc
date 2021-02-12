#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
 * 输出：2 -> 1 -> 9，即912 
 */

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr || l2 == nullptr)
    {
        return (l1 == nullptr) ? l2 : l1;
    }

    ListNode *VHead = new ListNode(NULL);
    auto l1_cur = l1;
    auto l2_cur = l2;
    auto ret_cur = VHead;

    bool carry = false;
    while (l1_cur != NULL && l2_cur != NULL)
    {
        // 循环加到其中一个指针指向末尾
        int res = l1_cur->val + l2_cur->val;
        if (carry)
        {
            // 有进位
            ++res;
        }
        carry = (res >= 10);
        res %= 10;
        ret_cur->next = new ListNode(res);

        ret_cur = ret_cur->next;
        l1_cur = l1_cur->next;
        l2_cur = l2_cur->next;
    }

    if (l1_cur == NULL)
    {
        // l1指向末尾， 处理l2剩余部分
        while (l2_cur != NULL)
        {
            int res = carry ? l2_cur->val + 1 : l2_cur->val;
            carry = (res >= 10);
            ret_cur->next = new ListNode(res%10);
            ret_cur = ret_cur->next;
            l2_cur = l2_cur->next;
        }
    }
    else
    {
        // l2指向末尾， 处理l1剩余部分
        while (l1_cur != NULL)
        {
            int res = carry ? l1_cur->val + 1 : l1_cur->val;
            ret_cur->next = new ListNode(res%10);
            carry = (res >= 10);
            ret_cur = ret_cur->next;
            l1_cur = l1_cur->next;
        }
    }
    ret_cur->next = carry ? new ListNode(1) : NULL;

    return VHead->next;
}

int main()
{
    ListNode *node0 = new ListNode(1);
    // ListNode *node1 = new ListNode(8);
    // ListNode *node2 = new ListNode(6);

    // node0->next = node1;
    // node1->next = node2;

    ListNode *node3 = new ListNode(9);
    ListNode *node4 = new ListNode(9);
    // ListNode *node5 = new ListNode(2);

    node3->next = node4;
    // node4->next = node5;

    auto ret = addTwoNumbers(node0, node3);

    while(ret != NULL)
    {
        cout << ret->val;
        ret = ret->next;
    }
    cout << endl;
}