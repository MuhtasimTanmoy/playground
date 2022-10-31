// class Solution {
// public:
//     bool equalFrequency(string word) {
//         unordered_set<int> freqSet;
//         vector<int> charToFreq(26, 0);
        
//         for (auto c: word) charToFreq[c - 'a']++;
//         for (auto freq: charToFreq) 
//             if (freq) 
//                 freqSet.insert(freq);
        
//         int minFreq = INT_MAX, maxFreq = INT_MIN;
//         for (auto freq: freqSet) {
//             minFreq = min(minFreq, freq);
//             maxFreq = max(maxFreq, freq);
//         }
//         return (maxFreq - minFreq) <= freqSet.size() == 1? 0: 1;
//     }
// };


class Solution {
public:
     bool equalFrequency(string word) {
        for (int i = 0; i < word.size(); i++) {
          map<char,int> mp;

          for(int j = 0; j < word.size(); j++)
              if (j != i) 
                  mp[word[j]]++;

          set<int> s;
          for(auto it:mp)
              s.insert(it.second);

          if (s.size() == 1)
              return true;

        }

        return false;
	}
};