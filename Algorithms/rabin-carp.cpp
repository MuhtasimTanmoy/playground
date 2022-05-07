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