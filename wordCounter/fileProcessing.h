#ifndef _ReadFile_H
#define _ReadFile_H
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "wordProcessing.h"
#include "Buffer.h"
#include <tuple>

class FileProcessing
{
public:
    FileProcessing(std::string inFileName,
                   std::string outFileName = "result.txt")
    : in_(std::ifstream(inFileName)),
    out_(std::ofstream(outFileName)),
    wordProcessing_(new Buffer(inFileName))
    {
        
    };

    std::tuple<std::string, int> GetWordOfHighestFrequency()
    {
        return wordProcessing_.GetWordOfHighestFrequency();
    }

    std::tuple<std::string, int> GetWordOfLowestFrequency()
    {
        return wordProcessing_.GetWordOfLowestFrequency();
    }

    // 按行打印
    void printAsLines()
    {
        return wordProcessing_.printAsLines();
    }

    // 按单词打印
    void printAsWords()
    {
        return wordProcessing_.printAsWords();
    }

    void printWordWithFrequency()
    {
        wordProcessing_.printWordCountsAll();
    }
    ~FileProcessing(){};

private:
    std::ifstream in_;
    std::ofstream out_;
    WordProcessing wordProcessing_;
};

#endif