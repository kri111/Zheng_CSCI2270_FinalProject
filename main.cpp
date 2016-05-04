#include <fstream>
#include<iostream>
#include<string>
#include<cstdlib>
#include "Dictionary.h"

using namespace std;

int main( )
{
    Dictionary dict;
    string key;

    do
    {
        cout<<"input the English word that you want to search,input quit to close:"<<endl;
        cin>>key;
        if (key!="quit")
        {
            dict.searchWord(key);
        }
    }
    while(key!="quit");
    cout<<"Bye"<<endl<<endl;
    return 0;
}

