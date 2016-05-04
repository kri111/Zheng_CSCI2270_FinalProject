#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <iostream>

using namespace std;

class Word
{
public:
    void set(string e, string c, string wc);
    int compare(string);
    string getChinese();
    string getWord_class();
private:
    string english;
    string chinese;
    string word_class;
};

class Dictionary
{
    public:
        Dictionary();
        //Dictionary();
        void searchWord(std::string k);
        ~Dictionary();
    protected:
    private:
        int BinSeareh(int low, int high, std::string k);
        int wordsNum;
        Word words[30]; //the size of word
};

#endif // DICTIONARY_H
