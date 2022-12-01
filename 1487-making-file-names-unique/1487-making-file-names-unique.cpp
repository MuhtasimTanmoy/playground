class Solution {
    unordered_map<string, int> counter;
    string getName(const string& name) {
        if (counter.count(name) == 0) {
            counter[name]++;
            return name;
        }
        
        auto lookFor = name + "(" + to_string(counter[name]) + ")";
        while (counter.count(lookFor)) 
            lookFor = name + "(" + to_string(counter[name]++) + ")";
        counter[lookFor]++;
        return lookFor;
    }
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> res;
        for (auto name: names) {
            auto formattedName = getName(name);
            res.push_back(formattedName);
        }
        return res;
    }
};