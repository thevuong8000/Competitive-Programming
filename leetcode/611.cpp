// source: https://leetcode.com/problems/valid-triangle-number
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = nums.size() - 1; i >= 2; i--){
            int l = 0, r = i -1;
            while(l < r){
                while(l < r && nums[l] + nums[r] <= nums[i]) l++;
                res += r - l;
                r--;
            }
        }
        return res;
    }
};
