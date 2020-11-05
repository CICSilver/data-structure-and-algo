#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "book_manager.h"

#define DEBUG

node *head = NULL;
node *tail = NULL;

book *book_new(char *ISBN, char *book_name, char *author, int page_size, char *publish, double price)
{
    book *p_book = (book *)calloc(1, sizeof(book));
    strcpy(p_book->ISBN, ISBN);
    strcpy(p_book->book_name, book_name);
    strcpy(p_book->author, author);
    p_book->page_size = page_size;
    strcpy(p_book->publish, publish);
    p_book->price = price;
    return p_book;
}

void add(book *p_book)
{
    add_front(p_book, head);
}

void add_front(book *p_book, node *p_node)
{
    node *new_node = (node *)calloc(1, sizeof(node));
    new_node->cur = p_book;
    //不指定则默认在头部插入
    if (p_node == head)
    {
        if (head == NULL)
        {
            new_node->prev = NULL;
            new_node->next = NULL;
            head = new_node;
            tail = new_node;
        }
        else
        {
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
        }
    }
    else
    {
        new_node->prev = p_node->prev;
        new_node->next = p_node;
        p_node->prev->next = new_node;
        p_node->prev = new_node;
    }
}

void add_front_by_ISBN(book *new_book, char *ISBN)
{
    add_front(new_book, search_by_ISBN(ISBN, 1));
}

void add_front_by_bookInfo(book *new_book, char *book_name, char *author)
{
    add_front(new_book, search_by_bookInfo(book_name, author, 1));
}

void add_tail(book* p_book, node* p_node)
{
    node* new_node = (node *)calloc(1, sizeof(node));
    new_node->cur = p_book;
    //默认在末尾插入
    if(p_node == NULL)
    {
        if(tail == NULL)
        {
            new_node->prev = NULL;
            new_node->next = NULL;
            head = new_node;
            tail = new_node;
        }else
        {
            tail->next = new_node;
            new_node->prev = tail;
            new_node->next = NULL;
            tail = new_node;
        }
    }else
    {
        new_node->prev = p_node;
        new_node->next = p_node->next;
        p_node->next->prev = new_node;
        p_node->next = new_node;
    }
}

void add_tail_by_ISBN(book* new_book, char* ISBN)
{
    add_tail(new_book, search_by_ISBN(ISBN, 1));
}
void add_tail_by_bookInfo(book* new_book, char* book_name, char* author)
{
    add_tail(new_book, search_by_bookInfo(book_name, author, 1));
}

//搜素-删除辅助函数
node *search_help_func(node *bookNode, node *search_res_head, int isDel, int isOld)
{
    if (isDel == OPT_DEL)
    {
        del(bookNode);
    }
    else if (isOld)
    {
        return bookNode;
    }
    else
    {
        return add_search_res(search_res_new(bookNode->cur), search_res_head);
    }
}

node *search(char *book_name, char *author, char *ISBN, int opt, int isDel, int isOld)
{
    node *search_res_head = search_res_new(NULL);
    node *temp_head = head;
    while (temp_head != NULL)
    {
        switch (opt)
        {
        case OPT_NAME:
        {
            if (strcmp(temp_head->cur->book_name, book_name) == 0)
            {
                search_res_head = search_help_func(temp_head, search_res_head, isDel, isOld);
            }
            break;
        }
        case OPT_AUTHOR:
        {
            if (strcmp(temp_head->cur->author, author) == 0)
            {
                search_res_head = search_help_func(temp_head, search_res_head, isDel, isOld);
            }
            break;
        }
        case OPT_ISBN:
        {
            if (strcmp(temp_head->cur->ISBN, ISBN) == 0)
            {
                search_res_head = search_help_func(temp_head, search_res_head, isDel, isOld);
            }
            break;
        }
        case OPT_NAME_AUTH:
        {
            if (strcmp(temp_head->cur->book_name, book_name) == 0 && strcmp(temp_head->cur->author, author) == 0)
            {
                search_res_head = search_help_func(temp_head, search_res_head, isDel, isOld);
            }
            break;
        }
        default:
            break;
        }
        temp_head = temp_head->next;
    }
    return search_res_head;
}

node *search_res_new(book *p_book)
{
    if (p_book == NULL)
    {
        return NULL;
    }
    node *search_res = (node *)calloc(1, sizeof(node));
    search_res->cur = p_book;
    // printf("1\n");
    return search_res;
}

node *add_search_res(node *new_res, node *head)
{
    if (head != NULL)
    {
        new_res->prev = NULL;
        new_res->next = head;
        head->prev = new_res;
    }
    else
    {
        new_res->prev = NULL;
        new_res->next = NULL;
    }
    return new_res;
}

