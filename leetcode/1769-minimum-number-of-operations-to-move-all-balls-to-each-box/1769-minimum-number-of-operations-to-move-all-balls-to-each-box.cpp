class Solution {
public:
    vector<int> minOperations(string boxes) {
        int len = boxes.size();
        vector<int> res(len, 0);
        
        for (int i = 0, pre_ops = 0, pre_cnt = 0, post_ops = 0, post_cnt = 0; i < boxes.length(); ++i) {
            res[i] += pre_ops;
            pre_cnt += boxes[i] == '1';
            pre_ops += pre_cnt;
            
            res[len - i - 1] += post_ops;
            post_cnt += boxes[len - i - 1] == '1';
            post_ops += post_cnt;
        }
        return res;
    }
};