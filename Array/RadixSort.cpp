// source: https://leetcode.com/problems/maximum-gap/
class Solution {
public:
    void countSort(vector<int>& nums, int exp){
        vector<vector<int>> cnt(10, vector<int>());
        for(int i = 0; i < nums.size(); i++){
            int digit = (nums[i] / exp) % 10;
            cnt[digit].push_back(nums[i]);
        }
        nums.clear();
        for(int i = 0; i < 10; i++){
            for(int x: cnt[i]) nums.push_back(x);
        }
    }
    
    void radixSort(vector<int>& nums){
        int max_elem = *max_element(nums.begin(), nums.end());
        for(int exp = 1; exp <= max_elem; exp *= 10){
            countSort(nums, exp);
        }
    }
    
    int maximumGap(vector<int>& nums) {
        int res = 0;
        for(int i = 1; i < nums.size(); i++){
            res = max(res, nums[i] - nums[i - 1]);
        }
        return res;
    }
};
