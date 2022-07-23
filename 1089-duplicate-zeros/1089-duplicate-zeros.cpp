class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        queue<int> pending;
        for(int i = 0; i < size(arr); i++) {
           if (!pending.empty()) {
                auto toReplace = pending.front();
                pending.pop();
                pending.push(arr[i]);
                if (!arr[i])  pending.push(arr[i]);
                arr[i] = toReplace;
            } else if (!arr[i])  pending.push(arr[i]);
        }
    }
};