class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>res;
        
        unordered_map<string,int>mp;
        
        string s="";
        for(int i=0;i<s1.length();i++) {
            if(s1[i] != ' ') s += s1[i];
            else {
                mp[s]++;
                s="";
            }
        }
        mp[s]++;
        s="";
        
        for(int i=0;i<s2.length();i++) {
            if(s2[i]!=' ') s+=s2[i];
            else {
                mp[s]++;
                s="";
            }
        }  
        
        mp[s]++;
        for(auto x:mp) 
            if(x.second==1)
                res.push_back(x.first);
        return res;
    }
};