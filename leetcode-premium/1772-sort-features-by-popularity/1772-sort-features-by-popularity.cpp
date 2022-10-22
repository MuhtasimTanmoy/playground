class Solution {
public:
    vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {
        unordered_map<string, int> popularity;
        for(const string &f : features) popularity[f] = 0;
        unordered_set<string> uniqFeats;
        for(const auto &r : responses) {
            istringstream ss(r);
            string word;
            while(ss >> word) if(uniqFeats.insert(word).second) ++popularity[word];
            uniqFeats.clear();
        }
        stable_sort(features.begin(), 
                    features.end(), 
                    [&](const string &str1, const string &str2) {
                        return popularity[str1] > popularity[str2];
                    });
        return features; 
    }
};