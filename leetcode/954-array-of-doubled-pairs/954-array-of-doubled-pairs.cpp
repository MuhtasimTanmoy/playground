class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        if (arr.size() % 2) return false;
        sort(arr.begin(), arr.end(), [&](int& a, int& b) {
            if (a < 0 && b < 0) return a > b;
            else return a < b;
        });
        unordered_map<int, int> freq;
        for (int num : arr) freq[num]++;
        for (int num : arr)
            if (freq[num]) {
				freq[num]--;
                int twiceNum = num * 2;
                if (freq[twiceNum] > 0) freq[twiceNum]--;
                else return false;
            }        
        return true;
    }
};