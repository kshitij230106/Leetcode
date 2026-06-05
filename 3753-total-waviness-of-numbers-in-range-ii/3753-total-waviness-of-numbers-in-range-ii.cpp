class Solution {
public:
    long long dp[20][11][11][2][2];
    long long cnt[20][11][11][2][2];
    string s;

    pair<long long,long long> dfs(int pos, int prev2, int prev1,
                                  bool started, bool tight) {
        if (pos == s.size()) {
            return {0, started ? 1 : 0};
        }

        if (!tight && dp[pos][prev2][prev1][started][0] != -1) {
            return {
                dp[pos][prev2][prev1][started][0],
                cnt[pos][prev2][prev1][started][0]
            };
        }

        int limit = tight ? s[pos] - '0' : 9;

        long long totalWave = 0;
        long long totalCnt = 0;

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (!started && d == 0) {
                auto [w, c] = dfs(pos + 1, 10, 10, false, ntight);
                totalWave += w;
                totalCnt += c;
                continue;
            }

            if (!started) {
                auto [w, c] = dfs(pos + 1, 10, d, true, ntight);
                totalWave += w;
                totalCnt += c;
                continue;
            }

            int add = 0;

            if (prev2 != 10) {
                if ((prev1 > prev2 && prev1 > d) ||
                    (prev1 < prev2 && prev1 < d))
                    add = 1;
            }

            auto [w, c] = dfs(pos + 1, prev1, d, true, ntight);

            totalWave += w + 1LL * add * c;
            totalCnt += c;
        }

        if (!tight) {
            dp[pos][prev2][prev1][started][0] = totalWave;
            cnt[pos][prev2][prev1][started][0] = totalCnt;
        }

        return {totalWave, totalCnt};
    }

    long long solve(long long x) {
        if (x <= 0) return 0;

        s = to_string(x);

        memset(dp, -1, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));

        return dfs(0, 10, 10, false, true).first;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};