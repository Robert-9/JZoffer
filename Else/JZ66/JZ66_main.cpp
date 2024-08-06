/*
描述
    给定一个数组 A[0,1,...,n-1] ,请构建一个数组 B[0,1,...,n-1] ,
    其中 B 的元素 B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]（除 A[i] 以外的全部元素的的乘积）。程序中不能使用除法。
*/


#include <vector>
#include <iostream>
using namespace std;
class Solution {
  public:
    vector<int> multiply(vector<int>& A) {
        if (A.empty()) return A;

        int n = A.size();
        int temp = 1;
        vector<int> B(n);
        B[0] = 1;
        for (int i = 1; i < n; i++) {
            B[i] = B[i - 1] * A[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            temp *= A[i + 1];
            B[i] *= temp;
        }
        return B;
    }
};