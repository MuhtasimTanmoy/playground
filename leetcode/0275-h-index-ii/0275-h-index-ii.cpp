class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = citations.size();
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= ans) return ans;
            ans--;
        }
        return ans; 
    }
};