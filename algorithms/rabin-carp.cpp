#include <bits/stdc++.h>
using namespace std;
#define log(x) cout << #x << " = " << x << endl;

vector<int> rabin_karp(string const& pattern, string const& longText) {
    const int p = 31;
	
	// prime
    const int m = 1e9 + 9;
    int patternSize = pattern.size(), longTextSize = longText.size();

    vector<long long> p_pow(max(patternSize, longTextSize));
    p_pow[0] = 1;

    for (int i = 1; i < (int) p_pow.size(); i++) 
        p_pow[i] = ( p_pow[i-1] * p ) % m;

	// 1 31 961 29791 923521 28629151 887503681 512613868 891029773 621922720 
	// 279604149 667728547 699584777 687127898 300964649 329904038 227025088 37777665 
	// 171107606 304335741 434407890 466644473 465978537 445334521 805370034 966470838 
	// 960595717 778466966 132475730 106747594 309175387 584436916 117544234 
	
	// for (int i = 0; i < (int) p_pow.size(); i++)
    //     cout<<p_pow[i]<<" ";
	// cout<<endl;

    vector<long long> hashLongTextArr(longTextSize + 1, 0); 
    for (int i = 0; i < longTextSize; i++)
        hashLongTextArr[i+1] = (hashLongTextArr[i] + (longText[i] - 'a' + 1) * p_pow[i]) % m;

    long long hashPattern = 0;
    for (int i = 0; i < patternSize; i++)
        hashPattern = (hashPattern + (pattern[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurences;
    for (int i = 0; i + patternSize - 1 < longTextSize; i++) {
		// m added to handle in case minus value calculated
        long long cur_h = (hashLongTextArr[i + patternSize] + m - hashLongTextArr[i]) % m; 
        if (cur_h == hashPattern * p_pow[i] % m) occurences.push_back(i);
    }
    return occurences;
}

void execute() {
	auto ans = rabin_karp( "test", "testilovetestyoutesdasdasdtestasd");
	for (auto a: ans) cout<<a<<endl;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	freopen("input.txt", "r", stdin);
    int no_of_test_cases = 1;
	// cin >> no_of_test_cases;
    while (no_of_test_cases--) execute(); 
	return 0;
}




// Sample problem
// https://leetcode.com/problems/maximum-repeating-substring/submissions

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int q = 1e9 + 1;
        int p = 31;
        
        vector<long long> hash(max(size(sequence), size(word)));
        hash[0] = 1;
        for (int i = 1; i < size(hash); i++)
            hash[i] = ( hash[i-1] * p ) % q;
        
        // for(int i = 0; i < size(hash); i++)
        //     cout<<hash[i]<<endl;
        // cout<<endl;
        
        long long wordHash = 0;
        for(int i = 0; i < size(word); i++)
            wordHash = (wordHash + (word[i] - 'a' + 1) * hash[i]) % q;
        
        // cout<<wordHash<<endl;
        // cout<<endl;
        
        vector<long long> longHash(size(sequence) + 1, 0);
        for(int i = 0; i < size(sequence); i++)
            longHash[i + 1] = (longHash[i] + (sequence[i] - 'a' + 1) * hash[i]) % q;
        
        // for(int i = 0; i < size(longHash); i++)
        //     cout<<longHash[i]<<endl;
        // cout<<endl;
        
        int result = 0, count = 0;
        for (int i = 0; i + size(word) - 1 < size(sequence); ) {
            int currentHash = ( longHash[i + size(word)] + q - longHash[i] ) % q;
            // cout<<currentHash<<endl;
            if (currentHash == ( wordHash * hash[i]) % q ) {
                // cout<<"Found: "<<i<<endl;
                i += size(word);
                count++;
                result = max(result, count);
            } else {
                i++;
                count = 0;
            }
        }
        
        return result;
    }
};

Zolodia Inc. is a USA based game development and metaverse company rooted 
in web3 and blockchain with a targeted approach to fully develop an 
ecosystem of technologies that gives control back to the users and 
creators. These technologies ranges from gaming, social media, 
entertainment, and more. 

This is an opportunity for those who want to excel their career and want to 
work with next gen technology stacks. We have several open positions to 
join our existing team. You'll be working under the supervision of senior 
devs.

We are looking for self motivated individuals who are flexible to learn 
new technologies and love to take challenges. Freshers, mid, and senior 
level individuals are welcome to apply and requested to send their CV 
to hello@zolodia.com

We have these open positions:

1. Mobile (Flutter)
2. Front-end/Full stack (ReactJS, NodeJS, Tailwind CSS, WebAssembly)
3. Back-end/Full stack (Go, Rust, C++, NodeJS, Python 3, WebAssembly)
4. Game dev/artist/animator (Unreal Engine 5, C++, Blender)
5. Blockchain and smart contract developer(Go, Rust, Solidity) 

Mode of work : Physical office and Remote
Time: Flexible
Salary: Monthly Bdt 30k-200k ( + 2 festival bonus)
Multiple jobs: Not allowed, you've to exclusively work only for us.
Future opportunity: Relocate to our Silicon Slopes, Utah, USA office.