// 给定一个非负整数，求它的开方，向下取整。

#include "include/head.h"

// Calculate the middle point mid
// If mid² equals x, we found the exact square root
// If mid² is less than x, search in the right half
// If mid² is greater than x, search in the left half

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        
        long long left = 1;
        long long right = x;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long square = mid * mid;
            
            if (square == x) {
                return mid;
            }
            else if (square < x) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return right;
    }
};

int main() {
    Solution solution;
    int x = 4;
    int result = solution.mySqrt(x);
    std::cout << "sqrt(" << x << ") = " << result << std::endl;
    return 0;
}