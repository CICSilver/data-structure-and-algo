#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}node;



struct ListNode* addTwoNumbers1(struct ListNode* l1, struct ListNode* l2)
{
    int size = 0;
    struct ListNode* temp_head = l1;
    while(temp_head)
    {
        size++;
        temp_head = temp_head->next;
    }
    int* val = (struct ListNode*) calloc(size,sizeof(struct ListNode));
    temp_head = l1;
    int count = 0;
    while(temp_head)
    {
        val[count++] = temp_head->val;
        temp_head = temp_head->next;
    }
    count--;
    struct ListNode* new_head1 = (struct ListNode*) calloc(1,sizeof(struct ListNode));
    struct ListNode* new_head = new_head1;
    temp_head = l2;
    int carry = 1;
    while(count >= 0)
    {
        struct ListNode* new_node = (struct ListNode*) calloc(1,sizeof(struct ListNode));
        int temp = (temp_head->val+val[count--])-10;
        if(temp >= 0)
        {
            new_node->val = 0;
        }
        else
        {
            new_node->val = temp+10;
        }
        new_head->next = new_node;
        new_head = new_node;
    }
    return new_head1->next;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int size = 0;
    int carry = 0;
    int isCarry = 0;
    struct ListNode* temp_head = l1;
    while (temp_head)
    {
        size++;
        temp_head = temp_head->next;
    }
    int* stack = (int *)calloc(size+1, sizeof(temp_head));
    int count = 0;
    while(l1 && l2)
    {
        int temp = l1->val+l2->val;
        int n;
        if(isCarry)
        {
            n++;
        }
        if(temp >= 10)
        {
            n = temp%10;
            if(isCarry)
            {
                n+=1;
                isCarry = 0;
            }
            carry = temp/10;
            isCarry = 1;
        }else
        {
            n = temp;
            if (isCarry)    
            {
                n+=1;
            }
            
            isCarry = 0;
            carry = 0;
        }
        
        stack[count++] = n;
        l1 = l1->next;
        l2 = l2->next;
    }
    struct ListNode* new_head = (struct ListNode*)calloc(1,sizeof(struct ListNode));
    struct ListNode* new_head_temp = new_head;
    int i = 0;
    while(i<count)
    {
        struct ListNode* new_node = (struct ListNode*)calloc(1,sizeof(struct ListNode));
        new_node->val = stack[i++];
        new_head->next = new_node;
        new_head = new_head->next;
    }
    
    while(l1)
    {
        int temp;
        if(isCarry)
        {
            temp = l1->val+carry;
            // printf("%d\n", l1->val);
            if(temp >= 10)
            {
                carry = temp/10;
                // printf("%d\n", temp+1);
                l1->val = temp%10;
                isCarry = 1;
            }else
            {
                l1->val = temp;
                isCarry = 0;
            }
        }
        new_head->next = l1;
        l1 = l1->next;
        new_head = new_head->next;
    
    }

    while(l2)
    {
        int temp;
        if(isCarry)
        {
            temp = l2->val+carry;
            if(temp >= 10)
            {
                carry = temp/10;
                l2->val = temp%10;
                isCarry = 1;
            }else
            {
                l2->val = temp;
                isCarry = 0;
            }
        }
        new_head->next = l2;
        l2 = l2->next;
        new_head = new_head->next;
    }

    if(isCarry)
    {
        struct ListNode* new_node = (struct ListNode*)calloc(1,sizeof(struct ListNode));
        new_node->val = carry;
        new_head->next = new_node;
    }

    return new_head_temp->next;
}

void printAll(node* head)
{
    while(head)
    {
        printf("%d ",head->val);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    node* l1_1 = (node *)calloc(1,sizeof(node));
    node* l1_2 = (node *)calloc(1,sizeof(node));
    node* l1_3 = (node *)calloc(1,sizeof(node));
    node* l1_4 = (node *)calloc(1,sizeof(node));
    node* l1_5 = (node *)calloc(1,sizeof(node));

    node* l2_1 = (node *)calloc(1,sizeof(node));
    node* l2_2 = (node *)calloc(1,sizeof(node));
    node* l2_3 = (node *)calloc(1,sizeof(node));

    l1_1->val = 9;
    l1_2->val = 9;
    l1_3->val = 1;
    l1_4->val = 9;
    l1_5->val = 9;

    l2_1->val = 1;
    l2_2->val = 6;
    l2_3->val = 4;

    l1_1->next = l1_2;
    l1_2->next = l1_3;
    // l1_3->next = l1_4;
    // l1_4->next = l1_5;

    // l2_1->next = l2_2;
    // l2_2->next = l2_3;

    printAll(l1_1);
    printAll(l2_1);

    printAll(addTwoNumbers(l1_1,l2_1));

}