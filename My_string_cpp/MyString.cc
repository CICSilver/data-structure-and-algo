#include "MyString.h"

std::ostream &operator<<(std::ostream &os, const MyString &str)
{
    return std::__ostream_insert(os, str.Data(), str.Size());
}

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

MyString& MyString::Append(const char *s)
{
    size_t s_len = strlen(s);
    EnsureGrow(s_len + Capacity());
    memcpy(this->str_ + Size(), s, s_len);

    return *this;
}

MyString& MyString::Append(const char s)
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

MyString &MyString::Insert(size_t pos, const char *c)
{
    CheckPosValid(pos);
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