class Solution {
public:
    int minCost(string colors, vector<int>& need) {        
        int total = 0;
        for (int i = 1; i < colors.size(); i++) 
            if (colors[i - 1] == colors[i]) {
                auto min_of_two = min(need[i - 1], need[i]),
                     max_of_two = max(need[i - 1], need[i]);
                total += min_of_two;
                need[i] = max_of_two;
            }
        return total;
    }
};