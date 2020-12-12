#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode *rotateRight(ListNode *head, int k)
{
    if(head == NULL)
    {
        return head;
    }
    vector<ListNode *> list;
    ListNode *temp = head;
    while(temp!=NULL)
    {
        list.emplace_back(temp);
        temp = temp->next;
    }
    int size = list.size();
    k = k >= size ? k % size : k;
    if(k == 0 || size == 1)
    {
        return head;
    }
    ListNode *newHead = list[size - k];
    ListNode *newTail = list[size - k - 1];
    ListNode *oldTail = list[size - 1];
    oldTail->next = head;
    newTail->next = NULL;
    return newHead;
}

int main()
{
    ListNode node2(2, NULL);
    ListNode node1(1, &node2);

    ListNode *head = &node1;
    rotateRight(head,2);
}