class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                bool ok = true;
                for (int l = i, r = j; l < r; l++, r--) {
                    if (s[l] != s[r]) {
                        ok = false;
                        break;
                    }
                }

                if (ok && j - i + 1 > ans.size())
                    ans = s.substr(i, j - i + 1);
            }
        }
        return ans;
    }
};
