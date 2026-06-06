class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
        }
        vector<int> ans(n);
        int left = 0;
        for (int i = 0; i < n; i++) {
            total -= nums[i]; 
            if (left > total)
                ans[i] = left - total;
            else
                ans[i] = total - left;
            left += nums[i];
        }
        return ans;
    }
};