class Solution {
public:
    
    string addStrings(string a, string b) {
        string result = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        
        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            
            result.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
    
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        
        string result = "0";
        int zeros = 0;
        
        for(int i = num2.size() - 1; i >= 0; i--) {
            int carry = 0;
            string temp = "";
            
            for(int k = 0; k < zeros; k++)
                temp.push_back('0');
            
            int digit2 = num2[i] - '0';
            
            for(int j = num1.size() - 1; j >= 0; j--) {
                int digit1 = num1[j] - '0';
                int prod = digit1 * digit2 + carry;
                
                temp.push_back((prod % 10) + '0');
                carry = prod / 10;
            }
            
            if(carry)
                temp.push_back(carry + '0');
            
            reverse(temp.begin(), temp.end());
            result = addStrings(result, temp);
            zeros++;
        }
        
        return result;
    }
};