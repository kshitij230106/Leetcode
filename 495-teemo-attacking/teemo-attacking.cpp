class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        if(n==0) return 0;
        int ans = 0;
        for(int i=1;i<n;i++){
            ans += min(duration, timeSeries[i]-timeSeries[i-1]);
        }
        ans += duration;

        return ans;
    }
};