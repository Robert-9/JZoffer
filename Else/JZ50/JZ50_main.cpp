/*
    描述
        在一个长为 字符串中找到第一个只出现一次的字符,并返回它的位置, 
        如果没有则返回 -1（需要区分大小写）.（从0开始计数）
*/

#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> hash;
        vector<char> onceChar;

        for(int index=0; index<str.size(); index++){
            hash[str[index]]++;
        }
        for(int i=0; i<str.size(); i++){
            if(hash[str[i]] == 1){
                return i;
            }
        }
        // for(int i=0; i<str.size(); i++){
        //     if(str[i] == )
        // }
        return -1;
    }
};