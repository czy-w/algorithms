// 输入两个字符串，输出一个布尔值，表示两个字符串是否满足条件。

#include "include/head.h"

class Solution {
   public:
    bool isIsomorphic(std::string s, std::string t) {
        std::vector<int> s_first_index(256, 0), t_first_index(256, 0);
        for (int i = 0; i < s.length(); ++i) {
            if (s_first_index[s[i]] != t_first_index[t[i]]) {
                return false;
            }
            s_first_index[s[i]] = t_first_index[t[i]] = i + 1;
        }
        return true;
    }
};

int main(){
    
}