/*
    描述
        请实现一个函数用来找出字符流中第一个只出现一次的字符。
        例如，当从字符流中只读出前两个字符 "go" 时，第一个只出现一次的字符是 "g" 。当从该字符流中读出前六个字符 “google" 时，第一个只出现一次的字符是"l"。
*/

#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


class Solution{
private:
    string inputStr;
    vector<char> onceVec;
    unordered_map<char, int> hash;

public:
  //Insert one char from stringstream
    void Insert(char ch) {
         inputStr.push_back(ch);
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        char result;
        int times = ++hash[inputStr[inputStr.size()-1]];
        if( times == 1){
            onceVec.push_back(inputStr[inputStr.size()-1]);
        }
        else if(times == 2){
            for(int i=0; i<onceVec.size(); i++){
                if(onceVec[i] == inputStr[inputStr.size()-1]){
                    onceVec.erase(onceVec.begin()+i);
                    break;
                }
            }
        }
        else if(times > 2){

        }
        if(onceVec.empty()) result = '#';
        else result = onceVec.front();
        
        return result;
    }

};
