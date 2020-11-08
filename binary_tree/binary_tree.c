#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"


void stack_one_init(int size)
{
    stack1 = (item**)calloc(size, sizeof(item*));
}
void stack_two_init(int size)
{
    stack2 = (item**)calloc(size, sizeof(item*));
}
void stack_init(int size)
{
    stack_one_init(size);
    stack_two_init(size);
}

void push_one(item* item)
{
    stack1[size_of_stack_one++] = item;
}
item* pop_one()
{
    if(size_of_stack_one<=0)
    {
        return NULL;
    }
    return stack1[--size_of_stack_one];
}

void push_two(item* item)
{
    stack2[size_of_stack_two++] = item;
}
item* pop_two()
{
    if(size_of_stack_two<=0)
    {
        return NULL;
    }
    return stack2[--size_of_stack_two];
}

// =============================== stack init finished =========================================

item* item_new(int val)
{
    item* new = (item*)calloc(1,sizeof(item));
    new->val = val;
    return new;
}

int getVal(btree* p_btree)
{
    if(!p_btree)
    {
        return NULL;
    }
    return p_btree->data->val;
}

btree* btree_init(int size)
{
    for(int i = 0;i<size;i++)
    {
        insert_btree_nonrecursive(item_new(i));
    }
    return head;
}

btree* btree_init_with_arr(int *arr, int size)
{
    for(int i = 0;i<size;i++)
    {
        insert_btree_recursive(head, item_new(arr[i]));
    }
    return head;
}

//有序二叉树，升序排列,非递归插入
//用一个parent保存cur信息，遍历cur判断插入位置
void insert_btree_nonrecursive(item* item)
{
    btree* cur = head;
    btree* parent = NULL;
    btree* new = (btree*)calloc(1,sizeof(btree));
    new->data = item;
    if(!cur)
    {
        head = new;
        return;
    }
    while(cur)
    {
        parent = cur;
        if(getVal(new) >= getVal(cur))
        {
            cur = cur->right;
        }else
        {
            cur = cur->left;
        }
    }
    if(getVal(new) >= getVal(parent))
    {
        parent->right = new;
    }else
    {
        parent->left = new;
    }
    tree_size++;
}

btree* insert_btree_recursive(btree* cur, item* item)
{
    if(head == NULL)
    {
        btree * new = (btree *)calloc(1,sizeof(btree));
        new->data = item;
        new->left = NULL;
        new->right = NULL;
        head = new;
        return head;
    }
    if(!cur)
    {
        // printf("1\n");
        btree * new = (btree *)calloc(1,sizeof(btree));
        new->data = item;
        new->left = NULL;
        new->right = NULL;
        return new;
    }
    if(item->val <= getVal(cur))
    {
        cur->left = insert_btree_recursive(cur->left,item);
    }
    else
    {
        cur->right = insert_btree_recursive(cur->right,item);
    }

    return cur;
}

void prefix_recursive(btree* p_btree)
{
    if(p_btree)
    {
        printf("%d ", getVal(p_btree));
        prefix_recursive(p_btree->left);
        prefix_recursive(p_btree->right);
    }
}
void infix_recursive(btree* p_btree)
{
    if(p_btree)
    {
        infix_recursive(p_btree->left);
        printf("%d ", getVal(p_btree));
        infix_recursive(p_btree->right);
    }
}
void suffix_recursive(btree* p_btree)
{
    if(p_btree)
    {
        suffix_recursive(p_btree->left);
        suffix_recursive(p_btree->right);
        printf("%d ", getVal(p_btree));
    }
}

void prefix_nonrecursive(btree* p_btree)
{

}
void infix_nonrecursive(btree* p_btree)
{

}
void suffix_nonrecursive(btree* p_btree)
{

}

btree* search_recursive(btree* p_btree, int target)
{
    //找到结果或找到空结点，返回
    if(!p_btree || getVal(p_btree) == target)
    {
        return p_btree;
    }
    if(getVal(p_btree) >= target)
    {
        return search_recursive(p_btree->left,target);
    }else
    {
        return search_recursive(p_btree->right,target);
    }
    
}
btree* search_nonrecursive(btree* p_btree, int target)
{
    btree* cur = p_btree;
    btree* res = NULL;
    while(cur)
    {
        if(getVal(cur) == target)
        {
            res = cur;
            break;
        }
        cur = target <= getVal(cur)?cur->left:cur->right;
    }
    return res;
}

int main()
{
    int arr[] = {5,1,3,12,0,8,7,15,9,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    btree* head = btree_init_with_arr(arr,size);
    infix_recursive(head);
    printf("\n");

    btree* res_r = search_recursive(head,12);
    btree* res_nr = search_nonrecursive(head,12);

    printf("res_r = %d, res_nr = %d\n", getVal(res_r), getVal(res_nr));
}

