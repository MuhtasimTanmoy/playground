// class Solution {
// public:
//     int maxRepeating(string sequence, string word) {
//         int q = 1e9 + 1;
//         int p = 31;
        
//         vector<long long> hash(max(size(sequence), size(word)));
//         hash[0] = 1;
//         for ( int i = 1; i < size(hash); i++)
//             hash[i] = ( hash[i-1] * p ) % q;
        
//         // for(int i = 0; i < size(hash); i++)
//         //     cout<<hash[i]<<endl;
//         // cout<<endl;
        
//         long long wordHash = 0;
//         for(int i = 0; i < size(word); i++)
//             wordHash = (wordHash + ( word[i] - 'a' + 1) * hash[i]) % q;
        
//         // cout<<wordHash<<endl;
//         // cout<<endl;
        
//         vector<long long> longHash(size(sequence) + 1, 0);
//         for(int i = 0; i < size(sequence); i++)
//             longHash[i + 1] = (longHash[i] + (sequence[i] - 'a' + 1) * hash[i]) % q;
        
//         // for(int i = 0; i < size(longHash); i++)
//         //     cout<<longHash[i]<<endl;
//         // cout<<endl;
        
//         int result = 0;
//         int count = 0;
//         for (int i = 0; i + size(word) - 1 < size(sequence); ) {
//             int currentHash = ( longHash[i + size(word)] + q - longHash[i] ) % q;
//             // cout<<currentHash<<endl;
//             if (currentHash == ( ( wordHash * hash[i]) % q) ) {
//                 // cout<<"Found: "<<i<<endl;
//                 i += size(word);
//                 count++;
//                 result = max(result, count);
//             } else {
//                 i++;
//                 count = 0;
//             }
//         }
        
//         return result;
//     }
// };

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int cnt = 0;
        string tmp = word;
        while (sequence.find(tmp) != string::npos) {
            ++cnt;
            tmp += word;
        }
        return cnt;
    }
};