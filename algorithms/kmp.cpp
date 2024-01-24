#include <vector>
#include<iostream>
using namespace std;

// AAACAAAAAC
vector<int> pre_kmp(string pat) {
	// k means the pattern in this case C the lst 3 no while dont match
	int size = pat.size();
	vector<int> sp(size, 0);
	for (int l = 0, r = 1; r < size; r++) {
		while (l && pat[l] != pat[r]) l = sp[l - 1];
		if (pat[l] == pat[r]) l++;
		sp[r] = l;
	}
	return sp;
}

void kmp(string text, string pattern) {
	auto sp = pre_kmp(pattern);
	for (int l = 0, i = 0; i < text.length(); i++) {
		while (l && pattern[l] != text[i]) l = sp[l - 1];
		if (pattern[l] == text[i]) l++;
		if (l == pattern.length()) {
			cout << "Pattern occurs with shift " << i - (pattern.length() - 1)<<"\n";
			l = sp[l - 1];
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



/// leetcode

string removeOccurrences(string a, string b) {
    vector<int> kmp(b.size() + 1), idx(a.size()), st;
    for (int i = 1, j = 0; i < b.size();)
        if (b[i] == b[j]) 
            kmp[++i] = ++j;
        else {
            i += j == 0;
            j = kmp[j];
        }
    int d = 0;
    for (auto i = 0, j = 0; i < a.size(); ++i) {
        a[i - d] = a[i];
        if (a[i - d] == b[j]) {
            idx[i - d] = ++j;
            if (j == b.size()) {
                d += b.size();
                j = i >= d ? idx[i - d] : 0;
            }
        }
        else {
            if (j != 0) {
                j = kmp[j];
                --i;
            }
        }
    }
    return a.substr(0, a.size() - d);
}

https://leetcode.com/problems/remove-all-occurrences-of-a-substring/discuss/1299275/True-O(n-%2B-m)-KMP