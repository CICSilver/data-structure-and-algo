#include "file_opera.h"

//使用保存文件进行初始化操作
void init_with_file()
{
    FILE * fp;
    if((fp = fopen(SAVE_FILE_NAME, "r")) == NULL)
    {
        printf("文件打开失败\n");
        return NULL;
    }
    isUpdated = 0;
    if(fp == NULL)
    {
        return;
    }
    
    book* p_book = (book *)calloc(1, sizeof(book));
    int size_of_book_in_file;
    fscanf(fp, "size_of_book_in_file = %d \n", &size_of_book_in_file);
    for(int i = 0;i<size_of_book_in_file;i++)
    {
        fscanf(fp, "ISBN:%s | 书名:%s | 作者:%s | 页数:%d | 出版社:%s | 价格:%lf \n", 
                    p_book->ISBN, p_book->book_name, p_book->author, &p_book->page_size, p_book->publish, &p_book->price);
        add(book_new(p_book->ISBN, p_book->book_name, p_book->author, p_book->page_size, p_book->publish, p_book->price));
        // printf("%d\n", i);
    }
    fclose(fp);
    free(p_book);
    p_book = NULL;
}
//保存当前链表信息到文件中
void save_books_to_file()
{
    if(!isUpdated)
    {
        return;
    }
    FILE *fp;
    if ((fp = fopen(SAVE_FILE_NAME, "w")) == NULL)
    {
        printf("文件打开失败\n");
        return NULL;
    }
    node *temp = getHead();
    int size = getSize(temp);
    fprintf(fp, "size_of_book_in_file = %d \n", size);
    printf("%d\n", size);
    while (temp != NULL)
    {
        write_book(temp->cur, fp);
        temp = temp->next;
    }
    fclose(fp);
}
//写入一本书的信息
void write_book(book* p_book, FILE * fp)
{
    fprintf(fp, "ISBN:%s | 书名:%s | 作者:%s | 页数:%d | 出版社:%s | 价格:%lf \n", 
        p_book->ISBN, p_book->book_name, p_book->author, p_book->page_size, p_book->publish, p_book->price);
}

void clean_file()
{
    FILE *fp;
    if ((fp = fopen(SAVE_FILE_NAME, "w+")) == NULL)
    {
        printf("文件打开失败\n");
        return NULL;
    }
    fclose(fp);
}