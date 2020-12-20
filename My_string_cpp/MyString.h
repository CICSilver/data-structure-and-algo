#ifndef _MYSTRING_H
#define _MYSTRING_H

#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdlib.h>

class MyString
{
public:
    MyString() : MyString(DEFAULT_SIZE) {}
    explicit MyString(const char *src) : MyString(src, strlen(src)) {}
    explicit MyString(size_t size) : capacity_(size)
    {
        if (DEFAULT_SIZE >= capacity_)
        {
            capacity_ = DEFAULT_SIZE;
        }
        str_ = new char[capacity_];
    }
    MyString(const char *src, size_t len) : MyString(len)
    {
        strcpy(str_, src);
    }

    MyString(MyString &string) : str_(nullptr), capacity_(0)
    {
        if (this != &string)
        {
            MyString temp(string.str_);
            std::swap(this->str_, temp.str_);
            std::swap(this->capacity_, temp.capacity_);
        }
    }

    MyString(MyString &&string)
    {
        if (this != &string)
        {
            this->capacity_ = string.capacity_;
            this->str_ = string.str_;
            string.str_ = nullptr;
        }
    }
    ~MyString()
    {
        delete[] str_;
    };

    MyString &operator=(MyString &src)
    {
        if (this != &src)
        {
            MyString temp(src.str_);
            std::swap(this->str_, temp.str_);
            std::swap(this->capacity_, temp.capacity_);
        }
        return *this;
    }

    // TODO
    MyString operator+=(const MyString &s);
    MyString operator+=(const char *s);

    friend std::ostream &operator<<(MyString &os, const MyString &str);

    MyString operator++() = delete;

    size_t Find(const char c, size_t pos = 0UL) const
    {
        const char *s = &c;
        return FindSubStr(s, pos);
    }
    size_t Find(const char *s, size_t pos = 0UL) const;
    size_t RFind(const char c, size_t pos = 18446744073709551615UL) const
    {
        const char *s = &c;
        return RFindSubStr(s, pos);
    }
    size_t RFind(const char *s, size_t pos = 18446744073709551615UL) const
    {
        return RFindSubStr(s, pos);
    }

    size_t Find_first_not_of(const char c, size_t pos = 0UL) const
    {
        const char *s = &c;
        return FindNotSubStr(s, pos);
    }
    size_t Find_first_not_of(const char *s, size_t pos = 0UL) const
    {
        return FindNotSubStr(s, pos);
    }

    size_t Find_last_not_of(const char c, size_t pos = 18446744073709551615UL) const
    {
        const char *s = &c;
        return RFindNotSubStr(s, pos);
    }
    size_t Find_last_not_of(const char *s, size_t pos = 18446744073709551615UL) const
    {
        return RFindNotSubStr(s, pos);
    }

    MyString &Insert(size_t pos, const char *c);
    MyString &Insert(size_t pos, size_t len, char c);

    void PopBack()
    {
        this->str_[Size() - 1] = '\0';
    }
    void PushBack(char c);

    void Clear();
    MyString Append(const char *s);

    MyString Append(const char s);

    constexpr char At(size_t pos) const;

    bool Empty()
    {
        return Size() == 0;
    }

    MyString &Replace(size_t pos, size_t len, MyString &str);

    MyString SubStr(size_t pos = 0UL, size_t len = 18446744073709551615UL);

    void Reserve(size_t newCapacity)
    {
        if (newCapacity <= Size())
        {
            std::__throw_out_of_range_fmt(__N("capacity (which is %zu) < this->Size() (which is %zu)"), newCapacity, this->Size());
        }
        this->str_ = (char *)realloc(this->str_, newCapacity);
        capacity_ = newCapacity;
    }

    size_t Length()
    {
        return strlen(str_);
    }

    size_t Capacity()
    {
        return capacity_ - 1;
    }

    const char *Data() const
    {
        return str_;
    }

    size_t Size() const
    {
        return strlen(str_);
    }

    size_t Length() const
    {
        return strlen(str_);
    }

private:
    char *str_;
    const size_t DEFAULT_SIZE = 15;
    size_t capacity_;

    const size_t npos = 18446744073709551615UL;

    void EnsureGrow(size_t _size)
    {
        auto temp = str_;
        if (CheckCapacity(_size))
        {

            temp = Grow(_size);
        }

        str_ = temp;
    }
    bool CheckCapacity(size_t _size);
    char *Grow(size_t minCapacity);
    void CheckPosValid(size_t pos)
    {
        if (pos > Size())
        {
            std::__throw_out_of_range_fmt(__N("pos (which is %zu) > this->Size() (which is %zu)"), pos, this->Size());
        }
    }
    // ANCHOR define.
    size_t FindSubStr(const char *s, size_t spos = 0UL, size_t epos = 18446744073709551615UL) const;
    size_t RFindSubStr(const char *s, size_t spos = 18446744073709551615UL, size_t epos = 0UL) const;
    size_t FindNotSubStr(const char *s, size_t spos = 0UL, size_t epos = 18446744073709551615UL) const;
    size_t RFindNotSubStr(const char *s, size_t spos = 18446744073709551615UL, size_t epos = 0UL) const;
};

#endif