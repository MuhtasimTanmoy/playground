class Solution {
public:
    bool isValidSerialization(string preorder) {
        int degree = 1;
        stringstream ss(preorder);
        for (string temp; getline(ss, temp, ',');) {
            degree--;
            if (degree < 0) return false;
            if (temp.back() != '#') degree += 2;
        }
        return degree == 0;
    }
};