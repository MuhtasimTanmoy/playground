https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<pair<int,int>> startPoints;
        
        int wordCount = 1;
        
        if(sentence[0] == searchWord[0]){
            startPoints.push_back({0,wordCount});
        }
        
        for(int i=1 ; i<sentence.size(); i++){
            
            if(sentence[i]==' '){
                wordCount++;
            }
            
            if(sentence[i] == searchWord[0]){
                if(sentence[i-1]==' '){
                    startPoints.push_back(make_pair(i,wordCount));
                }
            }
        }
        
        for(auto startPoint: startPoints){            
            if( sentence.substr(startPoint.first, searchWord.size()) == searchWord){
                return startPoint.second;
            }
        }
        
        return -1;
        
    }
};