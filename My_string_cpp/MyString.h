#ifndef _MYSTRING_H
#define _MYSTRING_H

#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <iterator>

static const size_t DEFAULT_SIZE = 15;

// #define DEEP_COPY
// TODO 引用计数需要添加写时拷贝，若不修改字符串，则始终读取同一个字符串，只有需要改动时才会另开一个字符串;
// TODO 目前使用的是用独立变量存储引用计数，也可以将其加到字符串前，合并空间
#define REF_COUNT

#define DEBUG

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
#ifdef REF_COUNT
        refCount = 1;
#endif
    }
    MyString(const char *src, size_t len) : MyString(len)
    {
        strcpy(str_, src);
    }
// ANCHOR double free 解决方案-----深拷贝
#ifdef DEEP_COPY
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
    MyString &operator=(MyString &&src)
    {
        if (this != &src)
        {
            this->capacity_ = src.capacity_;
            this->str_ = src.str_;
            src.str_ = nullptr;
        }
        return *this;
    }
    ~MyString()
    {
        delete[] str_;
    };
#endif

// ANCHOR double free 解决方案-----引用计数
#ifdef REF_COUNT
    MyString(MyString &string)
    {
        if (this != &string)
        {
            this->str_ = string.str_;
            refCount++;
        }
    }
    MyString(MyString &&string)
    {
        if (this != &string)
        {
            this->capacity_ = string.capacity_;
            this->str_ = string.str_;
            this->refCount = string.refCount;
            string.str_ = nullptr;
        }
    }
    MyString &operator=(MyString &src)
    {
        if (this != &src)
        {
            this->str_ = src.str_;
            refCount++;
        }
        return *this;
    }
    MyString &operator=(MyString &&src)
    {
        if (this != &src)
        {
            this->capacity_ = src.capacity_;
            this->str_ = src.str_;
            this->refCount = src.refCount;
            src.str_ = nullptr;
        }
        return *this;
    }
    ~MyString()
    {
        if (refCount == 1)
        {
            delete[] str_;
        }
        else
        {
            refCount--;
        }
    };

    // * ANCHOR 写时拷贝
    MyString &CopyOnWrite(MyString &src)
    {
        MyString temp(src.str_);
        std::swap(this->str_, temp.str_);
        std::swap(this->capacity_, temp.capacity_);
        return *this;
    }
#endif

    // TODO
    MyString &operator+=(const MyString &s)
    {
        return this->Append(s.Data());
    }
    MyString &operator+=(const char *s)
    {
        return this->Append(s);
    }

    // char &std::string::operator[](std::size_t __pos)
    char &operator[](size_t pos);
    friend MyString operator+(const MyString &s1, const MyString &s2)
    {
        MyString temp(s1.Data());
        temp += s2;
        return temp;
    }

    friend MyString operator+(const MyString &s1, const char *s2)
    {
        MyString temp(s1.Data());
        temp += s2;
        return temp;
    }
    //ANCHOR 流运算符只能用友元重载
    friend std::ostream &operator<<(std::ostream &os, const MyString &str)
    {
        os << str.str_;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, MyString &str)
    {
        is >> str.str_;
        return is;
    }

    bool operator>(const MyString &s)
    {
        return isBigger(s);
    }
    bool operator<(const MyString &s)
    {
        return !isBigger(s);
    }
    bool operator==(const MyString &s)
    {
        bool ret = true;
        if (this != &s)
        {
            return (strcmp(this->str_, s.str_) == 0);
        }
        return ret;
    }
    // * ANCHOR 类型转换运算符重载，即支持static_cast<int>的转换，也支持隐式转换
    operator int()
    {
    }
    // * ANCHOR i++:MyString operrator(int n),  ++i: MyString operator(), 使用一个n占位区分
    MyString operator++() = delete;
    MyString operator++(int n) = delete;
    MyString operator-() = delete;
    MyString operator*() = delete;

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
    MyString &Append(const char *s);

    MyString &Append(const char s);

    char &At(size_t pos) const
    {
        CheckPosValid(pos);
        return this->str_[pos];
    }

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

    // std::iterator begin()
    // {

    // }

    size_t Length() const
    {
        return strlen(str_);
    }

    size_t Capacity() const
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

    size_t Length()
    {
        return strlen(str_);
    }

