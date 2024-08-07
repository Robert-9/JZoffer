#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    static bool compare(int num1, int num2) {
        string str1 = to_string(num1) + to_string(num2);
        string str2 = to_string(num2) + to_string(num1);
        return str1 < str2;
    }

public:
    string PrintMinNumber(vector<int>& numbers) {
        if (numbers.empty()) return "";

        sort(numbers.begin(), numbers.end(), compare);

        string resultStr;
        for (int num : numbers) {
            resultStr += to_string(num);
        }

        // 防止出现类似 "000" 的情况，将其简化为 "0"
        if (resultStr[0] == '0') return "0";

        return resultStr;
    }
};
