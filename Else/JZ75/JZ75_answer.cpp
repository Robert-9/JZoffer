#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
private:
    unordered_map<char, int> hash;
    queue<char> onceQueue;

public:
    // Insert one char from stringstream
    void Insert(char ch) {
        hash[ch]++;
        if (hash[ch] == 1) {
            onceQueue.push(ch);
        }
        // 检查队列头部字符是否仍然只出现一次
        while (!onceQueue.empty() && hash[onceQueue.front()] > 1) {
            onceQueue.pop();
        }
    }

    // Return the first appearance once char in current stringstream
    char FirstAppearingOnce() {
        if (onceQueue.empty()) {
            return '#';
        } else {
            return onceQueue.front();
        }
    }
};