private:
    char *str_;
    size_t capacity_;
    const size_t npos = 18446744073709551615UL;
#ifdef REF_COUNT
    size_t refCount = 1;
#endif
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
    void CheckPosValid(size_t pos) const
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
    bool isBigger(const MyString &s)
    {
        bool ret = true;
        if (this != &s)
        {
            int diff = this->Size() - s.Size();
            if (diff != 0)
            {
                return (diff > 0);
            }
            else
            {
                if (strcmp(this->str_, s.str_) == 0)
                {
                    return false;
                }
                int size = this->Size();
                int count = 0;
                while (size--)
                {
                    if (this->At(count) - s.At(count) < 0)
                    {
                        ret = false;
                        break;
                    }
                    count++;
                }
            }
        }
        return ret;
    }
};

#endif

#ifdef DEBUG
// std::ostream &operator<<(std::ostream &os, const MyString &str)
// {
//     return std::__ostream_insert(os, str.Data(), str.Size());
// }

// std::istream &operator>>(std::istream &is, MyString &str)
// {
// }

MyString operator+(const MyString &s1, const MyString &s2);

bool MyString::CheckCapacity(size_t _size)
{
    return _size >= Capacity();
}

// 重新分配后指针地址可能改变，引用/指针不安全
char *MyString::Grow(size_t minCapacity)
{
    size_t oldCapacity = Capacity();
    size_t newCapacity = oldCapacity + (oldCapacity >> 1);
    if (minCapacity <= 1)
    {
        minCapacity = DEFAULT_SIZE;
    }
    if (newCapacity < minCapacity)
    {
        newCapacity = minCapacity;
    }

    str_ = (char *)realloc(str_, sizeof(char) * newCapacity);
    capacity_ = newCapacity;

    return str_;
}

MyString &MyString::Append(const char *s)
{
    size_t s_len = strlen(s);
    EnsureGrow(s_len + Capacity());
    memcpy(this->str_ + Size(), s, s_len);

    return *this;
}

MyString &MyString::Append(const char s)
{
    EnsureGrow(1 + Capacity());
    *(this->str_ + Size()) = s;

    return *this;
}

void MyString::Clear()
{
    capacity_ = DEFAULT_SIZE;
    memset(this->str_, 0, Size());
    this->str_ = (char *)realloc(this->str_, sizeof(char) * capacity_);
}

MyString MyString::SubStr(size_t pos, size_t len)
{
    MyString temp;
    CheckPosValid(pos);
    for (int i = 0; i < len; ++i)
    {
        temp.Append(*(this->str_ + pos + i));
    }
    return temp;
}
#ifdef DEEP_COPY
MyString &MyString::Insert(size_t pos, const char *c)
{
    CheckPosValid(pos);
    // MyString str(CopyOnWrite(this))
    size_t c_len = strlen(c);
    size_t newLen = c_len + this->Size() + 1;
    EnsureGrow(newLen);
    char s_temp[newLen] = {0};

    memcpy(s_temp, this->str_, pos);
    memcpy(s_temp + pos, c, c_len);
    memcpy(s_temp + pos + c_len, this->str_ + pos, this->Size() - pos);
    s_temp[newLen] = '\0';
    memcpy(this->str_, s_temp, newLen + 1);

    return *this;
}

MyString &MyString::Insert(size_t pos, size_t len, char c)
{
    CheckPosValid(pos);
    char s_temp[len + 1] = {0};
    for (size_t i = 0; i < len; ++i)
    {
        s_temp[i] = c;
    }
    s_temp[len] = '\0';
    return Insert(pos, s_temp);
}
#endif

