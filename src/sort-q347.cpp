//  347. Top K Frequent Elements

#include "include/head.h"



class Solution {
public:
std::vector<int> topKFrequent(std::vector<int>& nums, int k){
    std::unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;   
    std::priority_queue<std::pair<int, int>> pq;        
    for (auto it = freq.begin(); it != freq.end(); it++){
        pq.push({it->second, it->first});
        if (pq.size() > k){
            pq.pop();
        }
    }
    std::vector<int> res;
    while (k > 0){
        res.push_back(pq.top().second);
        pq.pop();
        k--;
    }
    return res;
}       
};      


int main() {
    Solution solution;
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    
    std::vector<int> result = solution.topKFrequent(nums, k);
    std::cout << "Top " << k << " frequent elements: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
