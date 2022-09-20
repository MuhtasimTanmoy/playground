class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        if (size(s) <= k) return false;
            
        unordered_set<string> bag;
        
        int totalCombination = 1;
        int itr = k;
        while (itr--) totalCombination *= 2;
        
        for (int i = 0; i <= size(s) - k; i++) {
            auto subStr = s.substr(i, k);
            // cout<<subStr<<endl;
            if (!bag.count(subStr)) bag.insert(subStr);
        }
        cout<< size(bag) << endl;
        cout<< totalCombination;
        return size(bag) == totalCombination;
    }
};