class Solution {
public:
    string reformatNumber(string number) {
        int index = 0;
        for (int i = 0; i < size(number); i++) {
            if (number[i] == ' ' || number[i] == '-') continue;
            number[index++] = number[i];
        }
        number.resize(index);
        
        string res = "";
        for (int i = 0; i < size(number); i++) {
            if (i != 0 && i % 3 == 0) res += "-";
            res += number[i];
        }
        if (res[size(res) - 2] == '-') swap(res[size(res) - 2], res[size(res) - 3]);
        return res;
    }
};