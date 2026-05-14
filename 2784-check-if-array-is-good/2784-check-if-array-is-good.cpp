class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> freq(201, 0);
        for (int x : nums) {
            freq[x]++;
        }
        if (freq[n] != 2)
            return false;
        for (int i = 1; i < n; i++) {
            if (freq[i] != 1)
                return false;
        }
        return true;
    }
};