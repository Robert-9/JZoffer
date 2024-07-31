#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

	class Solution {
	  public:
	    vector<string> Permutation(string s) {
	        vector<string> result;
	        if(s.size()<=1){
	            result.push_back(s);
	            return result;
	        }
	        sort(s.begin(), s.end());
	        permuteHelper(s, 0, result);
	        return result;
	    }
	
	  private:
	    void permuteHelper(string& s, int start, vector<string>& result) {
	        /*
	  @breief: 在每个递归层级上，通过交换字符来生成s的所有排列，并在达到末尾时将生成的排列添加到结果列表中。
	  @param:
	         s: 当前处理的字符串（随递归进行，其字符会被交换）。
	         start: 当前递归开始处理的字符串位置。
	         result: 存储所有排列的结果列表。
	       */
	        if (start == s.size()) {
	            result.push_back(s);
	            return;
	        }
	        unordered_set<char> seen;
	        for (int i = start; i < s.size(); i++) {
	            if (seen.find(s[i]) != seen.end()) continue; // 跳过重复字符
	            seen.insert(s[i]); 
	
	            swap(s[start], s[i]);             // 交换当前元素与后续元素
	            permuteHelper(s, start + 1, result); // 递归处理子问题
	            swap(s[start], s[i]);             // 撤销交换
	        }
	    }
	};



int main() {
    Solution sol;
    string s = "ABC";
    vector<string> permutations = sol.permute(s);
    for (const auto& p : permutations) {
        cout << p << endl;
    }
    return 0;
}
