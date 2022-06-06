class Solution {
public:
    double average(vector<int>& salary) {
        
        int minSalary = INT_MAX;
        int maxSalary = INT_MIN;
        
        int sum = 0;
        for(auto s: salary) {
            sum += s;
            maxSalary = max(s, maxSalary);
            minSalary = min(s, minSalary);
        }
        
        double s = sum - maxSalary - minSalary;
        double n = size(salary) - 2;
        return s/n;
    }
};