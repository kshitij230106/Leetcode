class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> pre(n + 1, 0);
        
        pre[1] = 1;
        
        for (int i = 1; i < n; i++) {
            int l = max(0, i - maxJump);
            int r = i - minJump;
            
            if (r >= 0 && s[i] == '0') {
                int reachable = pre[r + 1] - pre[l];
                
                if (reachable > 0)
                    pre[i + 1] = pre[i] + 1;
                else
                    pre[i + 1] = pre[i];
            } else {
                pre[i + 1] = pre[i];
            }
        }
        
        return pre[n] > pre[n - 1];
    }
};