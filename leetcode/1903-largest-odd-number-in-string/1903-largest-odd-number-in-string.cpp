class Solution {
public:
    string largestOddNumber(string num) {
        int oddIndex = -1;
        for (int i = num.size() - 1; i >= 0; i--) 
            if ((num[i] - '0') & 1) {
                oddIndex = i;
                break;
            }
        num.resize(oddIndex + 1);
        return num;
    }
};