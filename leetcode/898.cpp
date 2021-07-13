// source: https://leetcode.com/problems/bitwise-ors-of-subarrays/
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        vector<int> res;
        int left = 0, right;
        for(int i = 0; i < arr.size(); i++){
            res.push_back(arr[i]);

            int right = res.size() - 1;
            // res[left : right] is the all the OR sum with a[i] as last elem
            // Property: res[left : right] is sorted
            // right - left <= 32 (32 bit)
            for(int j = left; j < right; j++){
                if((res[j] | arr[i]) == res.back()) continue;
                res.push_back(res[j] | arr[i]);
            }
            left = right;
        }
        return unordered_set(res.begin(), res.end()).size();
    }
};
