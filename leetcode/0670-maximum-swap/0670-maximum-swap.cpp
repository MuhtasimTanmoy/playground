class Solution {
public:
    int maximumSwap(int num) {
        auto num_str = to_string(num);
        pair<int, int> keep;
        for (int i = num_str.size() - 1, max_so_far = -1, m_index = -1; i >= 0; i--) {
            auto now = num_str[i] - '0';
            if (max_so_far < now)
                max_so_far = now, m_index = i;
            else if (now < max_so_far)
                    keep = {m_index, i};
        }
        swap(num_str[keep.first], num_str[keep.second]);
        return stoi(num_str);
    }
};