#ifdef REF_COUNT

// * ANCHOR 因为发生了拷贝，可能导致调用该方法前的指针失效？
MyString &MyString::Insert(size_t pos, const char *c)
{
    CheckPosValid(pos);
    MyString temp_string(CopyOnWrite(*this));
    size_t c_len = strlen(c);
    size_t newLen = c_len + temp_string.Size() + 1;
    EnsureGrow(newLen);
    char s_temp[newLen] = {0};

    memcpy(s_temp, temp_string.str_, pos);
    memcpy(s_temp + pos, c, c_len);
    memcpy(s_temp + pos + c_len, temp_string.str_ + pos, temp_string.Size() - pos);
    s_temp[newLen] = '\0';
    memcpy(temp_string.str_, s_temp, newLen + 1);

    return temp_string;
}

MyString &MyString::Insert(size_t pos, size_t len, char c)
{
    CheckPosValid(pos);
    // MyString temp_string(CopyOnWrite(*this));
    char s_temp[len + 1] = {0};
    for (size_t i = 0; i < len; ++i)
    {
        s_temp[i] = c;
    }
    s_temp[len] = '\0';
    return Insert(pos, s_temp);
}
#endif

void MyString::PushBack(char c)
{
    this->Append(c);
}

size_t MyString::FindSubStr(const char *s, size_t spos, size_t epos) const
{
    size_t res_pos = npos;
    bool isDone = false;
    for (size_t i = spos; i < epos; ++i)
    {
        for (size_t j = 0; j < strlen(s); ++j)
        {
            if (this->str_[i + j] != s[j])
            {
                isDone = false;
                break;
            }
            isDone = true;
        }
        if (isDone)
        {
            res_pos = i;
            break;
        }
    }

    return res_pos;
}

size_t MyString::RFindSubStr(const char *s, size_t spos, size_t epos) const
{
    size_t res_pos = npos;
    bool isDone = false;
    if (spos >= Size())
    {
        spos = Size() - 1;
    }
    for (size_t i = spos - strlen(s); i >= 0; --i)
    {
        for (size_t j = 0; j < strlen(s); ++j)
        {
            if (this->str_[i + j] != s[j])
            {
                isDone = false;
                break;
            }
            isDone = true;
        }
        if (isDone)
        {
            res_pos = i;
            break;
        }
    }

    return res_pos;
}

size_t MyString::Find(const char *s, size_t pos) const
{
    return FindSubStr(s, pos);
}

size_t MyString::FindNotSubStr(const char *s, size_t spos, size_t epos) const
{
    size_t res_pos = npos;
    auto isDone = false;
    for (size_t i = spos; i < epos; ++i)
    {
        for (size_t j = 0; j < strlen(s); ++j)
        {
            if (this->str_[i] == s[j])
            {
                isDone = false;
                break;
            }
            isDone = true;
        }
        if (isDone)
        {
            res_pos = i;
            break;
        }
    }

    return res_pos;
}
size_t MyString::RFindNotSubStr(const char *s, size_t spos, size_t epos) const
{
    size_t res_pos = npos;
    bool isDone = false;

    if (spos >= Size())
    {
        spos = Size() - 1;
    }
    for (size_t i = spos; i >= epos; --i)
    {
        for (size_t j = 0; j < strlen(s); ++j)
        {
            if (this->str_[i] == s[j])
            {
                isDone = false;
                break;
            }
            isDone = true;
        }
        if (isDone)
        {
            res_pos = i;
            break;
        }
    }

    return res_pos;
}

MyString &MyString::Replace(size_t pos, size_t len, MyString &str)
{
    // TODO
}

char &MyString::operator[](size_t pos)
{
    return this->str_[pos];
}

void Clear()
{
    // TODO
}
#endif