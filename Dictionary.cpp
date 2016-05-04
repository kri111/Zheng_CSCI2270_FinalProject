#include "Dictionary.h"
#include <fstream>
#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

Dictionary::~Dictionary()
{
    //dtor
}

Dictionary::Dictionary()
{
    string e,c,wc;
    wordsNum=0;
    //read the file
    ifstream infile("dictionary.txt",ios::in);  //open the file
    if(!infile)       //test if it success
    {
        cerr<<"dictionary open error!"<<endl;
        exit(1);
    }
    while (!infile.eof())
    {
        infile>>e>>c>>wc;
        words[wordsNum].set(e, c, wc);
        ++wordsNum;
    }
    infile.close();
}

int Dictionary::BinSeareh(int low, int high, string key)
{
    int mid;
    while(low<=high)
    {
        mid=(low + high) / 2;
        if(words[mid].compare(key)==0)
        {
            return mid; //search successfully and return
        }
        if(words[mid].compare(key)>0)
            high=mid-1; //search in w[low..mid-1]
        else
            low=mid+1; //search in w[mid+1..high]
    }
    return -1; //when low>high, it means that there's null,fail in searching
}

void Dictionary::searchWord(string key)
{
    int low=0,high=wordsNum-1;  //
    int index=BinSeareh(low, high, key);
    if(index>=0){
        //cout<<key<<"--->"<<words[index].getWord_class()+"\t"<<words[index].getChinese() << endl;
        cout<<key<<"--->"<<words[index].getChinese()+"\t"<<words[index].getWord_class();
    }
    else
        cout<<"None result";
    cout<<endl<<endl;
}

void Word::set(string e, string c, string wc)
{
    english=e;
    chinese=c;
    word_class=wc;
}

int Word::compare(string k)
{
    return english.compare(k);
}

string Word::getChinese()
{
    return chinese;
}

string Word::getWord_class()
{
    return word_class;
}
