// Gets TLE
/*
class Solution {
public:
    int fourSumCount(vector<int>& one, 
                     vector<int>& two, 
                     vector<int>& three, 
                     vector<int>& four, int res = 0) {
        for (auto a: one)
            for (auto b: two)
                for (auto c: three)
                    for (auto d: four)
                        res += (a + b + c + d == 0);
        return res;                    
    }
};
*/

class Solution {
public:
    int fourSumCount(vector<int>& one, 
                     vector<int>& two, 
                     vector<int>& three, 
                     vector<int>& four, int res = 0) {
        unordered_map<int,int> mp;
        for (auto a: one)
            for (auto b: two)
                mp[a + b]++;
        for (auto c: three)
            for (auto d: four)
               if (mp.count(0 - c - d)) res += mp[0 - c - d];
        return res;               
    }
};