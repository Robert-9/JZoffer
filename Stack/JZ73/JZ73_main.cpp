/*
    描述：
        牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
        同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“nowcoder. a am I”。
        后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a nowcoder.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？

*/
#include <string>
#include <sstream>
#include <stack>
class Solution {
public:
    std::string ReverseSentence(std::string str) {  // 找到两个空格之间 或两侧的单词，将内容压入堆栈，然后弹出回原位
        if(str.empty()) return str;

        std::stringstream ss(str);
        std::string word;
        std::stack<std::string> stack;
        std::string resultStr;


        // while (ss >> word) {  // z这样写也可以
        //     stack.push(word);
        // }
        while(std::getline(ss, word, ' ')){
            stack.push(word);
        }

        while (!stack.empty()) {
            resultStr += stack.top();
            stack.pop();
            resultStr += ' ';
        }
        resultStr.pop_back();  // 弹出最后一个空格
        return resultStr;
    }
};