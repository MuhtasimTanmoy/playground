#include <vector>
#include<iostream>

using namespace std;

// AAACAAAAAC
vector<int> pre_kmp(string pattern) {
	// k means the pattern in this case C the lst 3 no while dont match
	int size = pattern.size();
	vector<int> suffixPrefixLen(size, 0);
	int upto = 0;
	for (int i = 1; i < size; i++) {
		while (upto > 0 && pattern[upto] != pattern[i]) upto = suffixPrefixLen[upto - 1];
		if (pattern[upto] == pattern[i]) upto++;
		suffixPrefixLen[i] = upto;
	}
	return suffixPrefixLen;
}

void kmp(string text, string pattern) {
	auto suffixPrefixLen = pre_kmp(pattern);
	int upto = 0;
	for (int i = 0; i < text.length(); i++) {
		while (upto > 0 && pattern[upto] != text[i]) upto = suffixPrefixLen[upto - 1];
		if (pattern[upto] == text[i]) upto++;
		if (upto == pattern.length()) {
			cout << "Pattern occurs with shift " << i - (pattern.length() - 1)<<"\n";
			upto = suffixPrefixLen[upto - 1];
		}
	}
}

void printKMPArr() {
	string s = "AAACAAAAAC";
	auto li = pre_kmp(s);
	int n = s.size();
	for (int i = 0; i < n; i++) cout << li[i] << " ";
}

void solve() {
	kmp("aapatternaaaabpatterncpatpatternternpatternd", "pattern");
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}
