class Solution {
    vector<vector<int>> solutions;

    void iteration(int current, int k, int remaining, vector<int> solution) {
        if( k < 0 ) return;
        if(remaining == 0 && k == 0) {
            solutions.push_back(solution);
            return;
        }
        for(int i = current; i <= 9; i++) {
            solution.push_back(i);
            iteration(i + 1, k - 1, remaining - i, solution);
            solution.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> singleSolution;
        iteration(1, k, n, singleSolution);
        return solutions;
    }
};