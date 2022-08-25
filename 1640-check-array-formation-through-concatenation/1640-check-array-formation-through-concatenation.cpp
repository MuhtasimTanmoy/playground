class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n = arr.size();
        unordered_map<int, vector<int>> mapping;
        // initialize hashmap
        for (auto p: pieces)
            mapping[p[0]] = p;

        int i = 0;
        while (i < n) {
            if (!mapping.count(arr[i])) 
                return false;
            auto targetPiece = mapping[arr[i]];
            for (int x : targetPiece) {
                if (x != arr[i]) 
                    return false;
                i++;
            }
        }
        return true;
    }
};