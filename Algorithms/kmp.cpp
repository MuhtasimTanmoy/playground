#include <iostream>
#include <string>

using namespace std;

// AAACAAAAAC
int *pre_kmp(string pattern) {
	// k means the pattern in this case C the lst 3 no while dont match
	int size = pattern.size();
	int *pie = new int[size];
	pie[0] = 0;
	int k = 0;
	for (int i = 1; i < size; i++) {
		while (k > 0 && pattern[k] != pattern[i]) k = pie[k - 1];
		if (pattern[k] == pattern[i]) k = k + 1;
		pie[i] = k;
	}
	return pie;
}

void kmp(string text, string pattern) {
	int *pie = pre_kmp(pattern);
	int matched_pos = 0;

	for (int current = 0; current < text.length(); current++) {
		while (matched_pos > 0 && pattern[matched_pos] != text[current])
			matched_pos = pie[matched_pos - 1];

		if (pattern[matched_pos] == text[current])
			matched_pos = matched_pos + 1;

		if (matched_pos == (pattern.length())) {
			cout << "Pattern occurs with shift " << current - (pattern.length() - 1);
			matched_pos = pie[matched_pos - 1];
		}
	}
}

void solve() {
	string s;
	cin >> s;
	int *li = pre_kmp(s);
	int n = s.size();
	for (int i = 0; i < n; i++) cout << li[i] << " ";
}

void solve2() {
	string s;
	cin >> s;
	int kmp[s.size() + 1];
	int prev = 0;
	kmp[0] = -1;
	kmp[1] = 0;
	
	for (int i = 1; i < s.size(); i++) {
		if (s[prev] == s[i]) prev++;
		else prev = 0;
		kmp[i + 1] = prev;
	}

	for (int i = 1; i <= s.size(); i++) 
		cout << kmp[i] << " ";
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 1;
	// cin >> no_of_test_cases;
	while (no_of_test_cases--) 
		solve();
		// solve2();
	return 0;
}
