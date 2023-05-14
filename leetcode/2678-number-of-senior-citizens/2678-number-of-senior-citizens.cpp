class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for (auto d: details) {
            d.pop_back();
            d.pop_back();
            
            int age = d.back() - '0'; d.pop_back();
            age = (d.back() - '0') * 10 + age;
            
            if (age > 60) res++;
        }
        return res;
    }
};