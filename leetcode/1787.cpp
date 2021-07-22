// source: https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> cnt[k + 1];
        for(int i = 0; i < nums.size(); i++){
            cnt[i % k][nums[i]]++;
        }
        vector<vector<int>> dp(k, vector<int>(1 << 10, 0));
      
        // Case 1: change all numbers in pos {i} - using pre_min
        // Case 2: remain 1 of the value
        int pre_min = 0;
        for(int i = 0; i < k; i++){
            if(i > 0){
                pre_min = *min_element(dp[i - 1].begin(), dp[i - 1].end());
            }
            int pos = n / k;
            if(n % k > i) pos++;
            for(int j = 0; j < (1 << 10); j++){
                dp[i][j] = pre_min + pos;
                for(auto& [k, v] : cnt[i]){
                    if(i == 0) dp[i][k] = min(dp[i][k], pos - v);
                    else dp[i][j] = min(dp[i][j], dp[i - 1][j ^ k] + pos - v);
                }
            }
        }
        return dp[k - 1][0];
    }
};
