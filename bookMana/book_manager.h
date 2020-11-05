#ifndef _BOOK_MANAGER_H
#define _BOOK_MANAGER_H

enum OPT
{
    OPT_ISBN,
    OPT_NAME,
    OPT_AUTHOR,
    OPT_NAME_AUTH,
    OPT_DEL
};

typedef struct _book
{
    char ISBN[14];
    char book_name[30];
    char author[30];
    int page_size;
    char publish[30];
    double price;
}book,Book;

typedef struct _node
{
    struct _node* prev;
    book* cur;
    struct _node* next;
}node;

//返回一个图书
book* book_new(char* ISBN, char* book_name, char* author, int page_size, char* publish, double price);

//头插入及两种辅助选择
void add(book*);
void add_front(book*, node*);
void add_front_by_ISBN(book* new_book, char* ISBN);
void add_front_by_bookInfo(book* new_book, char* book_name, char* author);

//尾插入及两种辅助选择
void add_tail(book*, node*);
void add_tail_by_ISBN(book* new_book, char* ISBN);
void add_tail_by_bookInfo(book* new_book, char* book_name, char* author);

//修改及两个辅助选择
int update(book* update_book,char* ISBN, char* book_name, char* author, int opt);
int update_by_ISBN(book* update_book,char* ISBN);
int update_by_bookInfo(book* update_book, char* book_name, char* author);

//删除及两个辅助选择
void del(node* node);
void del_by_ISBN(char* ISBN);
void del_by_bookInfo(char* book_name, char* author);

//搜索，返回一个新的结果链表的头结点
node* search(char* book_name, char* author, char* ISBN, int opt, int isDel, int isOld);
node* search_by_name(char* book_name,int isOld);
node* search_by_author(char* author,int isOld);
node* search_by_ISBN(char* ISBN,int isOld);
node* search_by_bookInfo(char* book_name, char* author,int isOld);
node* search_res_new(book* p_book);
//返回原链表中第一个匹配的结点
node* search_old_node(book* p_book);
//头部插入，返回新head
node* add_search_res(node* new_res, node* head);
//展示查找结果
void print_search_list(node* search_res_head);
//销毁查找结果链表
void destroy_search_list(node* search_res_head);

//遍历打印所有图书信息
void printAll();

void print_with_head(node* nodeHead);

//打印单个节点
void show(node *);

//判断指定图书是否存在
int isExsist(book* p_book, node* temp_head);

//获取总大小
int getSize(node* temp_head);

void book_copy(book* old_book, book* new_book);


#endif
