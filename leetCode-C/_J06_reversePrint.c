#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


int* reversePrint(struct ListNode* head, int* returnSize)
{
    int stack[10001];
    *returnSize = 0;
    int count = 0;
    while(head != NULL)
    {
        stack[count++] = head->val;
        head = head->next;
    }

    int *res = (int*)calloc(count,sizeof(int));
    while(count>0)
    {
        res[(*returnSize)++] = stack[count--];
    }
    return res;
}