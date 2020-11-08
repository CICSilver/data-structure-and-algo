#ifndef _FILE_OPERA_H
#define _FILE_OPERA_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "book_manager.h"

#define SAVE_FILE_NAME "books_info.txt"

//记录是否对链表进行过任何操作
int isUpdated;

// //记录文件中的记录条数
// int size_of_book_in_file = 0;

//使用保存文件进行初始化操作
void init_with_file();
//保存当前链表信息到文件中
void save_books_to_file();
//写入一本书的信息
void write_book(book* p_book, FILE * fp);

void clean_file();


#endif