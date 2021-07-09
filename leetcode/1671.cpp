// source: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        /**
        * Find Longest-Increasing-Subsequence in both direction at all specific position.
        * => stored into {left} and {right}
        */
        vector<int> lst;
        vector<int> left, right;
        for(int i = 0; i < nums.size(); i++){
            int index = lower_bound(lst.begin(), lst.end(), nums[i]) - lst.begin();
            if(index == lst.size()) lst.push_back(nums[i]);
            else lst[index] = nums[i];
            left.push_back(index);
        }
        
        lst.clear();
        for(int i = nums.size() - 1; i >= 0; i--){
            int index = lower_bound(lst.begin(), lst.end(), nums[i]) - lst.begin();
            if(index == lst.size()) lst.push_back(nums[i]);
            else lst[index] = nums[i];
            right.push_back(index);
        }
        reverse(right.begin(), right.end());
        
        int res = 3;
        for(int i = 1; i < nums.size() - 1; i++){
            if(left[i] < 1 || right[i] < 1) continue;
            res = max(res, left[i] + right[i] + 1);
        }
        return (int)nums.size() - res;
    }
};
