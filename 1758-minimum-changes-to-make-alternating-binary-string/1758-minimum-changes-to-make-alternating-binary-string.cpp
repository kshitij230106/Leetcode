class Solution {
public:
    int minOperations(string s) {
        int flip = 0;

        for(int i = 0; i < s.length(); i++){
            if((s[i] - '0') != i % 2){
                flip++;
            }
        }

        return min(flip, (int)s.length() - flip);
    }
};