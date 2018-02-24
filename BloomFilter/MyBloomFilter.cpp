/*
Waqar Haider U10664814
Collaborator: Matt Hormis
Source
http://blog.michaelschmatz.com/2016/04/11/how-to-write-a-bloom-filter-cpp/
https://llimllib.github.io/BloomFilter-tutorial/
https://prakhar.me/articles/bloom-filters-for-dummies/
https://stackoverflow.com/questions/26331628/reference-to-non-static-member-function-must-be-called
http://www.geeksforgeeks.org/bloom-filters-introduction-and-python-implementation/
*/

#include <iostream>
#include <math.h>
#include "MyBloomFilter.h"
using namespace std;


MyBloomFilter :: MyBloomFilter(int len){
    length=len; 
    for (int i = 0 ; i<len ; i++) bloomfiltBits.push_back(false);
}

int MyBloomFilter :: hashOne(string item){

    int x = item.length();
    int var = 0;

    for (int i = 0; i < x; i++){
        string temp = item.substr(i,1);//Returns a newly constructed string object with its value initialized to a copy of a substring of this object.
        const char *charToString = temp.c_str();//Returns a pointer to an array that contains a null-terminated sequence of characters
        int tempi = *charToString;
        var += tempi;
    }

    var = ceil(var/x);
    int modulo = var % 53;
    return modulo;
}

int MyBloomFilter :: hashTwo(string item){
    
    int x = item.length();
    int var = 0;
    for (int i = 0; i < x; i++){
        
        string temp = item.substr(i,1);
        const char *charToString = temp.c_str();
        int tempi = *charToString;
        var += tempi*3;
    }
    var = ceil(var/(x*2));
    int modulo = var % 97;
    return modulo;
}

void MyBloomFilter :: insert(string item){
    int one = hashOne(item);
    int two = hashTwo(item);

    bloomfiltBits[one] = true;
    bloomfiltBits[two] = true;

} 

bool MyBloomFilter :: exists(string item){
    int one = hashOne(item);
    int two = hashTwo(item);
    if (bloomfiltBits[one] == true && bloomfiltBits[two] == true) return true;
    else return false;
}

string MyBloomFilter::output(){
  
    return "0000000000";

}