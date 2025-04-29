#include "../bits/stdc++.h"
using namespace std;

int match(string&s, string& t, int len) {
	int i = 0;
	for (auto c: t) {
		if (i == s.size()) return 0;
		while (s[i] != c) {
			i++;
			if (i == s.size()) return 0;
		}
		i++;
	}

	vector<int> counter(len, 0);
	for (auto j = i; j < s.size(); j++) counter[s[j] - 'a']++;
	auto min_elem = *min_element(counter.begin(), counter.end());
	return min_elem + 1;
}

void process_input() {
	int n; cin>>n;
	int k; cin>>k;

	string s = "";
	for (auto i = 0; i < n; i++) {
		char c; cin>>c;
		s += c;
	}

	int t; cin>>t;
	for (auto i = 0; i < t; i++) {
		string now; cin>>now;
		cout<<match(s, now, k)<<endl;
	}
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("input.txt", "r", stdin);
	int r = 1; 
	while (r--) process_input();
	return 0;
}

// https://codeforces.com/contest/2104