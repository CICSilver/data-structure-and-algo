#ifndef _MYSTRING_H
#define _MYSTRING_H

#include <iostream>
#include <string.h>
#include <algorithm>

class MyString
{
public:
    MyString() : MyString(DEFAULT_SIZE) {}
    explicit MyString(const char *src) : MyString(src, strlen(src)) {}
    explicit MyString(int size) : capacity_(size)
    {
        if (DEFAULT_SIZE >= size)
        {
            size = DEFAULT_SIZE;
        }
        str_ = new char[size];
    }
    MyString(const char *src, int len) : MyString(len)
    {
        strcpy(str_, src);
    }
    MyString(MyString &string)
    {
        if (this != &string)
        {
            MyString temp(string.str_);
            std::swap(this->str_, temp.str_);
        }
    }
    MyString(MyString &&string)
    {
        if (this != &string)
        {
            this->capacity_ = string.capacity_;
            this->DEFAULT_SIZE = string.DEFAULT_SIZE;
            this->str_ = string.str_;
            string.str_ = nullptr;
        }
    }
    ~MyString();

    size_t find() const;
    size_t rfind() const;
    size_t find_not_of() const;
    size_t find_last_not_of() const;

    MyString &Insert(size_t pos, char *c);
    MyString &Insert(size_t pos, size_t len, char c);

    void PopBack();
    void PushBack(char c);

    void Clear();
    MyString Append(const char *s);

    MyString SubStr(size_t pos = 0UL, size_t len = 18446744073709551615UL);

    size_t Length()
    {
        return strlen(str_);
    }

private:
    char *str_;
    int DEFAULT_SIZE = 15;
    int capacity_;
};

MyString::MyString(/* args */)
{
}

MyString::~MyString()
{
}

#endif