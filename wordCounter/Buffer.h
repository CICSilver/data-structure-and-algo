#ifndef _BUFFER_H
#define _BUFFER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Buffer
{
public:
    using Buffer_ = std::vector<std::string>;
    Buffer() {}
    Buffer(std::string fileName) : in_(new std::ifstream(fileName)){};
    ~Buffer(){};

    // 获取行，返回一个存储行的vector
    Buffer_ GetLines();
    Buffer_ GetWords();

    void printBuffer(Buffer_ buf);

private:
    std::ifstream *in_;
};

Buffer::Buffer_ Buffer::GetLines()
{
    std::string s;
    Buffer::Buffer_ res;
    while (getline(*in_, s))
    {
        res.emplace_back(s);
    }
    return res;
}

/**
 * return: vector<string>, no simbols
 */
Buffer::Buffer_ Buffer::GetWords()
{
    std::string w;
    Buffer::Buffer_ res;

    while (*in_ >> w)
    {
        std::vector<std::string::iterator> mark;
        for (auto it = w.begin(); it != w.end(); ++it)
        {
            if (!(*it >= 'a' && *it <= 'z') && !(*it >= 'A' && *it <= 'Z') && !(*it == '_'))
            {
                mark.emplace_back(it);
            }
        }
        int size = mark.size();
        for (int i = 0; i < size; ++i)
        {
            w.erase(mark.back());
            mark.pop_back();
        }
        if(w.size()<=0)
        {
            continue;
        }
        res.emplace_back(w);
    }

    return res;
}

void Buffer::printBuffer(Buffer_ buf)
{
    for (auto const &l : buf)
    {
        std::cout << l << std::endl;
    }
}

#endif