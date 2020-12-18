#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "fileProcessing.h"
#include "wordProcessing.h"

using namespace std;

int main()
{
    FileProcessing fProcess("words.txt");

    // auto [L_word, L_counts] = fProcess.GetWordOfLowestFrequency();

    // printf("lowest frequency word is \"%s\" with frequency: %d\n",
    //        L_word.c_str(), L_counts);

    auto [H_word, H_counts] = fProcess.GetWordOfHighestFrequency();

    printf("highest frequency word is \"%s\" with frequency: %d\n",
           H_word.c_str(), H_counts);

    // printf("============================================================\n");

    // fProcess.printWordWithFrequency();
}