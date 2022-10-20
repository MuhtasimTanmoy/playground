class Solution {
public:
    string intToRoman(int num) {
        vector<string> romanWord = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        vector<int> value = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        int i = romanWord.size() - 1;
        string sol = "";
        while (num > 0) {
            while (value[i] <= num) {
                sol += romanWord[i];
                num -= value[i];
            }
            i--;
        }
        return sol;
    }
};