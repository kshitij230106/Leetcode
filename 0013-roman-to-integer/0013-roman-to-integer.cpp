class Solution {
public:
    int val(char c){
        if(c=='I') return 1;
        if(c=='V') return 5;
        if(c=='X') return 10;
        if(c=='L') return 50;
        if(c=='C') return 100;
        if(c=='D') return 500;
        return 1000;

    }
    int romanToInt(string s) {
        int sum = 0;
        for(int i=0;i<s.size();i++){
            if(i+1<s.size() && val(s[i])<val(s[i+1]))
                sum -= val(s[i]);
            else 
                sum += val(s[i]);
        }
        return sum;
    }
};