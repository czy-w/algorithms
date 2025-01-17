// String to Integer (atoi)
// Converts a string to a 32-bit signed integer
// Time complexity: O(n) where n is the length of the string
// Space complexity: O(1)
// Steps:
// 1. Skip leading whitespace
// 2. Check for sign (+ or -)
// 3. Convert digits and handle overflow
// 4. Return result within INT_MIN/INT_MAX bounds

#include "include/head.h"

// The myAtoi function takes a string and returns a 32-bit integer following these steps:
// Skip leading whitespace
// Handle optional sign (+ or -)
// Convert digits and check for overflow
// Return result within INT_MIN/INT_MAX bounds
// Key features:
// Uses long to handle potential overflow before clamping to INT_MIN/INT_MAX
// Properly handles all edge cases:
// Leading whitespace
// Optional +/- sign
// Invalid input (returns 0)
// Overflow conditions
// Time complexity: O(n) where n is string length
// Space complexity: O(1)


class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        int n = s.length();
        
        // Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Check if we've reached the end
        if (i >= n) return 0;
        
        // Handle sign
        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '+') ? 1 : -1;
            i++;
        }
        
        // Convert digits
        long result = 0;  // Using long to handle overflow
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            // Check for overflow
            if (sign == 1 && result > INT_MAX) return INT_MAX;
            if (sign == -1 && -result < INT_MIN) return INT_MIN;
            
            i++;
        }
        
        return sign * result;
    }
};

int main() {
    Solution solution;
    std::string input = "   -42";
    
    int result = solution.myAtoi(input);
    std::cout << "String '" << input << "' converted to: " << result << std::endl;
    
    return 0;
}