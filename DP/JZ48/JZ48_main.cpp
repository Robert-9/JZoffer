/*
    描述
        请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
*/

#include <algorithm>
#include <string>
#include <unordered_map>
#include <iterator>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        if(s.size() == 1) return 1;

        unordered_map<char, int> hash;
        int left=0, right = 0;
        int result = 0;

        for(int right=0; right<s.size(); right++){
            if(hash.count(s[right])){  // 在哈希表中已有，则更新left。但已有的元素不一定在left的后面，所以要取二者的大值
                left = max(hash[s[right]]+1, left);
            //     hash[s[right]] = right;
            // }
            // else{ 
            //     hash.insert({s[right], right});
            }
            hash[s[right]] = right;
            if(result < right-left+1){
                result = right - left+1;
            }
        }
        return result;
        
    }
};