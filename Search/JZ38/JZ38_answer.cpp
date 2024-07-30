#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> permute(string s) {
        vector<string> result;
        permuteHelper(s, 0, result);
        return result;
    }

private:
    void permuteHelper(string& s, int start, vector<string>& result) {
        /*
            辅助递归函数，用于生成从指定位置 start 开始的所有排列。
        */
        if (start == s.size()) {
            result.push_back(s);
            return;
        }
        
        for (int i = start; i < s.size(); i++) {
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
