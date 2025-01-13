// 给定一个只由左右原括号、花括号和方括号组成的字符串，求这个字符串是否合法。合法的
// 定义是每一个类型的左括号都有一个右括号一一对应，且括号内的字符串也满足此要求。
#include "include/head.h"

class Solution {
   public:
    bool isValid(std::string s) {
        std::stack<char> parsed;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
                parsed.push(s[i]);
            } else {
                    if (parsed.empty()) {
                        return false;
                    }
                char c = parsed.top();
            if ((s[i] == '}' && c == '{') ||
                (s[i] == ']' && c == '[') ||
                (s[i] == ')' && c == '(')) {
                    parsed.pop();
                    } else {
                    return false;
                 }
             }
        }
        return parsed.empty();
    }
 };