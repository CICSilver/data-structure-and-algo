#include <stdlib.h>
#include <stdio.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode node;

//递归
struct ListNode* reverseList(struct ListNode* head){
    if(!head)
    {
        return NULL;
    }
    //next为Null的结点即新的头结点
    if(!head->next)
    {
        return head;
    }
    struct ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

//栈
struct ListNode* reverseList1(struct ListNode* head)
{
    struct ListNode** stack = (struct ListNode*)calloc(5001, sizeof(struct ListNode*));
    int count = 0;
    while(head->next)
    {
        stack[count++] = head;
        head = head->next;
    }
    stack[0]->next = NULL;
    printf("111\n");
    struct ListNode* new_head = head;
    // count--;
    while(count >0)
    {
        head->next = stack[--count];
        printf("count = %d\n", count);
        head = head->next;
    }
    return new_head;
}

struct ListNode* reverseList2(struct ListNode* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    if(head->next == NULL)
    {
        return head;
    }
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next;

    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

printAll(node* head)
{
    while(head)
    {
        printf("%d\n",head->val);
        head = head->next;
    }
}

int main()
{
    node* pn5 = (node *)malloc(sizeof(node));
    node* pn4 = (node *)malloc(sizeof(node));
    node* pn3 = (node *)malloc(sizeof(node));
    node* pn2 = (node *)malloc(sizeof(node));
    node* pn1 = (node *)malloc(sizeof(node));
    pn1->val = 1;
    pn1->next = pn2;
    pn2->val = 2;
    pn3->val = 3;
    pn4->val = 4;
    pn5->val = 5;
    pn2->next = pn3;
    pn3->next = pn4;
    pn4->next = pn5;
    pn5->next = NULL;
    printAll(pn1);
    printAll(reverseList1(pn1));
}