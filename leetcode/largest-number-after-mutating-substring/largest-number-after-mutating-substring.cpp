class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool flag = false;
        
        for(int i = 0; i < num.length(); ++i) {
            int digit = num[i] -'0';
            if(digit < change[digit]) {
                num[i] = char('0' + change[digit]);
                flag = true;
            } else if(digit == change[digit]) continue;
            else if (flag) break;
        }
        
        return num;
    }
};