#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string charToWord[256];
        string words[300];
        int wordCount = 0;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words[wordCount++] = word;
        }
        if (wordCount != pattern.size())
            return false;
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];
            if (charToWord[c] == "") {
                for (int j = 0; j < 256; j++) {
                    if (charToWord[j] == w)
                        return false;
                }
                charToWord[c] = w;
            } else {
                if (charToWord[c] != w)
                    return false;
            }
        }
        return true;
    }
};