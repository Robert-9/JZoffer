/*
    逐位分析：从个位开始，逐步向高位移动，每次计算当前位是1的情况。
    三部分分析：
        高位：比当前位高的数字。
        当前位：当前正在处理的数字。
        低位：比当前位低的数字。
    根据当前位的数字大小，判断当前位为1时对应的1的数量
*/
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int result = 0;
        int factor = 1;  // 从个位开始，逐步分析每一位
        int lower = 0;   // 当前位的低位
        int current = 0; // 当前分析的位
        int higher = 0;  // 当前位的高位

        while (n / factor != 0) {
            lower = n - (n / factor) * factor;
            current = (n / factor) % 10;
            higher = n / (factor * 10);

            if (current == 0) {
                result += higher * factor;
            } else if (current == 1) {
                result += higher * factor + lower + 1;
            } else {
                result += (higher + 1) * factor;
            }
            factor *= 10;
        }

        return result;
    }
};
