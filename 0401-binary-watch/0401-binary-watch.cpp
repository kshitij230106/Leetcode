class Solution {
public:
    int countOnes(int x) {
        int cnt = 0;
        while (x) {
            cnt += x & 1;
            x >>= 1;
        }
        return cnt;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (countOnes(h) + countOnes(m) == turnedOn) {
                    string time = to_string(h) + ":";
                    if (m < 10) time += "0";
                    time += to_string(m);
                    ans.push_back(time);
                }
            }
        }
        return ans;
    }
};
