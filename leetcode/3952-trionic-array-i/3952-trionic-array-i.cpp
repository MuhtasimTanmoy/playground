class Solution {
public:
    bool isTrionic(vector<int>& N) {
        vector<bool> pattern;
        bool is_increasing = true;

        if (N[0] < N[1]) pattern.push_back(is_increasing);
        else return false;

        for (auto i = 1; i < N.size(); i++) 
            if (N[i-1] < N[i]) {
                if (!is_increasing) 
                    is_increasing = true,
                    pattern.push_back(is_increasing);
            } else if (N[i-1] > N[i]) {
                if (is_increasing) 
                    is_increasing = false,
                    pattern.push_back(is_increasing);
            } else return false;
        
        return pattern.size() == 3 
            && pattern[0] == true 
            && pattern[1] == false 
            && pattern[2] == true;
    }
};