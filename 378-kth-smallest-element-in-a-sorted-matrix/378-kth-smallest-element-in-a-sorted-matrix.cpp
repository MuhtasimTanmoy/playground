class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> que;
        for(auto col: matrix)
            for(auto item: col) {
                que.push(item);
                if (que.size() > k) que.pop();
            }
        return que.top();
    }
};