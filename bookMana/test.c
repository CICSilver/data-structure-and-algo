#include "book_manager.h"
#include "file_opera.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>

#define ISBN_LEN 13

char *getISBN(int seed)
{
    char *ISBN = (char *)calloc(ISBN_LEN, sizeof(char *));
    srand(seed);
    int i = 0;
    while(i<ISBN_LEN)
    {
        ISBN[i++] =(char) (rand()%10+48);
    }
    ISBN[i] = '\0';
    return ISBN;
}

void test_add()
{
    int len = 10;
    int seeds[10];
    char *ISBN[10];
    char *book_name[] = {
        "测试书名一",
        "测试书名二",
        "测试书名三",
        "测试书名四",
        "测试书名五",
        "测试书名六",
        "测试书名七",
        "测试书名八",
        "测试书名九",
        "测试书名十"
    };
    char *author[] = 
    {
        "作者0",
        "作者1",
        "作者2",
        "作者3",
        "作者4",
        "作者5",
        "作者6",
        "作者7",
        "作者8",
        "作者9"
    };
    char *publish[] = {
        "测试出版社一",
        "测试出版社二",
        "测试出版社三",
        "测试出版社四",
        "测试出版社五",
        "测试出版社六",
        "测试出版社七",
        "测试出版社八",
        "测试出版社九",
        "测试出版社十"
    };

    srand(time(NULL));
    for(int i = 0;i<10;i++)
    {
        seeds[i] = rand()%1000;
    }
    for(int i = 0;i<10;i++)
    {
        ISBN[i] = getISBN(seeds[i]);
    }

    
    for(int i = 0;i<10;i++)
    {
        add(book_new(ISBN[i], book_name[i], author[i], (i+1)*107, publish[i], (i+1)*12.0));     
    }
}

//指定头插入
void test_add_front(book* p_book)
{
    add_front_by_bookInfo(p_book, "测试书名六", "作者5");
}
//指定尾插入
void test_add_tail(book* p_book)
{
    add_tail_by_bookInfo(p_book, "测试书名九", "作者8");
}
//查找
void test_search()
{
    show(search_by_bookInfo("测试书名六", "作者5", 1));
}
//修改
void test_update()
{
    Book* p_book1 = book_new("0592038778285", "修改书名--原书二", "作者1", 214 , "测试出版社二", 23.0);
    int ret = update_by_bookInfo(p_book1, "测试书名二", "作者1");
    printf("%d\n", ret);
}
//重名插入
void test_add_duplicate()
{
    Book* p_book1 = book_new("4044204920559", "重名测试书一", "重名作者0", 300, "插入测试出版社", 543.0);
    Book* p_book2 = book_new("1808035262545", "重名测试书二", "重名作者0", 340, "插入测试出版社", 7654.0);
    add(p_book1);
    add(p_book2);
}

int main()
{
    Book* p_book1 = book_new("9123609048352", "文件测试一", "文件作者0", 888, "文件测试出版社", 888.0);
    // Book* p_book2 = book_new("6588532536940", "插入测试二", "插入作者1", 340, "插入测试出版社", 7654.0);
    init_with_file();
    // test_add();
    printAll();
    // printf("size of list = %d\n", getSize(getHead()));
    printf("==================================插入测试=========================================\n");
    // // test_search();
    // test_add_front(p_book1);
    // test_add_tail(p_book2);
    // printAll();
    // printf("==================================同作者所有作品搜索测试=========================================\n");
    // test_add_duplicate();
    // print_with_head(search_by_author("重名作者0", 0));
    // printf("==================================修改测试=========================================\n");
    // test_update();
    // printAll();
    // add(p_book1);
    save_books_to_file();
    // clean_file();
}  