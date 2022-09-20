class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> bag;
        for(auto str: arr) bag[str]++;
        int count = 0;
        for(auto str: arr) 
            if (bag[str] == 1) {
                count++;
                if ( count == k ) return str;
            }
        return "";
    }
};