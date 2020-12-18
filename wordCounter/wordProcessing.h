#ifndef _WORDPROCESSING_H
#define _WORDPROCESSING_H
#include <map>
#include <string>
#include <fstream>
#include <tuple>
#include "Buffer.h"

// 单词操作
class WordProcessing
{
public:
    typedef std::vector<std::string> WordList;
    typedef std::map<std::string, int> WordCounts;

    WordProcessing() = default;

    WordProcessing(Buffer *buffer)
        : buffer_(buffer)
    {
        auto buf = buffer_->GetWords();
        for (auto const &word : buf)
        {
            wordCounts_[word]++;
        }
    };
    ~WordProcessing(){};

    void printAsLines()
    {
        buffer_->printBuffer(buffer_->GetLines());
    }

    void printAsWords()
    {
        buffer_->printBuffer(buffer_->GetWords());
    }

    //获取出现频率最高的单词
    std::tuple<std::string, int> GetWordOfHighestFrequency()
    {
        return GetWordOfLOHFrequency(true);
    }

    //获取出现频率最低的单词
    std::tuple<std::string, int> GetWordOfLowestFrequency()
    {
        return GetWordOfLOHFrequency(false);
    }

    //查看所有词的出现频率
    void printWordCountsAll();

private:
    WordCounts wordCounts_;
    Buffer *buffer_;

    std::tuple<std::string, int> GetWordOfLOHFrequency(bool isGetHigh);
};

std::tuple<std::string, int> WordProcessing::GetWordOfLOHFrequency(bool isGetHigh)
{
    std::string temp = "";
    int i_temp = 0;
    auto func = isGetHigh ? [](int a, int b) {
        return a < b;
    }
                          : [](int a, int b) {
                                return a >= b;
                            };
    for (auto &p : wordCounts_)
    {
        if (func(i_temp, p.second) || i_temp == 0)
        {
            i_temp = p.second;
            temp = p.first;
        }
    }
    return std::make_tuple(temp, i_temp);
}

void WordProcessing::printWordCountsAll()
{
    for (auto const &p : wordCounts_)
    {
        printf("word: %15s , frequency: %d\n", p.first.c_str(), p.second);
    }
}

#endif