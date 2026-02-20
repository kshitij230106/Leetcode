class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;
        int count = 0, start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') count++;
            else count--;
            if (count == 0) {
                // Recursively process the inside
                string inner = s.substr(start + 1, i - start - 1);
                string processed = "1" + makeLargestSpecial(inner) + "0";
                parts.push_back(processed);
                start = i + 1;
            }
        }
        sort(parts.begin(), parts.end(), greater<string>());
        string result;
        for (auto &p : parts)
            result += p;
        return result;
    }
};