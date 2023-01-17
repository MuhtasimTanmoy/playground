class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int ans = citations.size();
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= ans) 
                if (i) { if (citations[i-1] <= ans) return ans; }
                else return ans;
            ans--;
        }
        return ans;
    }
};