void print_search_list(node *search_res_head)
{
    if (search_res_head == NULL)
    {
        printf("无查询结果\n");
    }
    node *temp_head = search_res_head;
    while (temp_head != NULL)
    {
        show(temp_head);
        temp_head = temp_head->next;
    }
}

void destroy_search_list(node *search_res_head)
{
    node *temp_head = search_res_head;
    while (temp_head != NULL)
    {
        if (temp_head->next == NULL)
        {
            free(temp_head);
            break;
        }
        temp_head = temp_head->next;
        free(temp_head->prev);
    }
}

void del(node *node)
{
    if (node->prev == NULL)
    {
        head = node->next;
        head->prev = NULL;
        node->next = NULL;
    }
    else if (node->next == NULL)
    {
        node->prev->next = NULL;
        node->prev = NULL;
    }
    else
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = NULL;
        node->prev = NULL;
    }
    free(node);
}

void del_by_ISBN(char *ISBN)
{
    search(NULL, NULL, ISBN, OPT_NAME_AUTH, OPT_DEL, 0);
}

void del_by_bookInfo(char *book_name, char *author)
{
    search(book_name, author, NULL, OPT_NAME_AUTH, OPT_DEL, 0);
}

node *search_by_name(char *book_name,int isOld)
{
    return search(book_name, NULL, NULL, OPT_NAME, 0, isOld);
}

node *search_by_author(char *author,int isOld)
{
    return search(NULL, author, NULL, OPT_AUTHOR, 0, isOld);
}

node *search_by_ISBN(char *ISBN,int isOld)
{
    return search(NULL, NULL, ISBN, OPT_ISBN, 0, isOld);
}

node *search_by_bookInfo(char *book_name, char *author,int isOld)
{
    return search(book_name, author, NULL, OPT_NAME_AUTH, 0, isOld);
}

void printAll()
{
    print_with_head(head);
}

void show(node *cur_node)
{
    printf("ISBN:%4s  |  书名:%4s  |  作者:%4s  |  页数:%4d  |  出版社:%4s  |  价格:%4lf\n",
           cur_node->cur->ISBN, cur_node->cur->book_name, cur_node->cur->author, cur_node->cur->page_size,
           cur_node->cur->publish, cur_node->cur->price);
}

int update_helper_func(node *search_head, book *update_book)
{
    if (getSize(search_head) != 1)
    {
        return -1;
    }
    else
    {
        book_copy(search_head->cur, update_book);
        // show(search_head);
        // search_head->cur = update_book;
    }
    return 1;
}

//若查询结果不唯一则放弃修改
int update(book *update_book, char *ISBN, char *book_name, char *author, int opt)
{
    node *search_head;
    switch (opt)
    {
    case OPT_ISBN:
    {
        return update_helper_func(search_by_ISBN(ISBN, 0), update_book);
        break;
    }
    case OPT_NAME_AUTH:
    {
        search_head = search_by_bookInfo(book_name, author, 0);
        return update_helper_func(search_head, update_book);
        break;
    }
    default:
        break;
    }
}

int update_by_ISBN(book *update_book, char *ISBN)
{
    return update(update_book, ISBN, NULL, NULL, OPT_ISBN);
}

int update_by_bookInfo(book *update_book, char *book_name, char *author)
{
    return update(update_book, NULL, book_name, author, OPT_NAME_AUTH);
}

void book_copy(book *old_book, book *new_book)
{
    strcpy(old_book->ISBN, new_book->ISBN);
    strcpy(old_book->book_name, new_book->book_name);
    strcpy(old_book->author, new_book->author);
    old_book->page_size = new_book->page_size;
    strcpy(old_book->publish, new_book->publish);
    old_book->price = new_book->price;
}

int isExsist(book *p_book, node *temp_head)
{
    while (temp_head != NULL)
    {
        if (temp_head->cur == p_book)
        {
            return 1;
        }
        temp_head = temp_head->next;
    }
    return 0;
}

int getSize(node *temp_head)
{
    int count = 0;
    while (temp_head != NULL)
    {
        count++;
        temp_head = temp_head->next;
    }
    return count;
}

void print_with_head(node* nodeHead)
{
    node *temp_head = nodeHead;
    while (temp_head != NULL)
    {
        show(temp_head);
        temp_head = temp_head->next;
    }
}

// int main1()
// {
//     book *b1 = book_new("123", "从入门到入坟", "爷", 20, "无", 20.0);
//     book *b2 = book_new("1234", "打发手动阀", "爷", 20, "调度", 20.0);
//     book *b3 = book_new("12345", "从入门到入坟", "爷1", 200, "aaa", 200.0);
//     add(b1);
    
//     add(b2);
//     add(b3);
//     printAll();
//     printf("%d\n",getSize(head));
// }
